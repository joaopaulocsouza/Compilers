%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    extern int yylex();
    extern int currentColumn;
    extern int commentLine;
    extern int commentColumn;
    extern int currentSizeWord;
    extern int line;
    extern char* yytext;
    extern int yychar;
    extern void attInput(int line);
    extern int yyleng;
    extern char currentInput[2048];
    void yyerror(char *s);
    bool eof = false;

%}

%token VOID
%token INT
%token CHAR
%token RETURN
%token BREAK
%token SWITCH
%token CASE
%token DEFAULT
%token DO
%token WHILE
%token FOR
%token IF
%token ELSE
%token TYPEDEF
%token STRUCT
%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token REMAINDER
%token INC
%token DEC
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_NOT
%token BITWISE_XOR
%token NOT
%token LOGICAL_AND
%token LOGICAL_OR
%token EQUAL
%token NOT_EQUAL
%token LESS_THAN
%token GREATER_THAN
%token LESS_EQUAL
%token GREATER_EQUAL
%token R_SHIFT
%token L_SHIFT
%token ASSIGN
%token ADD_ASSIGN
%token MINUS_ASSIGN
%token SEMICOLON
%token COMMA
%token COLON
%token L_PAREN
%token R_PAREN
%token L_CURLY_BRACKET
%token R_CURLY_BRACKET
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token TERNARY_CONDITIONAL
%token NUMBER_SIGN
%token POINTER
%token PRINTF
%token SCANF
%token DEFINE
%token EXIT
%token IDENTIFIER
%token NUM_OCTAL
%token NUM_INTEGER
%token NUM_HEXA
%token STRING
%token CHARACTER

%start Programa

%%
Programa: Declaracoes ProgramaLinha 
    | Funcao ProgramaLinha ;

ProgramaLinha: Programa |  ;

Declaracoes: DeclaracoesVaraveis 
    | DeclaracoesDePrototipos 
    | NUMBER_SIGN DEFINE IDENTIFIER Expressao ;

Funcao: Tipo Estrela IDENTIFIER Parametros L_CURLY_BRACKET FuncaoLinha Comandos R_CURLY_BRACKET;

FuncaoLinha: DeclaracoesVaraveis FuncaoLinha 
    |   ;

DeclaracoesVaraveis: Tipo Estrela IDENTIFIER DeclaracoesVaraveisLinha;

DeclaracoesVaraveisLinha: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET DeclaracoesVaraveisLinha 
        |  ASSIGN ExpressaoDeAtribuicao DeclaracoesVaraveisLinha 
        |  COMMA Estrela IDENTIFIER DeclaracoesVaraveisLinha
        |  SEMICOLON ;

DeclaracoesDePrototipos: Tipo Estrela IDENTIFIER Parametros SEMICOLON ;

Parametros: L_PAREN ParametrosLinha;

ParametrosLinha: Tipo Estrela IDENTIFIER ParametrosLinha
        | L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ParametrosLinha
        | COMMA ParametrosLinha
        | R_PAREN ;

Tipo: VOID 
    | CHAR 
    | INT ;

Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET;

Comandos: ListaComandos ComandosLinha;

ComandosLinha: Comandos |  ;

ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON
    |  IF L_PAREN Expressao R_PAREN Bloco ELSE Bloco
    |  IF L_PAREN Expressao R_PAREN Bloco
    |  WHILE L_PAREN Expressao R_PAREN Bloco
    |  FOR L_PAREN ExpressaoLinha SEMICOLON ExpressaoLinha SEMICOLON ExpressaoLinha R_PAREN Bloco
    |  PRINTF L_PAREN STRING COMMA Expressao R_PAREN SEMICOLON
    |  PRINTF L_PAREN STRING R_PAREN SEMICOLON
    |  SCANF L_PAREN STRING COMMA BITWISE_AND IDENTIFIER R_PAREN SEMICOLON
    |  EXIT L_PAREN Expressao R_PAREN SEMICOLON
    |  RETURN ExpressaoLinha SEMICOLON
    |  Expressao SEMICOLON
    |  SEMICOLON
    |  Bloco ;

Expressao: ExpressaoDeAtribuicao 
    | Expressao COMMA ExpressaoDeAtribuicao ;

ExpressaoDeAtribuicao: ExpressaoCondicional 
    | ExpressaoUnaria ASSIGN ExpressaoDeAtribuicao
    | ExpressaoUnaria MINUS_ASSIGN ExpressaoDeAtribuicao
    | ExpressaoUnaria ADD_ASSIGN ExpressaoDeAtribuicao ;

