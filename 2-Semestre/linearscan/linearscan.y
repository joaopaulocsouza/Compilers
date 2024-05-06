%{
    #include <iostream>
    #include <string.h>
    #include <stdbool.h>
    #include <vector>
    #include <stack>
    #include "linearscan.hpp"

    int i, j;

    extern int yylex();
    extern char* yytext;
    void yyerror(std::string s);

    LinearScan* linearScan = new LinearScan();

%}

%union {
    int integer;
    char* s;
}

%token <integer> INT;
%token K;
%token <s>ID;
%token EQUAL;
%token ARROW;
%token EOL;

%type <integer> Value;

%start LinearScan

%%

LinearScan: K EQUAL Value EOL Content{linearScan->k = $3;}

Content: Register EOL Content {}
        | Register {}

Register: ID ARROW Value Value {linearScan->addRegister($1, $3, $4);}

Value: INT { $$ = $1; }
%%

void yyerror(std::string s) {
    std::cout << "Error: " << s << std::endl;
}

int main(int argc, char **argv){
    yyparse();

    for(i = linearScan->k; i > 1; i--){
        linearScan->alloc(i);
    }

    std::cout << "----------------------------------------";
    for(auto result : linearScan->results){
        std::cout << "\nK = " << result.k << ": ";
        if(result.spill){
            std::cout << "SPILL on interation(s): " << result.iterations[0];
            for(int i = 1; i < result.iterations.size(); i++){
                std::cout << ", " << result.iterations[i];
            }
            continue;
        }
        std::cout << "Successful Allocation";
    }

    linearScan->deleteRegisters();
    delete linearScan;
    
    return 0;
}