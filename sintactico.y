%{
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

extern int nLineas;
int yylex(void);
FILE *yyin;
int erroresSemanticos = 0;

#define T_INTEGER 1
#define T_REAL    2
#define T_STRING  3
#define T_BOOLEAN 4

struct simbolo {
    char nombre[100];
    int tipo;
    int esConstante;
    int inicializado;
};

struct simbolo tablaSimbolos[200];
int numSimbolos = 0;

void yyerror(const char* msg) {
    fprintf(stderr, "Error sintactico en linea %d: %s\n", nLineas, msg);
}

void errorSemantico(const char* msg) {
    fprintf(stderr, "Error semantico en linea %d: %s\n", nLineas, msg);
    erroresSemanticos++;
}

int buscarSimbolo(char* nombre) {
    for(int i = 0; i < numSimbolos; i++) {
        if(strcmp(tablaSimbolos[i].nombre, nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void insertarSimbolo(char* nombre, int tipo, int esConstante, int inicializado) {
    if(buscarSimbolo(nombre) != -1) {
        char buffer[200];
        sprintf(buffer, "Identificador '%s' ya declarado previamente", nombre);
        errorSemantico(buffer);
    } else {
        strcpy(tablaSimbolos[numSimbolos].nombre, nombre);
        tablaSimbolos[numSimbolos].tipo = tipo;
        tablaSimbolos[numSimbolos].esConstante = esConstante;
        tablaSimbolos[numSimbolos].inicializado = inicializado;
        numSimbolos++;
    }
}

void comprobarTipos(int tipo1, int tipo2) {
    if(tipo1 != tipo2) {
        errorSemantico("Tipos incompatibles en la operacion o asignacion");
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

%token PROGRAM CONST VAR
%token BEGGIN ENDD
%token ASIGNACION WRITELN READLN
%token IF ELSE FOR WHILE DO THEN TO DOWNTO
%token MAS MENOS POR POTENCIA DIV MOD
%token AND OR NOT
%token MENOR MAYOR MENORIGUAL MAYORIGUAL IGUAL ENTRE
%token AMPERSAND

%%

programa:
            cabecera seccionDeclaracionCtes seccionDeclaracionVars cuerpo '.'
            {
                if(erroresSemanticos == 0)
                    printf("\n--- COMPILACION EXITOSA: Sin errores sintacticos ni semanticos. Lineas: %d ---\n", nLineas);
                else
                    printf("\n--- FALLO: Se encontraron %d errores semanticos. ---\n", erroresSemanticos);
            }
            ;

cabecera:
            PROGRAM ID ';'
            ;

seccionDeclaracionCtes:
            |
            CONST declaracionCtes
            ;

declaracionCtes:
            declaracionCte
            |
            declaracionCte declaracionCtes
            ;

declaracionCte:
            ID IGUAL NUM ';'      { insertarSimbolo($1, T_INTEGER, 1, 1); }
            |
            ID IGUAL REAL ';'     { insertarSimbolo($1, T_REAL, 1, 1); }
            |
            ID IGUAL CADENA ';'   { insertarSimbolo($1, T_STRING, 1, 1); }
            |
            ID IGUAL BOOL ';'     { insertarSimbolo($1, T_BOOLEAN, 1, 1); }
            |
            error ';' { yyerrok; yyclearin; }
            ;

seccionDeclaracionVars:
            |
            VAR declaracionVars
            ;

declaracionVars:
            declaracionVar
            |
            declaracionVar declaracionVars
            ;

declaracionVar:
            ID ':' tipo ';'
            {
                insertarSimbolo($1, $3, 0, 0);
            }
            |
            error ';' { yyerrok; yyclearin; }
            ;

tipo:
            INTEGER     { $$ = T_INTEGER; }
            |
            REAL_TIPO   { $$ = T_REAL; }
            |
            STRING      { $$ = T_STRING; }
            |
            BOOLEAN     { $$ = T_BOOLEAN; }
            ;

cuerpo:
            BEGGIN instrucciones ENDD
            ;
            
instrucciones:
            |
            lista_instrucciones
            ;

lista_instrucciones:
            instruccion
            |
            lista_instrucciones instruccion
            ;

instruccion:
            asignacion ';'
            |
            visualizacion
            |
            lectura ';'
            |
            if
            |
            while
            |
            for
            |
            ';'
            |
            error ';' { yyerrok; yyclearin; }
            ;

visualizacion:
            WRITELN '(' parametro_write ')' ';'
            { }
            ;

parametro_write:
            CADENA { $$ = T_STRING; }
            |
            ID
            {
                int idx = buscarSimbolo($1);
                if(idx == -1) {
                    char buf[100]; sprintf(buf, "Variable '%s' no declarada", $1);
                    errorSemantico(buf);
                    $$ = 0;
                } else {
                    if(tablaSimbolos[idx].inicializado == 0) {
                        char buf[100]; sprintf(buf, "Variable '%s' usada sin inicializar", $1);
                        errorSemantico(buf);
                    }
                    $$ = tablaSimbolos[idx].tipo;
                }
            }
            ;
            
asignacion:
            ID ASIGNACION expresion
            {
                int idx = buscarSimbolo($1);
                if(idx == -1) {
                    char buf[100]; sprintf(buf, "Variable '%s' no declarada", $1);
                    errorSemantico(buf);
                } else {
                    if(tablaSimbolos[idx].esConstante) {
                        char buf[100]; sprintf(buf, "No se puede modificar la constante '%s'", $1);
                        errorSemantico(buf);
                    } else {
                        comprobarTipos(tablaSimbolos[idx].tipo, $3);
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
                    errorSemantico("Variable no declarada en readln");
                 } else if(tablaSimbolos[idx].esConstante) {
                    errorSemantico("No se puede leer/modificar una constante");
                 } else {
                    tablaSimbolos[idx].inicializado = 1;
                 }
            }
            |
            READLN '(' AMPERSAND ID ')'
            {
                 int idx = buscarSimbolo($4);
                 if(idx == -1) errorSemantico("Variable no declarada en readln");
                 else { tablaSimbolos[idx].inicializado = 1; }
            }
            ;

expresion:
            expr_aritmetica { $$ = $1; }
            |
            expr_booleana   { $$ = $1; }
            ;

expr_aritmetica:
            termino { $$ = $1; }
            |
            expr_aritmetica MAS termino { comprobarTipos($1, $3); $$ = $1; }
            |
            expr_aritmetica MENOS termino { comprobarTipos($1, $3); $$ = $1; }
            |
            MENOS termino { $$ = $2; }
            ;

termino:
            factor { $$ = $1; }
            |
            termino POR factor { comprobarTipos($1, $3); $$ = $1; }
            |
            termino DIV factor { comprobarTipos($1, $3); $$ = $1; }
            |
            termino MOD factor
            {
                if($1 != T_INTEGER || $3 != T_INTEGER) errorSemantico("MOD requiere enteros");
                $$ = T_INTEGER;
            }
            |
            termino POTENCIA factor { comprobarTipos($1, $3); $$ = $1; }
            ;
            
factor:
            ID
            {
                int idx = buscarSimbolo($1);
                if(idx == -1) {
                    char buf[100]; sprintf(buf, "Variable '%s' no declarada", $1);
                    errorSemantico(buf);
                    $$ = T_INTEGER;
                } else {
                    if(tablaSimbolos[idx].inicializado == 0) {
                        char buf[100]; sprintf(buf, "Variable '%s' usada sin inicializar", $1);
                        errorSemantico(buf);
                    }
                    $$ = tablaSimbolos[idx].tipo;
                }
            }
            |
            NUM     { $$ = T_INTEGER; }
            |
            REAL    { $$ = T_REAL; }
            |
            CADENA  { $$ = T_STRING; }
            |
            '(' expr_aritmetica ')' { $$ = $2; }
            ;
            
expr_booleana:
            expr_bool_simple { $$ = $1; }
            |
            expr_booleana AND expr_bool_simple { $$ = T_BOOLEAN; }
            |
            expr_booleana OR expr_bool_simple  { $$ = T_BOOLEAN; }
            ;

expr_bool_simple:
            expr_aritmetica comparador expr_aritmetica
            {
                if($1 != $3) errorSemantico("Comparacion de tipos incompatibles");
                $$ = T_BOOLEAN;
            }
            |
            BOOL { $$ = T_BOOLEAN; }
            |
            '(' expr_booleana ')' { $$ = $2; }
            |
            NOT expr_bool_simple { $$ = T_BOOLEAN; }
            ;
            
if:
            IF '(' expr_booleana ')' BEGGIN instrucciones ENDD
            |
            IF '(' expr_booleana ')' BEGGIN instrucciones ENDD ELSE BEGGIN instrucciones ENDD
            ;

while:
            WHILE '(' expr_booleana ')' BEGGIN instrucciones ENDD
            ;

for:
            FOR '(' ID ASIGNACION expr_aritmetica TO expr_aritmetica ')' BEGGIN instrucciones ENDD
            {
                int idx = buscarSimbolo($3);
                if(idx == -1) {
                    errorSemantico("Variable del bucle FOR no declarada");
                } else {
                    if(tablaSimbolos[idx].tipo != T_INTEGER) {
                        errorSemantico("La variable del bucle FOR debe ser INTEGER");
                    }
                
                    tablaSimbolos[idx].inicializado = 1;
                    
                    if($5 != T_INTEGER || $7 != T_INTEGER) {
                        errorSemantico("Los limites del bucle FOR deben ser enteros");
                    }
                }
            }
            |
            FOR '(' ID ASIGNACION expr_aritmetica DOWNTO expr_aritmetica ')' BEGGIN instrucciones ENDD
            {
                int idx = buscarSimbolo($3);
                if(idx != -1 && tablaSimbolos[idx].tipo != T_INTEGER)
                     errorSemantico("Variable FOR debe ser entera");
            }
            ;


comparador:
            MENOR | MAYOR | MENORIGUAL | MAYORIGUAL | IGUAL | ENTRE
            ;

%%

int main()
{
    yyin = fopen("pruebaErrores.pas","r");
    if(!yyin){
        printf("\nError de apertura de pruebaErrores.pas\n");
        return -1;
    }
    yyparse();
    return 0;
}
