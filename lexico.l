%{
#include "y.tab.h"
#include <string.h>

extern int nLineas;
%}

%option noyywrap
%option noinput nounput

entero  [0-9]+
real    {entero}"."{entero}
iden    [a-zA-Z][a-zA-Z0-9]*
cadena  \"[^\"]*\"

%%

{real}      { yylval.tipo = 2; return REAL; }
{entero}    { yylval.tipo = 1; return NUM; }
{cadena}    { yylval.tipo = 3; return CADENA; }
"true"|"false" { yylval.tipo = 4; return BOOL; }

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

"{"[^}]*"}"             ;
"(*"([^*]|(\*+[^)]))*"*)" ;

[ \t]+      ;
\n          { nLineas++; }

.           ;

%%
