%{
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int nLineas = 1;

int yylex(void);
FILE *yyin;
int erroresSemanticos = 0;

/* Definición de constantes para tipos */
#define T_INTEGER 1
#define T_REAL    2
#define T_STRING  3
#define T_BOOLEAN 4

struct simbolo {
    char nombre[100];
    int tipo;
    int esConstante;  /* 1 si es const, 0 si es var */
    int inicializado; /* 1 si tiene valor, 0 si no */
};

struct simbolo tablaSimbolos[200];
int numSimbolos = 0;

/* Cola auxiliar para declaraciones múltiples (a,b:integer) */
char colaVars[20][100];
int numVarsCola = 0;

void yyerror(const char* msg) {
    /* No imprimimos errores sintácticos si queremos solo la salida semántica limpia,
       pero para depurar es útil. El enunciado pide informar errores. */
    /* fprintf(stderr, "LINEA %d. Error sintactico: %s\n", nLineas, msg); */
}

void errorSemantico(const char* msg) {
    printf("LINEA %d. ERROR SEMÁNTICO: %s\n", nLineas, msg);
    erroresSemanticos++;
}

int buscarSimbolo(char* nombre) {
    for(int i = 0; i < numSimbolos; i++) {
        if(strcmp(tablaSimbolos[i].nombre, nombre) == 0) return i;
    }
    return -1;
}

void insertarSimbolo(char* nombre, int tipo, int esConstante, int inicializado) {
    if(buscarSimbolo(nombre) != -1) {
        char buffer[200];
        sprintf(buffer, "Identificador '%s' ya declarado", nombre);
        errorSemantico(buffer);
    } else {
        strcpy(tablaSimbolos[numSimbolos].nombre, nombre);
        tablaSimbolos[numSimbolos].tipo = tipo;
        tablaSimbolos[numSimbolos].esConstante = esConstante;
        tablaSimbolos[numSimbolos].inicializado = inicializado;
        numSimbolos++;
    }
}

%}

%union {
    char nombreId[100];
    int tipo;
}

%token <nombreId> ID
%token <tipo> NUM REAL CADENA BOOL
%token <tipo> INTEGER REAL_TIPO STRING BOOLEAN

%type <tipo> tipo expresion expr_aritmetica termino factor expr_booleana expr_bool_simple parametro_write

%token PROGRAM CONST VAR BEGGIN ENDD
%token ASIGNACION WRITELN READLN IF ELSE FOR WHILE DO THEN TO DOWNTO
%token MAS MENOS POR POTENCIA DIV MOD AND OR NOT
%token MENOR MAYOR MENORIGUAL MAYORIGUAL IGUAL ENTRE AMPERSAND

/* Precedencia para evitar conflictos if-else */
%nonassoc THEN
%nonassoc ELSE

%%

programa: cabecera seccionDeclaracionCtes seccionDeclaracionVars cuerpo '.'
          {
              if(erroresSemanticos == 0)
                  printf("\nSe detectaron 0 errores.\n");
              else
                  printf("\nSe detectaron %d errores.\n", erroresSemanticos);
          }
        ;

cabecera: PROGRAM ID ';' ;

seccionDeclaracionCtes: /* vacio */ | CONST declaracionCtes ;
declaracionCtes: declaracionCte | declaracionCte declaracionCtes ;

declaracionCte:
    ID IGUAL NUM ';'      { insertarSimbolo($1, T_INTEGER, 1, 1); }
    | ID IGUAL REAL ';'   { insertarSimbolo($1, T_REAL, 1, 1); }
    | ID IGUAL CADENA ';' { insertarSimbolo($1, T_STRING, 1, 1); }
    | ID IGUAL BOOL ';'   { insertarSimbolo($1, T_BOOLEAN, 1, 1); }
    | error ';' { yyerrok; }
    ;

seccionDeclaracionVars: /* vacio */ | VAR declaracionVars ;
declaracionVars: declaracionVar | declaracionVar declaracionVars ;

declaracionVar:
    lista_ids ':' tipo ';'
    {
        /* Procesamos la cola de variables pendientes */
        for(int i=0; i<numVarsCola; i++) {
            insertarSimbolo(colaVars[i], $3, 0, 0);
        }
        numVarsCola = 0;
    }
    | error ';' { yyerrok; }
    ;

lista_ids:
    ID {
        strcpy(colaVars[numVarsCola], $1);
        numVarsCola++;
    }
    | lista_ids ',' ID {
        strcpy(colaVars[numVarsCola], $3);
        numVarsCola++;
    }
    ;

tipo:
    INTEGER   { $$ = T_INTEGER; }
    | REAL_TIPO { $$ = T_REAL; }
    | STRING    { $$ = T_STRING; }
    | BOOLEAN   { $$ = T_BOOLEAN; }
    ;

cuerpo: BEGGIN instrucciones ENDD ;

instrucciones: /* vacio */ | lista_instrucciones ;
lista_instrucciones: instruccion | lista_instrucciones instruccion ;

instruccion:
    asignacion ';'
    | visualizacion
    | lectura ';'
    | if | while | for
    | ';'
    | error ';' { yyerrok; }
    ;

visualizacion:
    WRITELN '(' parametro_write ')' ';'
    ;

