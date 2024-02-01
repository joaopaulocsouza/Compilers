%{
    #include "dcmat.hpp"
    #include <dcmat.tab.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    DCMAT dcmat;

    extern float h_view_lo;
    extern float h_view_hi;
    extern float v_view_lo;
    extern float v_view_hi;
    extern int precision;
    extern int integral_steps;
    extern bool Axis;
    extern bool Erase_Plot;

    extern int yylex();
    extern char* yytext;
    extern int yychar;
    extern int yyleng;
    void yyerror(char *s);
%}

%union{
    int integerValue;
    float floatValue;
    bool boolValue;
}

%token ADD;
%token SUBTRACT;
%token MULTIPLY;
%token DIV;
%token POW;
%token REST;
%token L_PAREN;
%token R_PAREN;
%token ASSIGN;
%token COLON;
%token L_SQUARE_BRACKET;
%token R_SQUARE_BRACKET;
%token SEMICOLON;
%token COMMA;
%token ABOUT;
%token ABS;
%token AXIS;
%token CONNECT_DOTS;
%token COS;
%token DETERMINANT;
%token ERASE;
%token FLOAT;
%token H_VIEW;
%token INTEGRAL_STEPS;
%token INTEGRATE;
%token LINEAR_SYSTEM;
%token MATRIX;
%token OFF;
%token ON;
%token PI;
%token E; 
%token VAR;
%token PLOT;
%token PRECISION;
%token QUIT;
%token RESET;
%token RPN;
%token SEN;
%token SET;
%token SETTINGS;
%token SHOW;
%token SOLVE;
%token SUM;
%token SYMBOLS;
%token TAN;
%token V_VIEW;
%token <integerValue>INT;
%token <floatValue>REAL;
%token IDENTIFIER;
%token EOL;

%type <floatValue>ExpNum;
%type <boolValue>ExpEnable;

%start Dcmat;

%%

Dcmat: EOL {return 0;}
    | QUIT EOL {exit(0);}
    | Exp EOL

Exp: SHOW SETTINGS SEMICOLON {dcmat.ShowSettings(); return 0;}
    | RESET SETTINGS SEMICOLON {dcmat.ResetSettings(); return 0;}
    | ABOUT SEMICOLON {
        printf("+----------------------------------------------+\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 17; i++) {printf(" ");};  printf("201800560120"); for(int i = 0; i < 17; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 9; i++) {printf(" ");};  printf("João Paulo Cardoso de Souza"); for(int i = 0; i < 10; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("+----------------------------------------------+\n\n");
        return 0;
    }
    | SET Set;

Set: FLOAT PRECISION INT[value] SEMICOLON {
        if($value <= 8 && $value >= 0){
            precision = $value;
        }else{
            printf("ERROR: float precision must be from 0 to 8\n");
        }
        return 0;}
    | H_VIEW ExpNum COLON ExpNum SEMICOLON { 
            if($2 < $4){
                h_view_lo = $2;
                h_view_hi = $4;
            } 
            return 0;
        };
    | V_VIEW ExpNum COLON ExpNum SEMICOLON { 
            if($2 < $4){
                v_view_lo = $2;
                v_view_hi = $4;
            } 
            return 0;
        };
    | AXIS ExpEnable SEMICOLON {
            Axis = $2;
            return 0;
        };
    | ERASE PLOT ExpEnable SEMICOLON {
            Erase_Plot = $3;
            return 0;
        };
    | INTEGRAL_STEPS INT SEMICOLON {
            integral_steps = $2;
            return 0;
        };
    
ExpNum: REAL {
            $$ = $1;
        };
    | INT   {
            $$ = $1;
        };
ExpEnable: ON {
                $$ = true;
            }; 
        | OFF {
            $$ = false;
        };

%%

void yyerror(char *s) {

    printf("Erro sintático: %s\n", yytext);

    return;

    /* attInput(line);

    (yychar == 0)?expectedDelaration():syntaxError(); */
}

int main(int argc, char **argv) {
    while(1){
        printf("> ");
        yyparse();
    }
    return 0;
}