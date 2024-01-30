%option noyywrap
%{
#include "sintatico.tab.h"
%}

%%

[ \t\n]  ; /* ignore whitespace and newline */

"+"  { return ADD; }
"-"  { return SUB; }
"*"  { return MUL; }
"/"  { return DIV; }
"^"  { return POW; }
"%"  { return MOD; }

"("  { return LPAREN; }
")"  { return RPAREN; }

"sen"    { return SIN; }
"cos"    { return COS; }
"tan"    { return TAN; }
"abs"    { return ABS; }

[a-z][a-zA-Z0-9]* {
              yylval.strval = strdup(yytext);
              return VAR;
            }

[0-9]+\.[0-9]* {
              yylval.floatval = atof(yytext);
              return REAL;
            }

[0-9]+ {
          yylval.intval = atoi(yytext);
          return INT;
        }

.       { fprintf(stderr, "Caractere inesperado: %s\n", yytext); }

%%
