%option noyywrap
%{
#include <stdio.h>
#include <stdbool.h>

int line = 1;
int currentColumn = 1;
bool flag = false;
int commentLine = 0;
int commentColumn = 0;

void VerifyBrokenLine();
void ReplaceString(char *string, int length, char *command);

%}

%x COMMENT_MULTIPLE_LINES

%%
<INITIAL>{
"void" {VerifyBrokenLine(); printf("VOID"); currentColumn += yyleng;}
"int" {VerifyBrokenLine(); printf("INT"); currentColumn += yyleng;}
"char" {VerifyBrokenLine(); printf("CHAR"); currentColumn += yyleng;}
"return" {VerifyBrokenLine(); printf("RETURN"); currentColumn += yyleng;}
"switch" {VerifyBrokenLine(); printf("SWITCH"); currentColumn += yyleng;}
"default" {VerifyBrokenLine(); printf("DEFAULT"); currentColumn += yyleng;}
"break" {VerifyBrokenLine(); printf("BREAK"); currentColumn += yyleng;}
"case" {VerifyBrokenLine(); printf("CASE"); currentColumn += yyleng;}
"do" {VerifyBrokenLine(); printf("DO"); currentColumn += yyleng;}
"while" {VerifyBrokenLine(); printf("WHILE"); currentColumn += yyleng;}
"for" {VerifyBrokenLine(); printf("FOR"); currentColumn += yyleng;}
"if" {VerifyBrokenLine(); printf("IF"); currentColumn += yyleng;}
"else" {VerifyBrokenLine(); printf("ELSE"); currentColumn += yyleng;}
"typedef" {VerifyBrokenLine(); printf("TYPEDEF"); currentColumn += yyleng;}
"struct" {VerifyBrokenLine(); printf("STRUCT"); currentColumn += yyleng;}
\"([^\\\"]|\\.)*\" {ReplaceString(yytext, yyleng, "STRING"); currentColumn += yyleng;}
"\'"(\\.|[^"\\\n])"\'" {ReplaceString(yytext, yyleng, "CHARACTER"); currentColumn += yyleng;}
"+" {VerifyBrokenLine(); printf("PLUS"); currentColumn += yyleng;}
"-" {VerifyBrokenLine(); printf("MINUS"); currentColumn += yyleng;}
"*" {VerifyBrokenLine(); printf("MULTIPLY"); currentColumn += yyleng;}
"/" {VerifyBrokenLine(); printf("DIV"); currentColumn += yyleng;}
"%" {VerifyBrokenLine(); printf("REMAINDER"); currentColumn += yyleng;}
"++" {VerifyBrokenLine(); printf("INC"); currentColumn += yyleng;}
"--" {VerifyBrokenLine(); printf("DEC"); currentColumn += yyleng;}
"&" {VerifyBrokenLine(); printf("BITWISE_AND"); currentColumn += yyleng;}
"|" {VerifyBrokenLine(); printf("BITWISE_OR"); currentColumn += yyleng;}
"~" {VerifyBrokenLine(); printf("BITWISE_NOT"); currentColumn += yyleng;}
"^" {VerifyBrokenLine(); printf("BITWISE_XOR"); currentColumn += yyleng;}
"!" {VerifyBrokenLine(); printf("NOT"); currentColumn += yyleng;}
"&&" {VerifyBrokenLine(); printf("LOGICAL_AND"); currentColumn += yyleng;}
"||" {VerifyBrokenLine(); printf("LOGICAL_OR"); currentColumn += yyleng;}
"==" {VerifyBrokenLine(); printf("EQUAL"); currentColumn += yyleng;}
"!=" {VerifyBrokenLine(); printf("NOT_EQUAL"); currentColumn += yyleng;}
"<" {VerifyBrokenLine(); printf("LESS_THAN"); currentColumn += yyleng;}
">" {VerifyBrokenLine(); printf("GREATER_THAN"); currentColumn += yyleng;}
"<=" {VerifyBrokenLine(); printf("LESS_EQUAL"); currentColumn += yyleng;}
">=" {VerifyBrokenLine(); printf("GREATER_EQUAL"); currentColumn += yyleng;}
">>" {VerifyBrokenLine(); printf("R_SHIFT"); currentColumn += yyleng;}
"<<" {VerifyBrokenLine(); printf("L_SHIFT"); currentColumn += yyleng;}
"=" {VerifyBrokenLine(); printf("ASSIGN"); currentColumn += yyleng;}
"+=" {VerifyBrokenLine(); printf("ADD_ASSIGN"); currentColumn += yyleng;}
"-=" {VerifyBrokenLine(); printf("MINUS_ASSIGN"); currentColumn += yyleng;}
";" {VerifyBrokenLine(); printf("SEMICOLON"); currentColumn += yyleng;}
"," {VerifyBrokenLine(); printf("COMMA"); currentColumn += yyleng;}
":" {VerifyBrokenLine(); printf("COLON"); currentColumn += yyleng;}
"(" {VerifyBrokenLine(); printf("L_PAREN"); currentColumn += yyleng;}
")" {VerifyBrokenLine(); printf("R_PAREN"); currentColumn += yyleng;}
"{" {VerifyBrokenLine(); printf("L_CURLY_BRACKET"); currentColumn += yyleng;}
"}" {VerifyBrokenLine(); printf("R_CURLY_BRACKET"); currentColumn += yyleng;}
"[" {VerifyBrokenLine(); printf("L_SQUARE_BRACKET"); currentColumn += yyleng;}
"]" {VerifyBrokenLine(); printf("R_SQUARE_BRACKET"); currentColumn += yyleng;}
"?" {VerifyBrokenLine(); printf("TERNARY_CONDITIONAL"); currentColumn += yyleng;}
"#" {VerifyBrokenLine(); printf("NUMBER_SIGN"); currentColumn += yyleng;}
"->" {VerifyBrokenLine(); printf("POINTER"); currentColumn += yyleng;}
"printf" {VerifyBrokenLine(); printf("PRINTF"); currentColumn += yyleng;}
"scanf" {VerifyBrokenLine(); printf("SCANF"); currentColumn += yyleng;}
"define" {VerifyBrokenLine(); printf("DEFINE"); currentColumn += yyleng;}
"exit" {VerifyBrokenLine(); printf("EXIT"); currentColumn += yyleng;}
"0"(x|X)[0-9a-fA-F]+ {VerifyBrokenLine(); printf("NUM_HEXA(%s)", yytext); currentColumn += yyleng;}
"0"[1-7]+[0-7]* {VerifyBrokenLine(); printf("NUM_OCTAL(%s)", yytext); currentColumn += yyleng;}
[0-9]+ {VerifyBrokenLine(); printf("NUM_INTEGER(%s)", yytext); currentColumn += yyleng;}
[_|A-Z|a-z][a-zA-Z0-9_]* {VerifyBrokenLine(); yyleng <= 255?printf("IDENTIFIER(%s)", yytext):printf("error:lexical:%d:%d: identifier too long", line, currentColumn); currentColumn += yyleng;}
"/*" {BEGIN(COMMENT_MULTIPLE_LINES); commentColumn = currentColumn; commentLine = line; currentColumn += yyleng;}
"\a" {currentColumn += yyleng;}
"\b" {currentColumn += yyleng;}
"\f" {currentColumn += yyleng;}
"\r" {currentColumn += yyleng;}
"\t" {currentColumn += yyleng;}
"\\" {currentColumn += yyleng;}
"\v" {currentColumn += yyleng;}
"\'" {currentColumn += yyleng;}
"\?" {currentColumn += yyleng;}
"\0" {currentColumn += yyleng;}
"\"" {currentColumn += yyleng;}
[\n] {line++; currentColumn = 1;}
"//".* 
[ ]  {currentColumn++;} 
[/t ]  {currentColumn++;} 
. {VerifyBrokenLine(); printf("error:lexical:%d:%d: %s", line, currentColumn, yytext); currentColumn += yyleng;}
}

<COMMENT_MULTIPLE_LINES>[/]*"*/" {BEGIN(INITIAL); currentColumn += yyleng;}
<COMMENT_MULTIPLE_LINES>"/*" {VerifyBrokenLine(); printf("warning:%d:%d: '/*' within block comment", line, currentColumn); currentColumn += yyleng;}
<COMMENT_MULTIPLE_LINES>[\n] {line++; currentColumn = 1;}
<COMMENT_MULTIPLE_LINES>[/t ]  {currentColumn += yyleng;} 
<COMMENT_MULTIPLE_LINES><<EOF>>  {BEGIN(INITIAL); VerifyBrokenLine(); printf("error:lexical:%d:%d: unterminated comment", commentLine, commentColumn); currentColumn += yyleng;} 
<COMMENT_MULTIPLE_LINES>. {currentColumn += yyleng;}

%%
void VerifyBrokenLine() {
    if(flag == true){
        printf("\n");
    }else{
        flag = true;
    }
}

void ReplaceString(char *string, int length, char *command){
    if (length >= 2) {
        for (int i = 0; i < length - 1; i++) {
            string[i] = string[i + 1];
        }
        string[length - 1] = '\0';
        string[length - 2] = '\0';
    } 
    else {
        string[0] = '\0';
    }
    VerifyBrokenLine();
    printf("%s(%s)",command, string);

}

int main(){
    yylex();
    return 0;
}
