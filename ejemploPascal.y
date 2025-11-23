%{
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

extern int nLineas;
int yylex(void);
FILE *yyin;

void yyerror(const char* msg) {
    fprintf(stderr, "Error sintactico en linea %d: %s\n", nLineas, msg);
}
%}

%token  ID
%token  PROGRAM
%token  CONST
%token  VAR
%token  NUM
%token  REAL
%token  CADENA
%token  BOOL
%token  INTEGER
%token  REAL_TIPO
%token  STRING
%token  BOOLEAN
%token BEGGIN
%token ENDD
%token ASIGNACION
%token WRITELN
%token READLN
%token IF
%token ELSE
%token FOR
%token WHILE
%token DO
%token THEN
%token TO
%token DOWNTO
%token MAS
%token MENOS
%token POR
%token POTENCIA
%token DIV
%token MOD
%token AND
%token OR
%token NOT
%token MENOR
%token MAYOR
%token MENORIGUAL
%token MAYORIGUAL
%token IGUAL
%token ENTRE
%token AMPERSAND

%%

programa:
            cabecera seccionDeclaracionCtes seccionDeclaracionVars cuerpo '.'
            { printf("\nSintaxis correcta. Numero de lineas %d\n", nLineas); }
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
            ID IGUAL NUM ';'
            |
            ID IGUAL REAL ';'
            |
            ID IGUAL CADENA ';'
            |
            ID IGUAL BOOL ';'
            |
            error ';' { yyerrok; }
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
            ID ':' tipo ';' { printf("\nDeclaracion de variable"); }
            |
            error ';' { yyerrok; }
            ;

tipo:
            INTEGER
            |
            REAL_TIPO
            |
            STRING
            |
            BOOLEAN
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
            error ';' { yyerrok; }
            ;

visualizacion:
            WRITELN '(' parametro_write ')'
            { printf("\nInstruccion: Writeln"); }
            ;

parametro_write:
            CADENA
            |
            ID
            ;
            
asignacion:
            ID ASIGNACION expresion { printf("\nInstruccion: Asignacion"); }
            ;

lectura:
            READLN '(' ID ')' { printf("\nInstruccion: Readln"); }
            |
            READLN '(' AMPERSAND ID ')' { printf("\nInstruccion: Readln &"); }
            ;

expresion:
            expr_aritmetica
            |
            expr_booleana
            ;

expr_aritmetica:
            termino
            |
            expr_aritmetica MAS termino
            |
            expr_aritmetica MENOS termino
            |
            MENOS termino
            ;

termino:
            factor
            |
            termino POR factor
            |
            termino '/' factor
            |
            termino DIV factor
            |
            termino MOD factor
            |
            termino POTENCIA factor
            ;
            
factor:
            ID
            |
            NUM
            |
            REAL
            |
            CADENA
            |
            '(' expr_aritmetica ')'
            ;
            
expr_booleana:
            expr_bool_simple
            |
            expr_booleana AND expr_bool_simple
            |
            expr_booleana OR expr_bool_simple
            ;

expr_bool_simple:
            expr_aritmetica comparador expr_aritmetica
            |
            BOOL
            |
            expr_aritmetica
            |
            '(' expr_booleana ')'
            |
            NOT expr_bool_simple
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
            |
            FOR '(' ID ASIGNACION expr_aritmetica DOWNTO expr_aritmetica ')' BEGGIN instrucciones ENDD
            ;


comparador:
            MENOR
            |
            MAYOR
            |
            MENORIGUAL
            |
            MAYORIGUAL
            |
            IGUAL
            |
            ENTRE
            ;

%%

int main()
{
    yyin=fopen("pruebaErrores.pas","r");
    if(!yyin){
        printf("\nError de apertura!");
        return -1;
    }
    yyparse();
    return 0;
}
