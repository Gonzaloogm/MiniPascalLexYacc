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
                  ID '=' NUM ';'    {printf("\nDeclaracion cte entero");}
                  | ID '=' REAL ';'   {printf("\nDeclaracion cte real");}
                  | ID '=' CADENA ';' {printf("\nDeclaracion cte cadena");}
                  | ID '=' BOOL ';'   {printf("\nDeclaracion cte bool");}
                  ;
seccionDeclaracionVars: /*vacia*/
                  | VAR declaracionVars
                  ;
declaracionVars:  declaracionVar
                  | declaracionVar declaracionVars
                  ;
declaracionVar:
                  listaIDs ':' tipo ';' {printf("\nDeclaracion de variable");}
                  ;
listaIDs:
                  ID
                  | ID ',' listaIDs
                  ;
tipo:
                  INTEGER   {printf("\nTipo entero");}
                  | REAL_TIPO      {printf("\nTipo real");}
                  | STRING    {printf("\nTipo cadena");}
                  | BOOLEAN   {printf("\nTipo booleano");}
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
