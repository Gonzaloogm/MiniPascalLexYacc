%{
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
int yylex(void);
FILE *yyin;
extern int nLineas;
%}

/* ====== TOKENS (Corregido AMPERSANT) ====== */
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
            { printf("\n Sintaxis correcta. Numero de lineas %d\n", nLineas); }
            ;

cabecera: PROGRAM ID ';'{printf("\n Reconozco la cabecera");}
            ;

seccionDeclaracionCtes: /*vacia*/
            | CONST declaracionCtes 
            ;

declaracionCtes: declaracionCte 
            | declaracionCte declaracionCtes
            ; 

declaracionCte:
            ID IGUAL NUM ';'    {printf("\nDeclaracion cte entero");}
            | ID IGUAL REAL ';'   {printf("\nDeclaracion cte real");}
            | ID IGUAL CADENA ';' {printf("\nDeclaracion cte cadena");}
            | ID IGUAL BOOL ';'   {printf("\nDeclaracion cte bool");}
            ;

seccionDeclaracionVars: /*vacia*/
            | VAR declaracionVars
            ;

/* Esta es la regla BUENA (la que quiere tu profesora) */
declaracionVars:  declaracionVar
            | declaracionVar declaracionVars
            ;

declaracionVar:
            ID ':' tipo ';' {printf("\nDeclaracion de variable");}
            ;
            


tipo:
            INTEGER   {printf("\nTipo entero");}
            | REAL_TIPO      {printf("\nTipo real");}
            | STRING    {printf("\nTipo cadena");}
            | BOOLEAN   {printf("\nTipo booleano");}
            ;
            
cuerpo:
            BEGGIN instrucciones ENDD
            ;
            
instrucciones:
             /*vacia*/
            |
            instruccion_lista
            ;

instruccion_lista:
            instruccion
            |
            instruccion_lista instruccion 
            ;
            
instruccion:
            asignacion
            |
            visualizacion
            |
            lectura
           
            ;
            
puntoycoma_opcional:
            /* vacia */
            |
            ';'
            ;
            
visualizacion:
            WRITELN '(' CADENA ')' puntoycoma_opcional
            { printf("\nInstruccion: Writeln (cadena)"); }
            |
            WRITELN '(' ID ')' puntoycoma_opcional
            { printf("\nInstruccion: Writeln (id)"); }
            ;           
            
asignacion:
            ID ASIGNACION expresion ';'
            { printf("\nInstruccion: Asignacion"); }
            ;


lectura:
            READLN '(' ID ')' ';'
            { printf("\nInstruccion: Readln (id)"); }
            |
            READLN '(' AMPERSAND ID ')' ';'
            { printf("\nInstruccion: Readln (con &)"); }
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
            ;

termino:
            factor
            |
            termino POR factor
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
            |
            NOT expr_bool_simple
            ;

expr_bool_simple:
            expr_aritmetica comparador expr_aritmetica 
            |
            BOOL
            |
            ID
            |
            '(' expr_booleana ')'
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
    yyin=fopen("minipascal.pas","r");
    if(!yyin){
        printf("\n Error de apertura!");
        return -1;
    }
    yyparse();
}