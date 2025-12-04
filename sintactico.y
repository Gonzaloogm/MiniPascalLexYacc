%{
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int nLineas = 1;

void yyerror(const char* msg);
int yylex(void);
FILE *yyin;

struct simbolo {
    char nombre[100];
    int tipo;
    int esConstante;
    int inicializado;
};

struct simbolo tablaSimbolos[200];
int dim = 0;
int nErrores = 0;

char colaVars[20][100];
int numVarsCola = 0;

int buscarSimbolo(char* nombre);
void addTablaSimbolos(char* nombre, int tipo, int esConstante, int inicializado);

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
%token ASIGNACION WRITELN READLN IF ELSE FOR WHILE DO TO DOWNTO
%token MAS MENOS POR POTENCIA DIV MOD AND OR NOT
%token MENOR MAYOR MENORIGUAL MAYORIGUAL IGUAL ENTRE AMPERSAND

%nonassoc THEN
%nonassoc ELSE

%%

programa: cabecera seccionDeclaracionCtes seccionDeclaracionVars cuerpo '.'
          {
              if(nErrores == 0) {
                  printf("\nSe detectaron 0 errores.\n");
              } else {
                  printf("\nSe detectaron %d errores.\n", nErrores);
              }
          }
        ;

cabecera: PROGRAM ID ';' ;

seccionDeclaracionCtes: /* vacio */ | CONST declaracionCtes ;
declaracionCtes: declaracionCte | declaracionCte declaracionCtes ;

declaracionCte:
      ID IGUAL NUM ';'      { addTablaSimbolos($1, 1, 1, 1); }
    | ID IGUAL REAL ';'     { addTablaSimbolos($1, 2, 1, 1); }
    | ID IGUAL CADENA ';'   { addTablaSimbolos($1, 3, 1, 1); }
    | ID IGUAL BOOL ';'     { addTablaSimbolos($1, 4, 1, 1); }
    | error ';' { yyerrok; }
    ;

seccionDeclaracionVars: /* vacio */ | VAR declaracionVars ;
declaracionVars: declaracionVar | declaracionVar declaracionVars ;

declaracionVar:
    lista_ids ':' tipo ';'
    {
        for(int i=0; i<numVarsCola; i++) {
            addTablaSimbolos(colaVars[i], $3, 0, 0);
        }
        numVarsCola = 0;
    }
    | error ';' { yyerrok; }
    ;

lista_ids:
      ID { strcpy(colaVars[numVarsCola], $1); numVarsCola++; }
    | lista_ids ',' ID { strcpy(colaVars[numVarsCola], $3); numVarsCola++; }
    ;

tipo:
      INTEGER   { $$ = 1; }
    | REAL_TIPO { $$ = 2; }
    | STRING    { $$ = 3; }
    | BOOLEAN   { $$ = 4; }
    ;

cuerpo: BEGGIN instrucciones ENDD ;

instrucciones: /* vacio */ | lista_instrucciones ;
lista_instrucciones: instruccion | lista_instrucciones instruccion ;

instruccion:
      asignacion ';'
    | visualizacion ';'
    | lectura ';'
    | if | while | for
    | ';'
    | error ';' { yyerrok; }
    ;

visualizacion:
    WRITELN '(' parametro_write ')'
    ;

parametro_write:
      CADENA { $$ = 3; }
    | ID {
        int idx = buscarSimbolo($1);
        if(idx == -1) {
             printf("LINEA %d. ERROR SEMÁNTICO: Variable %s no declarada\n", nLineas, $1);
             nErrores++;
             $$ = 0;
        } else {
             if(tablaSimbolos[idx].inicializado == 0) {
                 printf("LINEA %d. ERROR SEMÁNTICO: Variable %s sin inicializar\n", nLineas, $1);
                 nErrores++;
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
            printf("LINEA %d. ERROR SEMÁNTICO: Variable %s no declarada\n", nLineas, $1);
            nErrores++;
        } else {
            if(tablaSimbolos[idx].esConstante) {
                printf("LINEA %d. ERROR SEMÁNTICO: Intentando modificar la constante %s\n", nLineas, $1);
                nErrores++;
            } else {
                if (tablaSimbolos[idx].tipo == 1 && $3 == 2) {
                    printf("LINEA %d. ERROR SEMÁNTICO: Tipos incompatibles\n", nLineas);
                    nErrores++;
                }
                else if (tablaSimbolos[idx].tipo == 3 && $3 != 3) {
                    printf("LINEA %d. ERROR SEMÁNTICO: Tipos incompatibles\n", nLineas);
                    nErrores++;
                }
                
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
             printf("LINEA %d. ERROR SEMÁNTICO: Variable %s no declarada\n", nLineas, $3);
             nErrores++;
         } else if(tablaSimbolos[idx].esConstante) {
             printf("LINEA %d. ERROR SEMÁNTICO: Intentando leer sobre una constante\n", nLineas);
             nErrores++;
         } else {
             tablaSimbolos[idx].inicializado = 1;
         }
    }
    ;

expresion: expr_aritmetica { $$ = $1; } | expr_booleana { $$ = $1; } ;

expr_aritmetica:
      termino { $$ = $1; }
    | expr_aritmetica MAS termino {
        if ($1 == 2 || $3 == 2) $$ = 2; else $$ = 1;
    }
    | expr_aritmetica MENOS termino {
        if ($1 == 2 || $3 == 2) $$ = 2; else $$ = 1;
    }
    | MENOS termino { $$ = $2; }
    ;

termino:
      factor { $$ = $1; }
    | termino POR factor {
        if ($1 == 2 || $3 == 2) $$ = 2; else $$ = 1;
    }
    | termino DIV factor { $$ = 1; }
    | termino MOD factor { $$ = 1; }
    | termino POTENCIA factor { $$ = 1; }
    ;

factor:
      ID {
        int idx = buscarSimbolo($1);
        if(idx == -1) {
            printf("LINEA %d. ERROR SEMÁNTICO: Variable %s no declarada\n", nLineas, $1);
            nErrores++;
            $$ = 1;
        } else {
            if(tablaSimbolos[idx].inicializado == 0) {
                 printf("LINEA %d. ERROR SEMÁNTICO: Variable %s sin inicializar\n", nLineas, $1);
                 nErrores++;
            }
            $$ = tablaSimbolos[idx].tipo;
        }
    }
    | NUM     { $$ = 1; }
    | REAL    { $$ = 2; }
    | CADENA  { $$ = 3; }
    | '(' expr_aritmetica ')' { $$ = $2; }
    ;

expr_booleana: expr_bool_simple | expr_booleana AND expr_bool_simple | expr_booleana OR expr_bool_simple ;

expr_bool_simple:
      expr_aritmetica comparador expr_aritmetica { $$ = 4; }
    | BOOL { $$ = 4; }
    | '(' expr_booleana ')' { $$ = $2; }
    | NOT expr_bool_simple { $$ = 4; }
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

void yyerror(const char* msg) {
    /* fprintf(stderr, "LINEA %d. Error sintactico: %s\n", nLineas, msg); */
}

int main() {
    yyin = fopen("pascalSem.pas","r");
    if(!yyin){ printf("\nError abriendo pascalSem.pas\n"); return -1; }
    yyparse();
    return 0;
}

int buscarSimbolo(char* nombre) {
    for(int i = 0; i < dim; i++) {
        if(strcmp(tablaSimbolos[i].nombre, nombre) == 0) return i;
    }
    return -1;
}

void addTablaSimbolos(char* nombre, int tipo, int esConstante, int inicializado) {
    if(buscarSimbolo(nombre) != -1) {
        printf("LINEA %d. ERROR SEMÁNTICO: Identificador '%s' ya declarado\n", nLineas, nombre);
        nErrores++;
    } else {
        strcpy(tablaSimbolos[dim].nombre, nombre);
        tablaSimbolos[dim].tipo = tipo;
        tablaSimbolos[dim].esConstante = esConstante;
        tablaSimbolos[dim].inicializado = inicializado;
        dim++;
    }
}