ExpressaoCondicional: ExpressaoORLogico TERNARY_CONDITIONAL Expressao COLON Expressao
    | ExpressaoORLogico ;

ExpressaoORLogico: ExpressaoORLogico LOGICAL_OR ExpressaoANDLogico 
    | ExpressaoANDLogico ;

ExpressaoANDLogico: ExpressaoOR 
    | ExpressaoANDLogico LOGICAL_AND ExpressaoOR ;

ExpressaoOR: ExpressaoXOR 
    | ExpressaoOR BITWISE_OR ExpressaoXOR ;

ExpressaoXOR: ExpressaoAND 
    | ExpressaoXOR BITWISE_XOR ExpressaoAND ;

ExpressaoAND: ExpressaoDeIgualdade 
    | ExpressaoAND BITWISE_AND ExpressaoDeIgualdade ;

ExpressaoDeIgualdade: ExpressaoRelacional 
    | ExpressaoDeIgualdade NOT_EQUAL ExpressaoRelacional
    | ExpressaoDeIgualdade EQUAL ExpressaoRelacional ;

ExpressaoRelacional: ExpressaoShift 
    | ExpressaoRelacional LESS_THAN ExpressaoShift
    | ExpressaoRelacional LESS_EQUAL ExpressaoShift 
    | ExpressaoRelacional GREATER_EQUAL ExpressaoShift
    | ExpressaoRelacional GREATER_THAN ExpressaoShift ;

ExpressaoShift: ExpressaoAditiva 
    | ExpressaoShift R_SHIFT ExpressaoAditiva 
    | ExpressaoShift L_SHIFT ExpressaoAditiva ;

ExpressaoAditiva: ExpressaoMultiplicativa 
    | ExpressaoAditiva MINUS ExpressaoMultiplicativa 
    | ExpressaoAditiva PLUS ExpressaoMultiplicativa ;

ExpressaoMultiplicativa: ExpressaoCast 
    | ExpressaoMultiplicativa MULTIPLY ExpressaoCast
    | ExpressaoMultiplicativa DIV ExpressaoCast 
    | ExpressaoMultiplicativa REMAINDER ExpressaoCast ;

ExpressaoCast: L_PAREN Tipo Estrela R_PAREN ExpressaoCast 
    | ExpressaoUnaria ;

ExpressaoUnaria: INC ExpressaoUnaria 
    | DEC ExpressaoUnaria 
    | BITWISE_NOT ExpressaoCast 
    | NOT ExpressaoCast
    | BITWISE_AND ExpressaoCast 
    | MULTIPLY ExpressaoCast 
    | PLUS ExpressaoCast 
    | MINUS ExpressaoCast 
    | ExpressaoPosFixa;

ExpressaoPosFixa: ExpressaoPrimaria 
    | ExpressaoPosFixa L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET 
    | ExpressaoPosFixa INC 
    | ExpressaoPosFixa DEC 
    | ExpressaoPosFixa L_PAREN ExpressaoDeAtribuicao ExpressaoPosFixaLinha R_PAREN ;
    | ExpressaoPosFixa L_PAREN R_PAREN ;

ExpressaoPosFixaLinha: COMMA ExpressaoDeAtribuicao ExpressaoPosFixaLinha |   ; 

ExpressaoPrimaria: IDENTIFIER 
    | Numero 
    | CHARACTER 
    | STRING 
    | L_PAREN Expressao R_PAREN ;

Numero: NUM_HEXA 
    | NUM_INTEGER 
    | NUM_OCTAL ;

ExpressaoLinha: Expressao 
    |  ;

Estrela: MULTIPLY Estrela |   ;

%%

void expectedDelaration(){
    printf("error:syntax:%d:%d: expected declaration or statement at end of input\n%s\n", line, currentColumn, currentInput);
    exit(0);
}

void syntaxError(){
    int sizeLineBeforeError = currentColumn - currentSizeWord;
    printf("error:syntax:%d:%d: %s\n%s", line, sizeLineBeforeError, yytext, currentInput);
    while(sizeLineBeforeError > 1){
        printf(" ");
        sizeLineBeforeError--;
    };
    printf("^");
    exit(0);
}

void yyerror(char *s) {

    attInput(line);

    (yychar == 0)?expectedDelaration():syntaxError();
}

int main(int argc, char **argv) {
    yyparse();
	printf("SUCCESSFUL COMPILATION.");
    return 0;
}