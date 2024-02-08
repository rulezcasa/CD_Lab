%{
#include <stdio.h>
%}

%%
[0-9]+          { printf("NUMBER: %s\n", yytext); }
[a-zA-Z]+       { printf("WORD: %s\n", yytext); }
[ \t\n]         { /* ignore whitespace */ }
.               { printf("UNKNOWN: %s\n", yytext); }
%%

int yywrap() {
    return 1;  // Indicate that there are no more input streams
}

int main() {
    yylex();
    return 0;
}
