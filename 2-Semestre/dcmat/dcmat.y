%{
    #include "dcmat.hpp"
    #include "includes.hpp"
    #include <dcmat.tab.h>

    DCMAT dcmat;
    Expressao expressao;

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

%code requires {
    class Expressao;
}

%union{
    int integerValue;
    float floatValue;
    bool boolValue;
    char *stringValue;
    Expressao *expValue;
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
%type <expValue>Value;
%type <boolValue>Bool;
%type <expValue>Expressao;
%type <expValue>ExpressaoRest;
%type <expValue>ExpressaoPow;
%type <expValue>Termo;
%type <expValue>ExpressaoSub;
%type <expValue>ExpressaoAdd;
%type <expValue>ExpressaoDiv;
%type <expValue>ExpressaoMult;

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
            if(result.type == "INT"){
                std::cout << $1 << " " << result.value->value << "\n";
            }else if(result.type == "FLOAT"){
                printf("%s = %.*f\n", $1, precision, result.value->value);
            }
        }else{
            std::cout << "Undefined symbol\n";
        }
    }
    | IDENTIFIER ASSIGN Expressao SEMICOLON {
         Expressao *exp = $3;
         dcmat.CreateHashItem($1, exp, exp->type);
    }
    | MATRIX EQUAL L_SQUARE_BRACKET R_PAREN SEMICOLON;
    | Expressao { Expressao *exp = $1;  if(!exp->function)std::cout << exp->value << "\n"; if(exp->function)std::cout << "É uma função";}


