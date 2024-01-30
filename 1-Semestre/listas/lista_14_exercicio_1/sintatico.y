%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int yylex();
void yyerror(const char *s);

%}



%union {
    int intval;
    double floatval;
    char *strval;
}

%type <intval> expression factor
%type <floatval> term primary
%token <intval> INT
%token <floatval> REAL
%token <strval> VAR
%token ADD SUB MUL DIV POW MOD
%token LPAREN RPAREN
%token SIN COS TAN ABS

%left '+' '-'
%left '*' '/'
%left '^'
%left UMINUS

%start calclist

%%

calclist: 
     | calclist line
     ;

line: expression '\n' { printf("EXPRESSAO CORRETA\n"); }
    ;


expression: term
          | expression ADD term { $$ = $1 + $3; }
          | expression SUB term { $$ = $1 - $3; }
          ;

term: factor
    | term MUL factor { $$ = $1 * $3; }
    | term DIV factor { $$ = $1 / $3; }
    ;

factor: primary
      | factor POW primary { $$ = pow($1, $3); }
      ;

primary: INT { $$ = $1; }
       | REAL { $$ = $1; }
       | VAR { /* Implementar a lógica para variáveis */ }
       | SIN LPAREN expression RPAREN { $$ = sin($3); }
       | COS LPAREN expression RPAREN { $$ = cos($3); }
       | TAN LPAREN expression RPAREN { $$ = tan($3); }
       | ABS LPAREN expression RPAREN { $$ = fabs($3); }
       | LPAREN expression RPAREN { $$ = $2; }
       | SUB primary %prec UMINUS { $$ = -$2; }
       ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
}

int main() {
    yyparse();
    return 0;
}
