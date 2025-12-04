%{
  #include "y.tab.h"
  int nLineas = 0;
%}

entero  [0-9]+
real    {entero}"."{entero}
iden    [a-zA-Z][a-zA-Z0-9]*
cadena  (\"[^\"]*\"|\'[^\']*\')

bool    (true|false)

%%

{real}      { printf("\n [LEX]REAL"); return REAL; }
{entero}    { printf("\n [LEX]NUM"); return NUM; }
{cadena}    { printf("\n [LEX]CADENA"); return CADENA; }
{bool}      { printf("\n [LEX]BOOL"); return BOOL; }

const       { printf("\n [LEX]CONST"); return CONST; }
program     { printf("\n [LEX]PROGRAM"); return PROGRAM; }
var         { printf("\n [LEX]VAR"); return VAR; }

integer     { printf("\n [LEX]INTEGER"); return INTEGER; }
real        { printf("\n [LEX]REAL_TIPO"); return REAL_TIPO; }
string      { printf("\n [LEX]STRING"); return STRING; }
boolean     { printf("\n [LEX]BOOLEAN"); return BOOLEAN; }

begin       { printf("\n [LEX]BEGGIN"); return BEGGIN; }
end         { printf("\n [LEX]ENDD"); return ENDD; }

":="        {printf("\n [LEX]ASIGNACION"); return ASIGNACION; }

writeln     {printf("\n [LEX]WRITELN"); return WRITELN; }
readln      {printf("\n [LEX]READLN"); return READLN; }

if          { printf("\n [LEX]IF"); return IF; }
else        { printf("\n [LEX]ELSE"); return ELSE; }
while       { printf("\n [LEX]WHILE"); return WHILE; }
do          { printf("\n [LEX]DO"); return DO; }
for         { printf("\n [LEX]FOR"); return FOR; }

then        { printf("\n [LEX]THEN"); return THEN; }
to          { printf("\n [LEX]TO"); return TO; }
downto      { printf("\n [LEX]DOWNTO"); return DOWNTO; }

","         { printf("\n [LEX]COMA"); return ','; }
";"         { printf("\n [LEX]PYC"); return ';'; }

div         { printf("\n [LEX]DIV"); return DIV; }
mod         { printf("\n [LEX]MOD"); return MOD; }
and         { printf("\n [LEX]AND"); return AND; }
or          { printf("\n [LEX]OR"); return OR; }
not         { printf("\n [LEX]NOT"); return NOT; }

"+"         { printf("\n [LEX]MAS"); return MAS; }
"-"         { printf("\n [LEX]MENOS"); return MENOS; }
"*"         { printf("\n [LEX]POR"); return POR; }
"**"        { printf("\n [LEX]POTENCIA"); return POTENCIA; }

"<"         { printf("\n [LEX]MENOR"); return MENOR; }
">"         { printf("\n [LEX]MAYOR"); return MAYOR; }
"<="        { printf("\n [LEX]MENORIGUAL"); return MENORIGUAL; }
">="        { printf("\n [LEX]MAYORIGUAL"); return MAYORIGUAL; }
"="         { printf("\n [LEX]IGUAL"); return IGUAL; }
"<>"        { printf("\n [LEX]ENTRE"); return ENTRE; }

"&"         { printf("\n [LEX]AMPERSAND"); return AMPERSAND; }

{iden}      { printf("\n [LEX]ID"); return ID; }

"{"[^}]*"}" { printf("\n [LEX]COMENTARIO (Ignorado)"); }

[ \t]+      ;
\n          { nLineas++; }

.           { printf("\n [LEX][%c]", yytext[0]); return yytext[0]; }

%%

int yywrap() { return 1; }