Set: FLOAT PRECISION INT[value] SEMICOLON {
        if($value <= 8 && $value >= 0){
            precision = $value;
        }else{
            printf("ERROR: float precision must be from 0 to 8\n");
        }
        };
    | H_VIEW Value COLON Value SEMICOLON { 
            Expressao *exp1, *exp2;
            exp1 = static_cast<Expressao*>($2);
            exp2 = static_cast<Expressao*>($4);
            if(exp1->value < exp2->value){
                h_view_lo = exp1->value ;
                h_view_hi = exp2->value ;
            } else{
                printf("ERROR: h_view_lo must be smaller than h_view_hi\n");
            }
        };
    | V_VIEW Value COLON Value SEMICOLON { 
            Expressao *exp1, *exp2;
            exp1 = static_cast<Expressao*>($2);
            exp2 = static_cast<Expressao*>($4);
            if(exp1->value < exp2->value){
                v_view_lo = exp1->value;
                v_view_hi = exp2->value;
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

ExpressaoSub: Termo SUBTRACT Expressao {
                Expressao *exp = new Expressao(); 
                exp->type = "SUB"; exp->left = $1; exp->right = $3; exp->value = exp->left->value - exp->right->value;
                $$ = exp; if($1->function || $3->function){ exp->function = true;};
            };
              | ExpressaoAdd {$$ = $1;}
            
ExpressaoAdd: Termo ADD Expressao {
                Expressao *exp = new Expressao(); 
                exp->type = "ADD"; exp->left = $1; exp->right = $3; exp->value = exp->left->value + exp->right->value;
                 if($1->function || $3->function){ exp->function = true;}; $$ = exp;
            };
              | ExpressaoDiv {$$ = $1;}

ExpressaoDiv: Termo DIV Expressao {
                Expressao *exp = new Expressao(); 
                exp->type = "DIV"; exp->left = $1; exp->right = $3; exp->value = exp->left->value / exp->right->value;
                if($1->function || $3->function){ exp->function = true;}; $$ = exp; 
            };
              | ExpressaoMult {$$ = $1;}

ExpressaoMult: Termo MULTIPLY Expressao {
                Expressao *exp = new Expressao(); 
                exp->type = "MULTIPLY"; exp->left = $1; exp->right = $3; exp->value = exp->left->value * exp->right->value;
                if($1->function || $3->function){ exp->function = true;}; $$ = exp; 
            };
               | ExpressaoRest {$$ = $1;}

ExpressaoRest: Termo REST Expressao {
                Expressao *exp = new Expressao(); 
                exp->type = "REST"; exp->left = $1; exp->right = $3;  exp->value = dcmat.CalcRest(exp->left->value, exp->right->value);
                if($1->function || $3->function){ exp->function = true;}; $$ = exp; 
            };
               | ExpressaoPow {$$ = $1;}

ExpressaoPow: Termo POW Expressao {
                Expressao *exp = new Expressao(); if($1->type == "FLOAT" || $3->type=="FLOAT"){exp->type = "FLOAT"; }else{
                    exp->type = "INT";
                };
                exp->oper = "POW"; exp->left = $1; exp->right = $3; exp->value = pow(exp->left->value, exp->right->value);
                if($1->function || $3->function){ exp->function = true;}; $$ = exp; 
            };
               | Termo {$$ = $1;}


Termo: IDENTIFIER {
            result = dcmat.FindHashItem($1);
            if(result.exists){
               $$ = result.value;
            }else{
                std::cout << "Undefined symbol [" << $1 << "]\n";
            }};
        | PI {
                Expressao *exp = new Expressao(); exp->value = pi; 
                exp->type = "FLOAT"; exp->oper = "OPERANDO";
                $$ = exp;
            };
        | E  { Expressao *exp = new Expressao(); exp->value = euler; 
                exp->type = "FLOAT"; exp->oper = "OPERANDO";
                $$ = exp;
            } ;
        | Value {$$ = $1;};
        | SEN L_PAREN Expressao R_PAREN {
                Expressao *exp = new Expressao(); exp->exp = $3; exp->type = $3->type;
                exp->oper = "SEN"; exp->function = $3->function; exp->value = sin($3->value);
                $$ = exp; 
            }
        | COS L_PAREN Expressao R_PAREN  {
                Expressao *exp = new Expressao(); exp->exp = $3; exp->type = $3->type;
                exp->oper = "COS"; exp->function = $3->function; exp->value = cos($3->value);
                $$ = exp;
            }
        | TAN L_PAREN Expressao R_PAREN  {
                Expressao *exp = new Expressao(); exp->exp = $3; exp->type = $3->type;
                exp->oper = "TAN"; exp->function = $3->function;  exp->value = tan($3->value);
                $$ = exp;
            }
        | ABS L_PAREN Expressao R_PAREN  {
                Expressao *exp = new Expressao(); exp->exp = $3; exp->type = $3->type;
                exp->oper = "ABS"; exp->function = $3->function; exp->value = abs($3->value);
                $$ = exp;
            }

Value: NumInt {  Expressao *exp = new Expressao(); exp->value = $1; exp->oper = "OPERANDO";
                exp->type = "INT"; $$ = exp;
                };
    | ADD NumInt {Expressao *exp = new Expressao(); exp->value = $2; exp->oper = "OPERANDO";
                    exp->type = "INT";  $$ = exp;
                }; 
    | SUBTRACT NumInt {Expressao *exp = new Expressao(); exp->value = -$2; exp->oper = "OPERANDO";
                    exp->type = "INT";  $$ = exp;
                }; 
    | NumFloat {Expressao *exp = new Expressao(); exp->value = $1; exp->oper = "OPERANDO";
                    exp->type = "FLOAT";  $$ = exp;
                };
    | ADD NumFloat {Expressao *exp = new Expressao(); exp->value = $2; exp->oper = "OPERANDO";
                    exp->type = "FLOAT";  $$ = exp;
                };
    | SUBTRACT NumFloat {Expressao *exp = new Expressao(); exp->value = -$2; exp->oper = "OPERANDO";
                    exp->type = "FLOAT";  $$ = exp;
                }; 
    | L_PAREN Expressao R_PAREN {$$ = $2;};
    | SUBTRACT L_PAREN Expressao R_PAREN {$3->value = -$3->value; $$ =$3; };
    | ADD L_PAREN Expressao R_PAREN {$$ =$3; };
    | VAR {Expressao *exp = new Expressao(); exp->function = true; exp->type = "VAR"; $$ = exp;}
    | SUBTRACT VAR {Expressao *exp = new Expressao(); exp->function = true; exp->type = "SUBVAR"; $$ = exp;}
    | ADD VAR {Expressao *exp = new Expressao(); exp->function = true; exp->type = "VAR"; $$ = exp;}



NumInt: INT   {
            $$ = $1;
        };

NumFloat: REAL { $$ = $1; };

Bool: ON { $$ = true; }; 
    | OFF { $$ = false; };

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