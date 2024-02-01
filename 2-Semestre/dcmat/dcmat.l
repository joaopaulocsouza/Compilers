%option noyywrap
%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include "dcmat.tab.h"
%}

%%

"+" return ADD;
"-" return SUBTRACT;
"*" return MULTIPLY;
"/" return DIV;
"^" return POW;
"%" return REST;
"(" return L_PAREN;
")" return R_PAREN;
":=" return ASSIGN;
":" return COLON;
"[" return L_SQUARE_BRACKET;
"]" return R_SQUARE_BRACKET;
";" return SEMICOLON;
"," return COMMA;

"about" return ABOUT;
"abs" return ABS;
"axis" return AXIS;
"connect_dots" return CONNECT_DOTS;
"cos" return COS;
"determinant" return DETERMINANT;
"erase" return ERASE;
"float" return FLOAT;
"h_view" return H_VIEW;
"integral_steps" return INTEGRAL_STEPS;
"integrate" return INTEGRATE;
"linear_system" return LINEAR_SYSTEM;
"matrix" return MATRIX;
"off" return OFF;
"on" return ON;
[Pp][Ii] return PI;
[Ee] return E; 
[Xx] return VAR;
"plot" return PLOT;
"precision" return PRECISION;
"quit" return QUIT;
"reset" return RESET;
"rpn" return RPN;
"sen" return SEN;
"settings" return SETTINGS;
"set" return SET;
"show" return SHOW;
"solve" return SOLVE;
"sum" return SUM;
"symbols" return SYMBOLS;
"tan" return TAN;
"v_view" return V_VIEW;

[-+]?[0-9]+"."[0-9]+ {yylval.floatValue = atof(yytext); return REAL;}
[-+]?[0-9]+ {yylval.integerValue = atoi(yytext);  return INT;}
[a-zA-Z]+[0-9a-zA-Z]* return IDENTIFIER;
"\n" return EOL;
"\0" return EOL;
[ ] {};
"\t" {};

. {printf("Invalid Symbol: %s", yytext); return 0;}

%%
