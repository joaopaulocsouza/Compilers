%option noyywrap
%%
" "  { printf("white space\n"); }
"-" {printf("error\n");}
"--"[a-z]* {printf("%s comment\n", yytext); }
[0-9]+ {printf("%s NUM\n", yytext); }
[0-9]+"."[0-9]* {printf("%s REAL\n", yytext); }
"." {printf("%s error", yytext); }
"."[0-9]+ {printf("%s REAL\n", yytext); }
"i" {printf("%s ID\n", yytext); }
"i"[a-e | g-z | 0-9][a-z0-9]* {printf("%s ID\n", yytext); }
[a-h | j-z][a-z0-9]* {printf("%s ID\n", yytext); }
"if" {printf("%s IF\n", yytext);}
"if"[0-9 | a-z][a-z0-9]* {printf("%s ID\n", yytext);}
[\n\r | \n] {}

. {printf("%s error\n", yytext); }
%%
int main(){
    yylex();
    return 0;
}
