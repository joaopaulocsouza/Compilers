%{
    #include "dcmat.hpp"
    #include "includes.hpp"
    #include <dcmat.tab.h>

    DCMAT dcmat;

    DeclaredVar result;

    extern float h_view_lo;
    extern float h_view_hi;
    extern float v_view_lo;
    extern float v_view_hi;
    extern int precision;
    extern int integral_steps;
    extern bool Axis;
    extern bool Erase_Plot;

    float euler = 2.71828182;
    float pi = 3.14159265;

    bool isLexico = false;
    extern int yylex();
    extern char* yytext;
    extern int yychar;
    extern int yyleng;
    void yyerror(const void *s);
%}

%union{
    int integerValue;
    float floatValue;
    bool boolValue;
    char *stringValue;
}

%token ADD;
%token SUBTRACT;
%token MULTIPLY;
%token DIV;
%token POW;
%token REST;
%token L_PAREN;
%token R_PAREN;
%token EQUAL;
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
%token <stringValue>IDENTIFIER;
%token EOL;

%type <integerValue>NumInt;
%type <floatValue>NumFloat;
%type <floatValue>Value;
%type <boolValue>Bool;
%type <floatValue>Expressao;
%type <floatValue>ExpressaoRest;
%type <floatValue>ExpressaoPow;
%type <floatValue>Termo;
%type <floatValue>ExpressaoSub;
%type <floatValue>ExpressaoAdd;
%type <floatValue>ExpressaoDiv;
%type <floatValue>ExpressaoMult;

%start Dcmat;

%%

Dcmat: EOL {return 0;}
    | QUIT EOL {exit(0);}
    | Command EOL {return 0;}

Command: SHOW SYMBOLS SEMICOLON {dcmat.ShowSymbols();}
    | SHOW SETTINGS SEMICOLON {dcmat.ShowSettings();}
    | RESET SETTINGS SEMICOLON {dcmat.ResetSettings();}
    | ABOUT SEMICOLON {
        printf("+----------------------------------------------+\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 17; i++) {printf(" ");};  printf("201800560120"); for(int i = 0; i < 17; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 9; i++) {printf(" ");};  printf("João Paulo Cardoso de Souza"); for(int i = 0; i < 10; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(int i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("+----------------------------------------------+\n\n");
    }
    | SET Set;
    | IDENTIFIER SEMICOLON {
        result = dcmat.FindHashItem($1);
        if(result.exists){
            printf("%s = %.*f\n", $1, precision, result.value);
        }else{
            std::cout << "Undefined symbol\n";
        }
    }
    | IDENTIFIER ASSIGN Expressao SEMICOLON {
        dcmat.CreateHashItem($1, $3);
    }
    | MATRIX EQUAL L_SQUARE_BRACKET R_PAREN SEMICOLON;
    | Expressao { std::cout << $1 << "\n";}


Set: FLOAT PRECISION INT[value] SEMICOLON {
        if($value <= 8 && $value >= 0){
            precision = $value;
        }else{
            printf("ERROR: float precision must be from 0 to 8\n");
        }
        };
    | H_VIEW Value COLON Value SEMICOLON { 
            if($2 < $4){
                h_view_lo = $2;
                h_view_hi = $4;
            } else{
                printf("ERROR: h_view_lo must be smaller than h_view_hi\n");
            }
        };
    | V_VIEW Value COLON Value SEMICOLON { 
            if($2 < $4){
                v_view_lo = $2;
                v_view_hi = $4;
            }else{
                printf("ERROR: v_view_lo must be smaller than v_view_hi\n");
            }
        };
    | AXIS Bool SEMICOLON {
            Axis = $2;
        };
    | ERASE PLOT Bool SEMICOLON {
            Erase_Plot = $3;
        };
    | INTEGRAL_STEPS INT SEMICOLON {
            integral_steps = $2;
        };


Expressao: ExpressaoSub {$$ = $1;};

ExpressaoSub: Termo SUBTRACT Expressao {$$ = $1 - $3;};
              | ExpressaoAdd {$$ = $1;}
            
ExpressaoAdd: Termo ADD Expressao {$$ = $1 + $3;};
              | ExpressaoMult {$$ = $1;}

ExpressaoDiv: Termo DIV Expressao {$$ = $1 * $3;};
              | ExpressaoMult {$$ = $1;}

ExpressaoMult: Termo MULTIPLY Expressao {$$ = $1 * $3;};
               | ExpressaoRest {$$ = $1;}

ExpressaoRest: Termo REST Expressao {$$ = $1 / $3;};
               | ExpressaoPow {$$ = $1;}

ExpressaoPow: Termo POW Expressao {$$ =  pow($1, $3);};
               | Termo {$$ = $1;}


Termo:  L_PAREN Expressao R_PAREN {$$ = $2;};
        | IDENTIFIER {
            result = dcmat.FindHashItem($1);
            if(result.exists){
               $$ = result.value;
            }else{
                std::cout << "Undefined symbol [" << $1 << "]\n";
            }};
        | PI {$$ = pi;};
        | E {$$ = euler;}; 
        | Value {$$ = $1;};
        | SEN L_PAREN Expressao R_PAREN {$$ = sin($3);}
        | COS L_PAREN Expressao R_PAREN {$$ = cos($3);}
        | TAN L_PAREN Expressao R_PAREN {$$ = tan($3);}
        | ABS L_PAREN Expressao R_PAREN {$$ = abs($3);}

Value: NumInt { $$ = $1;};
    | ADD NumInt {$$ = $2;} ; 
    | SUBTRACT NumInt { $$ = -$2;} ; 
    | NumFloat { $$ = $1;};
    | ADD NumFloat {$$ = $2;} ; 
    | SUBTRACT NumFloat { $$ = -$2;} ; 


NumInt: INT   {
            $$ = $1;
        };

NumFloat: REAL {
            $$ = $1;
        };

Bool: ON {
                $$ = true;
            }; 
        | OFF {
            $$ = false;
        };

%%

void expectedDelaration(){
     std::cout << "SYNTAX ERROR: Incomplete Command\n";
    return;
}

void syntaxError(){
    std::cout << "SYNTAX ERROR: " << yytext << "\n";
}

void yyerror(const void *s) {

    if(!isLexico){
        (yychar == 0)?expectedDelaration():syntaxError(); 
    }
    else{
        isLexico = false;
    }

    return;
}

int main(int argc, char **argv) {
    while(1){
        printf("> ");
        yyparse();
    }
    return 0;
}