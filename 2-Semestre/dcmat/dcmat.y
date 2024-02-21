%{
    #include "dcmat.hpp"
    #include "includes.hpp"
    #include <dcmat.tab.h>

    DCMAT dcmat;
    Expressao expressao;
    Expressao *function = nullptr; 

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
%type <expValue>Termo;
%type <expValue>ExpressionSumSub;
%type <expValue>ExpressionPowRem;
%type <expValue>ExpressionMulDiv;
%type <expValue>Signal;

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
            if(result.type == INT_KEY){
                std::cout << $1 << " = " << result.value->value << "\n";
            }else if(result.type == FLOAT_KEY){
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
    | Expressao { Expressao *exp = $1; 
        if(exp->element != FUNCTION_KEY){std::cout << std::fixed << std::setprecision(precision) << exp->value << "\n"; }
        else{ std::cout << "funcao: "<< expressao.CalcFunctionValue(5, exp) << std::endl;}}
    | PLOT L_PAREN Expressao R_PAREN SEMICOLON {
        if($3->element == FUNCTION_KEY){
            function = $3;
            dcmat.PlotChart(function);
        }else{
            std::cout << "No Function defined!\n";
        }
    };
    | PLOT SEMICOLON {
        if(function){
            dcmat.PlotChart(function);
        }else{
            std::cout << "No Function defined!\n";
        }
    }


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


Expressao: ExpressionSumSub {$$ = $1;};

ExpressionSumSub: ExpressionMulDiv ADD ExpressionSumSub {
                        $$ = dcmat.CreateExp(ADD_KEY, $1, $3);    
                };
                | ExpressionMulDiv SUBTRACT ExpressionSumSub {
                        $$ = dcmat.CreateExp(SUB_KEY, $1, $3);    
                };
                | ExpressionMulDiv {$$ = $1;};

ExpressionMulDiv: ExpressionPowRem MULTIPLY ExpressionMulDiv {
                        $$ = dcmat.CreateExp(MULTIPLY_KEY, $1, $3);    
                };
                | ExpressionPowRem DIV ExpressionMulDiv {
                        $$ = dcmat.CreateExp(DIV_KEY, $1, $3);    
                };
                | ExpressionPowRem {$$ = $1;};

ExpressionPowRem: Signal POW ExpressionPowRem {
                        $$ = dcmat.CreateExp(POW_KEY, $1, $3);    
                };
                | Signal REST ExpressionPowRem {
                        $$ = dcmat.CreateExp(REST, $1, $3);    
                };
                | Signal {$$ = $1;};

Signal: Termo {$$ = $1;};
        | ADD Termo {$$ = $2;};
        | SUBTRACT Termo {
            if($2->type == VAR_KEY) $2->type = SUBVAR_KEY;
            if($2->element != FUNCTION_KEY) $2->value = -$2->value;
            $$ = $2;
        }

Termo: IDENTIFIER {
            result = dcmat.FindHashItem($1);
            if(result.exists){
               $$ = result.value;
            }else{
                std::cout << "Undefined symbol [" << $1 << "]\n";
            }};
        | Value {$$ = $1;};
        | SEN L_PAREN Expressao R_PAREN { 
                float value = 0;
                if($3->element != FUNCTION_KEY)value = sin($3->value);
                $$ = dcmat.CreateSheet($3->type, SEN_KEY, value, $3);
            }
        | COS L_PAREN Expressao R_PAREN  { 
                float value = 0;
                if($3->element != FUNCTION_KEY) value = cos($3->value);
                $$ = dcmat.CreateSheet($3->type, COS_KEY, value, $3);
            }
        | TAN L_PAREN Expressao R_PAREN  { 
                float value = 0;
                if($3->element != FUNCTION_KEY) value = tan($3->value);
                $$ = dcmat.CreateSheet($3->type, TAN_KEY, value, $3);
            }
        | ABS L_PAREN Expressao R_PAREN { 
                float value = 0;
                if($3->element != FUNCTION_KEY) value = abs($3->value);
                $$ = dcmat.CreateSheet($3->type, ABS_KEY, value, $3);
            }

Value: NumInt { $$ = dcmat.CreateSheet(INT_KEY, OP, $1, nullptr); }; 
    | NumFloat { $$ = dcmat.CreateSheet(FLOAT_KEY, OP, $1, nullptr); };
    | L_PAREN Expressao R_PAREN { $$ = $2;};
    | VAR {$$ = dcmat.CreateSheet(VAR_KEY, OP, 0, nullptr); }
    | PI { $$ = dcmat.CreateSheet(FLOAT_KEY, OP, pi, nullptr); };
    | E  { $$ = dcmat.CreateSheet(FLOAT_KEY, OP, euler, nullptr); } ;



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