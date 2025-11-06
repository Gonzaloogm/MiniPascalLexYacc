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

/* ====== TOKENS ====== */
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
                  cabecera seccionDeclaracionCtes seccionDeclaracionVars
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
seccionDeclaracionVars: /* vacío */
                  | VAR declaracionVar
                  ;

declaracionVar:
                  ID ':' tipo ';' { printf("\nDeclaracion de variable"); }
                  | ID ':' tipo ';' declaracionVar
                  ;

tipo:
                  INTEGER   { printf("\nTipo entero"); }
                  | REAL_TIPO      { printf("\nTipo real"); }
                  | STRING    { printf("\nTipo cadena"); }
                  | BOOLEAN   { printf("\nTipo booleano"); }
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
