%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    extern int yylex();
    extern char* yytext;
    void yyerror(char *s);
    int maxRegisters;
%}

%union {
    int i;
    char* s;
}

%token <i> INT;
%token K;
%token <s>GRAFO;
%token EQUAL;
%token ARROW;
%token COLON;
%token EOL;

%start Regalloc

%%
    Regalloc: GRAFO INT COLON EOL Def EOL

    Def: K EQUAL INT {maxRegisters = atoi(yytext); return(0);}
%%

void yyerror(char *s) {
    printf("Error: %s\n", s);
}

int main(int argc, char **argv){
    yyparse();
    printf("Parsing complete -  Registradores: %d\n", maxRegisters);
    return 0;
}