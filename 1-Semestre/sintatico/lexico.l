%option noyywrap
%{
    #include "sintatico.tab.h"
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>

    int line = 1;
    bool flag = false;
    int currentColumn = 1;
    int currentSizeWord = 0;
    int commentColumn = 0;
    int commentLine = 0;
    char currentInput[2048];
    bool verifyID(int sizeId);
    void attInput(int line);
    extern bool eof;

%}

%x COMMENT_MULTIPLE_LINES

%%
<INITIAL>{
"void" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return VOID;}
"int" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return INT;}
"char" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return CHAR;}
"return" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return RETURN;}
"switch" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return SWITCH;}
"default" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return DEFAULT;}
"break" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return BREAK;}
"case" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return CASE;}
"do" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return DO;}
"while" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return WHILE;}
"for" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return FOR;}
"if" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return IF;}
"else" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return ELSE;}
"typedef" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return TYPEDEF;}
"struct" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return STRUCT;}
\"([^\\\"]|\\.)*\" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return STRING;}
"\'"(\\.|[^"\\\n])"\'" {currentSizeWord = yyleng; currentColumn += yyleng; return CHARACTER;}
"+" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return PLUS;}
"-" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return MINUS;}
"*" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return MULTIPLY;}
"/" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return DIV;}
"%" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return REMAINDER;}
"++" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return INC;}
"--" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return DEC;}
"&" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return BITWISE_AND;}
"|" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return BITWISE_OR;}
"~" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return BITWISE_NOT;}
"^" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return BITWISE_XOR;}
"!" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return NOT;}
"&&" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return LOGICAL_AND;}
"||" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return LOGICAL_OR;}
"==" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return EQUAL;}
"!=" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return NOT_EQUAL;}
"<" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return LESS_THAN;}
">" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return GREATER_THAN;}
"<=" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return LESS_EQUAL;}
">=" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return GREATER_EQUAL;}
">>" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return R_SHIFT;}
"<<" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return L_SHIFT;}
"=" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return ASSIGN;}
"+=" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return ADD_ASSIGN;}
"-=" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return MINUS_ASSIGN;}
";" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return SEMICOLON;}
"," {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return COMMA;}
":" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return COLON;}
"(" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return L_PAREN;}
")" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return R_PAREN;}
"{" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return L_CURLY_BRACKET;}
"}" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return R_CURLY_BRACKET;}
"[" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return L_SQUARE_BRACKET;}
"]" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return R_SQUARE_BRACKET;}
"\?" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return TERNARY_CONDITIONAL;}
"#" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return NUMBER_SIGN;}
"->" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return POINTER;}
"printf" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return PRINTF;}
"scanf" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return SCANF;}
"define" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return DEFINE;}
"exit" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return EXIT;}
"0"(x|X)[0-9a-fA-F]+ {currentSizeWord = yyleng; currentColumn += yyleng; return NUM_HEXA;}
"0"[1-7]+[0-7]* {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return NUM_OCTAL;}
[0-9]+ {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; return NUM_INTEGER;}
[_|A-Z|a-z][a-zA-Z0-9_]* { currentSizeWord = yyleng; currentColumn += yyleng; verifyID(yyleng); return IDENTIFIER; }
"/*" {BEGIN(COMMENT_MULTIPLE_LINES); commentColumn = currentColumn; commentLine = line; currentColumn += yyleng;}
"\a" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}
"\b" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}
"\f" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}
"\r" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}
"\t" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}
"\\" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}
"\v" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}
"\'" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}
"\0" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng; eof = true;}
"\"" {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}
[\n] {strcpy(currentInput, "");line++; currentColumn = 1; currentSizeWord = 0;}
"//".* 
[ ]  {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn++;} 
. {printf("error:lexical:%d:%d: %s", line, currentColumn, yytext); currentColumn += yyleng; exit(0);}
}

<COMMENT_MULTIPLE_LINES>[/]*"*/" {BEGIN(INITIAL); currentColumn += yyleng;}
<COMMENT_MULTIPLE_LINES>"/*" {printf("warning:%d:%d: '/*' within block comment\n", line, currentColumn); currentColumn += yyleng;}
<COMMENT_MULTIPLE_LINES>[\n] {line++; currentColumn = 1;}
<COMMENT_MULTIPLE_LINES>[/t ]  {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;} 
<COMMENT_MULTIPLE_LINES><<EOF>>  {BEGIN(INITIAL); printf("error:lexical:%d:%d: unterminated comment", commentLine, commentColumn); currentColumn += yyleng; exit(0);} 
<COMMENT_MULTIPLE_LINES>. {strcpy(currentInput, yytext); currentSizeWord = yyleng; currentColumn += yyleng;}

%%

bool verifyID(int sizeId) {
    if(sizeId > 255){
        printf("error:lexical:%d:%d: identifier too long", line, currentColumn);
        exit(0);
    }
    return true;
}

void attInput(int line) {
    fseek(stdin, 0, SEEK_SET);
    for(int i = 0; i < line; i++) {
        fgets(currentInput, 2000, stdin);
    }
}