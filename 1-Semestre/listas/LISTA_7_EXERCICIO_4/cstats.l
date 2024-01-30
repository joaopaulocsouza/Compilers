%{
#include <stdio.h>

int total_lines = 0;
int blank_lines = 0;
int lines_with_comments = 0;
int non_blank_non_comment_lines = 0;
int semicolons_count = 0;
int preproc_direct_count = 0;
%}

%option noyywrap

%{
int in_comment = 0;
int in_single_line_comment = 0;
%}

%%

[\t ]+            /* Ignore tabs and spaces */
\n                { total_lines++; blank_lines++; }
[^\n]+            { total_lines++; non_blank_non_comment_lines++; }

"/*"              { in_comment = 1; lines_with_comments++; }
<comment>"*/"     { in_comment = 0; }
<comment>\n       { lines_with_comments++; }
<comment>.        { /* Ignore characters within comments */ }

"//"              { in_single_line_comment = 1; lines_with_comments++; }
<single_line_comment>\n { in_single_line_comment = 0; lines_with_comments++; }
<single_line_comment>.  { /* Ignore characters within single-line comments */ }

";"               { semicolons_count++; }
"#"               { preproc_direct_count++; }

%%

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s arquivo.c [arquivo2.c ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        if (file == NULL) {
            fprintf(stderr, "Erro ao abrir o arquivo %s\n", argv[i]);
            continue;
        }

        total_lines = 0;
        blank_lines = 0;
        lines_with_comments = 0;
        non_blank_non_comment_lines = 0;
        semicolons_count = 0;
        preproc_direct_count = 0;

        in_comment = 0;
        in_single_line_comment = 0;

        yyin = file;
        yylex();

        printf("%d %d %d %d %d %d %s\n", total_lines, blank_lines, lines_with_comments, non_blank_non_comment_lines, semicolons_count, preproc_direct_count, argv[i]);

        fclose(file);
    }

    return 0;
}