parametro_write:
    CADENA { $$ = T_STRING; }
    | ID {
        int idx = buscarSimbolo($1);
        if(idx == -1) {
             char buf[100]; sprintf(buf, "Variable %s no declarada", $1);
             errorSemantico(buf);
             $$ = 0; // Tipo error
        } else {
             if(tablaSimbolos[idx].inicializado == 0) {
                 char buf[100]; sprintf(buf, "Variable %s sin inicializar", $1);
                 errorSemantico(buf);
             }
             $$ = tablaSimbolos[idx].tipo;
        }
    }
    | parametro_write ',' parametro_write
    ;
            
asignacion:
    ID ASIGNACION expresion
    {
        int idx = buscarSimbolo($1);
        if(idx == -1) {
            char buf[100]; sprintf(buf, "Variable %s no declarada", $1);
            errorSemantico(buf);
        } else {
            /* Chequeo: Modificar constante */
            if(tablaSimbolos[idx].esConstante) {
                char buf[100]; sprintf(buf, "Intentando modificar la constante %s", $1);
                errorSemantico(buf);
            } else {
                /* Chequeo: Tipos incompatibles (Regla estricta) */
                /* Si asigno algo que NO es entero a un entero */
                if (tablaSimbolos[idx].tipo == T_INTEGER && $3 != T_INTEGER) {
                    errorSemantico("Tipos incompatibles");
                }
                /* Si asigno algo que NO es string a un string */
                else if (tablaSimbolos[idx].tipo == T_STRING && $3 != T_STRING) {
                    errorSemantico("Tipos incompatibles");
                }
                
                /* Si todo OK, se marca como inicializada */
                tablaSimbolos[idx].inicializado = 1;
            }
        }
    }
    ;

lectura:
    READLN '(' ID ')'
    {
         int idx = buscarSimbolo($3);
         if(idx == -1) {
             char buf[100]; sprintf(buf, "Variable %s no declarada", $3);
             errorSemantico(buf);
         } else if(tablaSimbolos[idx].esConstante) {
             errorSemantico("Intentando leer sobre una constante");
         } else {
             /* Al leer, la variable toma valor -> inicializada */
             tablaSimbolos[idx].inicializado = 1;
         }
    }
    ;

expresion: expr_aritmetica { $$ = $1; } | expr_booleana { $$ = $1; } ;

expr_aritmetica:
    termino { $$ = $1; }
    | expr_aritmetica MAS termino {
        /* Si alguno es real, resultado real. Si no, entero */
        if ($1 == T_REAL || $3 == T_REAL) $$ = T_REAL; else $$ = T_INTEGER;
    }
    | expr_aritmetica MENOS termino {
        if ($1 == T_REAL || $3 == T_REAL) $$ = T_REAL; else $$ = T_INTEGER;
    }
    | MENOS termino { $$ = $2; }
    ;

termino:
    factor { $$ = $1; }
    | termino POR factor {
        if ($1 == T_REAL || $3 == T_REAL) $$ = T_REAL; else $$ = T_INTEGER;
    }
    | termino DIV factor { $$ = T_INTEGER; }
    | termino MOD factor { $$ = T_INTEGER; }
    | termino POTENCIA factor { $$ = T_INTEGER; }
    ;

factor:
    ID {
        int idx = buscarSimbolo($1);
        if(idx == -1) {
            char buf[100]; sprintf(buf, "Variable %s no declarada", $1);
            errorSemantico(buf);
            $$ = T_INTEGER; // Tipo dummy para continuar
        } else {
            /* Chequeo: Variable sin inicializar usada en expresion */
            if(tablaSimbolos[idx].inicializado == 0) {
                 char buf[100]; sprintf(buf, "Variable %s sin inicializar", $1);
                 errorSemantico(buf);
            }
            $$ = tablaSimbolos[idx].tipo;
        }
    }
    | NUM     { $$ = T_INTEGER; }
    | REAL    { $$ = T_REAL; }
    | CADENA  { $$ = T_STRING; }
    | '(' expr_aritmetica ')' { $$ = $2; }
    ;

expr_booleana: expr_bool_simple | expr_booleana AND expr_bool_simple | expr_booleana OR expr_bool_simple ;

expr_bool_simple:
    expr_aritmetica comparador expr_aritmetica { $$ = T_BOOLEAN; }
    | BOOL { $$ = T_BOOLEAN; }
    | '(' expr_booleana ')' { $$ = $2; }
    | NOT expr_bool_simple { $$ = T_BOOLEAN; }
    ;

if:
    IF expr_booleana THEN instrucciones ';'
    | IF expr_booleana THEN BEGGIN instrucciones ENDD ';'
    | IF expr_booleana THEN BEGGIN instrucciones ENDD ELSE BEGGIN instrucciones ENDD ';'
    ;

while: WHILE expr_booleana DO BEGGIN instrucciones ENDD ';' ;

for:
    FOR ID ASIGNACION expr_aritmetica TO expr_aritmetica DO BEGGIN instrucciones ENDD ';'
    | FOR ID ASIGNACION expr_aritmetica DOWNTO expr_aritmetica DO BEGGIN instrucciones ENDD ';'
    ;

comparador: MENOR | MAYOR | MENORIGUAL | MAYORIGUAL | IGUAL | ENTRE ;

%%

int main()
{
    yyin = fopen("pascal2.pas","r");
    if(!yyin){
        printf("\nError abriendo ejemplo.pas\n");
        return -1;
    }
    yyparse();
    return 0;
}
