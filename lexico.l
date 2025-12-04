%{
#include "y.tab.h"
#include <string.h>

extern int nLineas;
%}

/* Opciones para que no de error si no usamos input/yyunput */
%option noinput nounput

entero  [0-9]+
real    {entero}"."{entero}
iden    [a-zA-Z][a-zA-Z0-9]*
cadena  (\"[^\"]*\"|\'[^\']*\')
bool    (true|false)

%%

{real}      { yylval.tipo = 2; return REAL; } /* 2 = T_REAL */
{entero}    { yylval.tipo = 1; return NUM; }  /* 1 = T_INTEGER */
{cadena}    { yylval.tipo = 3; return CADENA; } /* 3 = T_STRING */
{bool}      { yylval.tipo = 4; return BOOL; }   /* 4 = T_BOOLEAN */

const       { return CONST; }
program     { return PROGRAM; }
var         { return VAR; }

integer     { yylval.tipo = 1; return INTEGER; }
real        { yylval.tipo = 2; return REAL_TIPO; }
string      { yylval.tipo = 3; return STRING; }
boolean     { yylval.tipo = 4; return BOOLEAN; }

begin       { return BEGGIN; }
end         { return ENDD; }

":="        { return ASIGNACION; }

writeln     { return WRITELN; }
readln      { return READLN; }

if          { return IF; }
else        { return ELSE; }
while       { return WHILE; }
do          { return DO; }
for         { return FOR; }

then        { return THEN; }
to          { return TO; }
downto      { return DOWNTO; }

","         { return ','; }
";"         { return ';'; }
":"         { return ':'; }
"("         { return '('; }
")"         { return ')'; }
"."         { return '.'; }

div         { return DIV; }
mod         { return MOD; }
and         { return AND; }
or          { return OR; }
not         { return NOT; }

"+"         { return MAS; }
"-"         { return MENOS; }
"*"         { return POR; }
"**"        { return POTENCIA; }

"<"         { return MENOR; }
">"         { return MAYOR; }
"<="        { return MENORIGUAL; }
">="        { return MAYORIGUAL; }
"="         { return IGUAL; }
"<>"        { return ENTRE; }

"&"         { return AMPERSAND; }

{iden}      {
              strcpy(yylval.nombreId, yytext);
              return ID;
            }

"{"[^}]*"}" {}

[ \t]+      ;
\n          { nLineas++; }

.           { printf("Error lexico: %s\n", yytext); }

%%

int yywrap() { return 1; }
