%{
  #include "y.tab.h"
  int nLineas = 0;
%}

entero  [0-9]+
real    {entero}"."{entero}
iden    [a-zA-Z][a-zA-Z0-9]*
cadena  \"([^\\\"]|\\.)*\"
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


{iden}      { printf("\n [LEX]ID"); return ID; }

[ \t]+      ;    /* Ignorar espacios y tabulaciones */

\n          { nLineas++; }

.           { printf("\n [LEX][%c]", yytext[0]); return yytext[0]; }

%%

int yywrap() {
    return 1;
}

