%{
    #include "dcmat.hpp"
    #include "includes.hpp"
    #include <dcmat.tab.h>

    DCMAT dcmat;
    Expressao expressao;
    Expressao *function = nullptr; 
    Expressao *matrix = nullptr;

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
    int i = 0;
    int j = 0;

    bool hasError = false;
    bool hasUndeclared = false;
    Vetor *undeclared = new Vetor();

    bool isLexico = false;
    extern int yylex();
    extern char* yytext;
    extern int yychar;
    extern int yyleng;
    void yyerror(const void *s);
    void PrintUndeclareds();
    void clearMemory();
    bool stopPrint = false;
%}

%code requires {
    class Expressao;
    class MatrixClass;
    class Vetor;
}

%union{
    int integerValue;
    float floatValue;
    bool boolValue;
    char *stringValue;
    Expressao *expValue;
    MatrixClass *matrixValue;
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
%type <floatValue>Limit;
%type <matrixValue>Matrix;
%type <matrixValue>MatrixColum;
%type <matrixValue>MatrixLine;
%type <matrixValue>MatrixValue;

%start Dcmat;

%%

Dcmat:
    | EOL {stopPrint = false; undeclared->vetor.clear(); isLexico = false; return 0;}
    | QUIT EOL { clearMemory(); exit(0);}
    | Command EOL {stopPrint = false; hasUndeclared = false; isLexico = false; undeclared->vetor.clear() ;return 0;}

Command: SHOW SYMBOLS SEMICOLON {dcmat.ShowSymbols();}
    | SHOW SETTINGS SEMICOLON {dcmat.ShowSettings();}
    | SHOW MATRIX SEMICOLON {
        if(matrix != nullptr){
            dcmat.ShowMatrix(matrix->matrix);}
        else {
            std::cout << "\nNo Matrix defined!\n\n";
            }}
    | RESET SETTINGS SEMICOLON {dcmat.ResetSettings();}
    | ABOUT SEMICOLON {
        printf("\n+----------------------------------------------+\n");
        printf("|"); for(i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(i = 0; i < 17; i++) {printf(" ");};  printf("201800560120"); for(i = 0; i < 17; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(i = 0; i < 9; i++) {printf(" ");};  printf("João Paulo Cardoso de Souza"); for(i = 0; i < 10; i++) {printf(" ");}; printf("|\n");
        printf("|"); for(i = 0; i < 46; i++) {printf(" ");}; printf("|\n");
        printf("+----------------------------------------------+\n\n");
    }
    | SET Set;
    | IDENTIFIER SEMICOLON {
        result = dcmat.FindHashItem($1);
        if(result.exists){
            if(result.type == MATRIX_KEY){
                dcmat.ShowMatrix(result.value->matrix);
            }
            else if(result.type == INT_KEY){
                std::cout << "\n" << $1 << " = " << result.value->value << "\n\n";
            }else if(result.type == FLOAT_KEY){
                std::cout << "\n" << std::fixed << std::setprecision(precision) << $1 << " = " << result.value->value << "\n\n";
            }
        }else{
            std::cout << "\nUndefined symbol\n\n";
        }
    }
    | IDENTIFIER ASSIGN Expressao SEMICOLON {
        if(hasUndeclared){
            PrintUndeclareds();
        }else if($3 != nullptr && $3->element != FUNCTION_KEY){
            Expressao *exp = $3;
            dcmat.CreateHashItem($1, exp, exp->type);
            if(exp->type == FLOAT_KEY || exp->type == INT_KEY) {
                std::cout << "\n" << std::fixed << std::setprecision(precision) << (float)exp->value << "\n\n" ;
            } else if(exp->type == MATRIX_KEY){
                dcmat.ShowMatrix($3->matrix);
            }
        };
    }
    | IDENTIFIER ASSIGN Matrix SEMICOLON{
        if($3 != nullptr){
            if($3->lines > 10 || $3->columns > 10){
                std::cout << "\nERROR: Matrix limits out of boundaries.\n" << std::endl;
            }else{
                Expressao *exp = expressao.CreateMatrix($3);
                dcmat.CreateHashItem($1, exp, MATRIX_KEY);
                dcmat.ShowMatrix($3);
            }
        }
    }
    | MATRIX EQUAL Matrix SEMICOLON{
        if($3->lines > 10 || $3->columns > 10){
            std::cout << "\nERROR: Matrix limits out of boundaries.\n" << std::endl;
        }else{
            if(matrix){
                matrix->matrix = $3;
            }else{
                Expressao *exp = expressao.CreateMatrix($3);
                matrix = exp;
            }
        }
    };
    | SOLVE DETERMINANT SEMICOLON {
        if(matrix){
            if(matrix->matrix->lines != matrix->matrix->columns){
                std::cout << "Matrix format incorrect!\n";
            }else{
                float det = dcmat.SolveDeterminant(matrix->matrix);
                std::cout << "\n" << std::fixed << std::setprecision(precision) << det << "\n\n";
            }
        }else{
            std::cout << "\nNo Function defined!\n\n";
        }
    }
    | SOLVE LINEAR_SYSTEM SEMICOLON {
        if(matrix){
            if(matrix->matrix->lines != matrix->matrix->columns-1){
                std::cout << "\nMatrix format incorrect!\n\n";
            }else{
                dcmat.SolveLinearSystem(matrix->matrix);
            }
        }else{
            std::cout << "\nNo Function defined!\n\n";
        }
    }
    | Expressao { 
        if($1 != nullptr){
            Expressao *exp = $1; 
            if(!stopPrint){
                if(hasUndeclared){
                    PrintUndeclareds();
                }else if(exp->element != FUNCTION_KEY){
                    if(exp->type == MATRIX_KEY){
                        dcmat.ShowMatrix(exp->matrix);
                    }else{
                        std::cout << "\n" << std::fixed << std::setprecision(precision) << exp->value << "\n\n"; 
                    }
                }
                else{ 
                    std::cout << "\nThe x variable cannot be present on expressions.\n" << std::endl;}
                }
            }
        }
    | PLOT L_PAREN Expressao R_PAREN SEMICOLON {
        if(!stopPrint){
            if(hasUndeclared){
                PrintUndeclareds();
            }else{
                function = $3;
                dcmat.PlotChart(function);
            }
        }
    };
    | PLOT SEMICOLON {
        if(function){
            dcmat.PlotChart(function);
        }else{
            std::cout << "\nNo Function defined!\n\n";
        }
    }
    | INTEGRATE L_PAREN Limit COLON Limit COMMA Expressao R_PAREN SEMICOLON {
        if(hasUndeclared){
            PrintUndeclareds();
        }else if($5 <= $3){
            std::cout << "\nERROR: lower limit must be smaller than upper limit\n\n";
        }else{
            dcmat.Integrate($5, $3, $7);
        }
    }
    | SUM L_PAREN IDENTIFIER COMMA Limit COLON Limit COMMA Expressao R_PAREN SEMICOLON {
         if(hasUndeclared){
            for(i = 0; i < undeclared->vetor.size(); i++){
                if(undeclared->vetor[i] == $3){
                    undeclared->vetor.erase(undeclared->vetor.begin() + i);
                }
            }
        }

        undeclared->vetor.size() > 0 ?PrintUndeclareds():dcmat.Sum($5, $7, $9);
    }
    | RPN L_PAREN Expressao R_PAREN SEMICOLON {
        std::cout << "\nExpression in RPN format:\n\n";
        dcmat.ReversePolishNotation($3);
        std::cout << "\n\n";
    }

Matrix: L_SQUARE_BRACKET MatrixLine MatrixColum R_SQUARE_BRACKET 
    {
        $2->matrix.push_back($2->line);
        if($3 != nullptr){
            for(i = 0; i < $3->matrix.size(); i++){
                $2->matrix.push_back($3->matrix[i]);
            } 
        }
        $2->lines = $2->matrix.size();
        $2->columns = $2->matrix[0].size();
        for(i = 0; i < $2->matrix.size(); i++){
            if($2->columns < $2->matrix[i].size()) $2->columns = $2->matrix[i].size();
        }
        for(i = 0; i < $2->lines; i++){
            if($2->columns > $2->matrix[i].size()){
                for(j = $2->matrix[i].size()-1; j < $2->columns; j++) $2->matrix[i].push_back(0);
            }
        }
        $$ = $2;
    };

MatrixColum: MatrixColum COMMA MatrixLine {
            MatrixClass *line = nullptr;
                if($1 != nullptr){
                    $1->matrix.push_back($3->line);
                    line = $1;
                }else{
                    line = new MatrixClass();
                    line->matrix.push_back($3->line);
                }
            $$ = line;
        }
        | {$$ = nullptr;};

MatrixLine: L_SQUARE_BRACKET Limit MatrixValue R_SQUARE_BRACKET {
        MatrixClass *line = new MatrixClass();
        line->line.push_back($2);
        if($3 != nullptr){
            for(i = 0; i < $3->line.size(); i++){
                line->line.push_back($3->line[i]);
            }
        }
        $$ = line;
    };

MatrixValue: MatrixValue COMMA Limit { 
        MatrixClass *line = nullptr;
            if($1 != nullptr){
                $1->line.push_back($3);
                line = $1;
            }else{
                line = new MatrixClass();
                line->line.push_back($3);
            }
            $$ = line;
        }
        | {$$ = nullptr;};


Set: FLOAT PRECISION Limit[value] SEMICOLON {
        if($value <= 8 && $value >= 0){
            precision = $value;
        }else{
            printf("\nERROR: float precision must be from 0 to 8\n\n");
        }
        };
    | H_VIEW Limit COLON Limit SEMICOLON {
            if($2 < $4){
                h_view_lo = $2;
                h_view_hi = $4;
            }else{
                printf("\nERROR: h_view_lo must be smaller than h_view_hi\n\n");
            }
        };
    | V_VIEW Limit COLON Limit SEMICOLON {
            if($2 < $4){
                v_view_lo = $2;
                v_view_hi = $4;
            }else{
                printf("\nERROR: v_view_lo must be smaller than v_view_hi\n\n");
            }
        };
    | AXIS Bool SEMICOLON {
            Axis = $2;
        };
    | ERASE PLOT Bool SEMICOLON {
            Erase_Plot = $3;
        };
    | INTEGRAL_STEPS Limit SEMICOLON {
        if($2 <= 0){
            std::cout << "\nERROR: integral_steps must be a positive non-zero integer\n\n";
        }else{
            integral_steps = (int)$2;
        }
    };


Expressao: ExpressionSumSub {$$ = $1;};

ExpressionSumSub: ExpressionSumSub ADD ExpressionMulDiv {
                        $$ = ($1 == nullptr || $3 == nullptr)? nullptr:expressao.CreateExp(ADD_KEY, $1, $3);    
                };
                | ExpressionSumSub SUBTRACT ExpressionMulDiv {
                        $$ = ($1 == nullptr || $3 == nullptr)? nullptr:expressao.CreateExp(SUB_KEY, $1, $3);    
                };
                | ExpressionMulDiv {$$ = $1;};

ExpressionMulDiv: ExpressionMulDiv MULTIPLY ExpressionPowRem {
                        $$ = ($1 == nullptr || $3 == nullptr)? nullptr:expressao.CreateExp(MULTIPLY_KEY, $1, $3);    
                };
                | ExpressionMulDiv DIV ExpressionPowRem {
                        $$ = ($1 == nullptr || $3 == nullptr)? nullptr:expressao.CreateExp(DIV_KEY, $1, $3);    
                };
                | ExpressionPowRem {$$ = $1;};

ExpressionPowRem: ExpressionPowRem POW Signal {
                        $$ = ($1 == nullptr || $3 == nullptr)? nullptr:expressao.CreateExp(POW_KEY, $1, $3);    
                };
                | ExpressionPowRem REST Signal {
                        $$ = ($1 == nullptr || $3 == nullptr)? nullptr:expressao.CreateExp(REST, $1, $3);    
                };
                | Signal {$$ = $1;};

Signal: Termo {$$ = $1;};
        | ADD Termo {$$ = $2;};
        | SUBTRACT Termo {
            if($2->type == MATRIX_KEY){
                Expressao *exp = expressao.CreateMatrix($2->matrix);
                for(i = 0; i < exp->matrix->lines; i++){
                    for(j = 0; j < exp->matrix->columns; j++){
                        exp->matrix->matrix[i][j] *= -1; 
                    }
                }
                $$ = exp;
            }else{
                switch($2->type){
                    case VAR_KEY:
                        $2->type = SUBVAR_KEY;
                        break;
                    default:
                        if($2->element != FUNCTION_KEY && $2->type != ID_KEY) $2->value = -$2->value;
                        break;
                }
                $$ = $2;
            }
        }

Termo: IDENTIFIER {
            result = dcmat.FindHashItem($1);
            if(result.exists){
                result.value->id = $1;
                Expressao *exp = result.value->type != MATRIX_KEY?
                    expressao.CreateSheet(result.value->type, OP, result.value->value, result.value->exp, EXPRESSION_KEY, $1):expressao.CreateMatrix(result.value->matrix);
                exp->id = $1;
                $$ = exp;
            }else{
                Expressao *exp = expressao.CreateSheet(ID_KEY, OP, 0, nullptr, EXPRESSION_KEY, $1);
                $$ = exp;
                hasUndeclared = true;
                bool test = false;
                for(i = 0; i < undeclared->vetor.size(); i++){ 
                    if(undeclared->vetor[i] == $1){
                        test = true;
                        break;
                    }
                }
                if(!test)undeclared->vetor.push_back($1);
            }};
        | Value {$$ = $1;};
        | SEN L_PAREN Expressao R_PAREN { 
                if($3->type == MATRIX_KEY){
                    std::cout << "\nIncorrect type for operator ’SEN’ - have MATRIX\n\n";
                    $$ = nullptr;
                }else{
                    float value = 0;
                    int element = $3->element;
                    if($3->element != FUNCTION_KEY)value = sin($3->value);
                    $$ = expressao.CreateSheet($3->type, SEN_KEY, value, $3, element);
                }
            }
        | COS L_PAREN Expressao R_PAREN  { 
                if($3->type == MATRIX_KEY){
                    std::cout << "\nIncorrect type for operator ’COS’ - have MATRIX\n\n";
                    $$ = nullptr;
                }else{
                    float value = 0;
                    int element = $3->element;
                    if($3->element != FUNCTION_KEY) value = cos($3->value);
                    $$ = expressao.CreateSheet($3->type, COS_KEY, value, $3, element);
                }
            }
        | TAN L_PAREN Expressao R_PAREN  { 
                if($3->type == MATRIX_KEY){
                    std::cout << "\nIncorrect type for operator ’TAN’ - have MATRIX\n\n";
                    $$ = nullptr;
                }else{
                    float value = 0;
                    int element = $3->element;
                    if($3->element != FUNCTION_KEY) value = tan($3->value);
                    $$ = expressao.CreateSheet($3->type, TAN_KEY, value, $3, element);
                }
            }
        | ABS L_PAREN Expressao R_PAREN { 
                if($3->type == MATRIX_KEY){
                    std::cout << "\nIncorrect type for operator ’ABS’ - have MATRIX\n\n";
                    $$ = nullptr;
                }else{
                    float value = 0;
                    int element = $3->element;
                    if($3->element != FUNCTION_KEY) value = abs($3->value);
                    $$ = expressao.CreateSheet($3->type, ABS_KEY, value, $3, element);
                }
            }

Limit: NumFloat {$$ = $1;};
        | ADD NumFloat {$$ = $2;};
        | SUBTRACT NumFloat { $$ = -$2; }
        | NumInt {$$ = $1;};
        | ADD NumInt {$$ = $2;};
        | SUBTRACT NumInt {$$ = -$2;}

Value: NumInt { $$ = expressao.CreateSheet(INT_KEY, OP, $1, nullptr); }; 
    | NumFloat { $$ = expressao.CreateSheet(FLOAT_KEY, OP, $1, nullptr); };
    | L_PAREN Expressao R_PAREN { 
        int element = $2->element;
        $$ = expressao.CreateSheet($2->type, EXP_KEY, $2->value, $2, element) ;};
    | VAR {$$ = expressao.CreateSheet(VAR_KEY, OP, 0, nullptr); }
    | PI { $$ = expressao.CreateSheet(FLOAT_KEY, OP, pi, nullptr); };
    | E  { $$ = expressao.CreateSheet(FLOAT_KEY, OP, euler, nullptr); } ;



NumInt: INT   {
            $$ = $1;
        };

NumFloat: REAL { $$ = $1; };

Bool: ON { $$ = true; }; 
    | OFF { $$ = false; };

%%

void expectedDelaration(){
    std::cout << "\nSYNTAX ERROR: Incomplete Command.\n\n";
}

void syntaxError(){
    std::cout << "\nSYNTAX ERROR: [" << yytext << "]\n\n";   
    stopPrint = true;
}

void yyerror(const void *s) {
    if(!stopPrint){
        if(!isLexico){
            (yychar == EOL)?expectedDelaration():syntaxError(); 
        }
        else{
            isLexico = false;
        }
    }
    undeclared->vetor.clear(); hasUndeclared = false;
}

void PrintUndeclareds(){
    std::cout << "\n";
    for(i = 0; i < undeclared->vetor.size(); i++){
        std::cout << "Undefined symbol [" << undeclared->vetor[i] << "]\n";
    }
    std::cout << "\n";
    undeclared->vetor.clear(); hasUndeclared = false;
};

void clearMemory(){
    if(matrix != nullptr) delete matrix;
    delete undeclared;
    dcmat.DeleteHash();
}

int main(int argc, char **argv) {
    while(1){
        if(!stopPrint)printf("> ");
        yyparse();
    }
    return 0;
}