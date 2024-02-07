
/*
Name : Harish Thangaraj
Reg_no: 21BRS1033
Slot: L45+L46 
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

// Function to classify the type of token
const char* classify_token(const char *token) {
    // Check if the token is a keyword
    const char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return "Keyword";
        }
    }

    // Check if the token is an identifier
    if (isalpha(token[0]) || token[0] == '_') {
        return "Identifier";
    }

    // Check if the token is a constant (for simplicity, we'll consider integers as constants)
    int valid_constant = 1;
    for (int i = 0; i < strlen(token); i++) {
        if (!isdigit(token[i])) {
            valid_constant = 0;
            break;
        }
    }
    if (valid_constant) {
        return "Constant";
    }

    // Check if the token is an operator or special symbol
    const char *operators[] = {"+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>", "++", "--", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", "->", ".", "->*", ".", ",", ":", "?", "::"};
    for (int i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
        if (strcmp(token, operators[i]) == 0) {
            return "Operator/Special Symbol";
        }
    }

    // If none of the above conditions match, classify the token as "Unknown"
    return "Unknown";
}

// Function to identify tokens from a statement and store them in an array
void identify_tokens(const char *statement, char tokens[][MAX_TOKEN_LENGTH], char types[][20], int *num_tokens) {
    char *token;
    char copy[strlen(statement) + 1]; // Create a copy of the statement to avoid modifying the original string
    strcpy(copy, statement);

    // Tokenize the statement using strtok
    token = strtok(copy, " ");
    while (token != NULL) {
        // Copy each token into the tokens array
        strcpy(tokens[*num_tokens], token);
        // Classify the token
        strcpy(types[*num_tokens], classify_token(token));
        (*num_tokens)++;

        // Get the next token
        token = strtok(NULL, " ");
    }
}

int main() {
    char statement[MAX_TOKEN_LENGTH * MAX_TOKENS];
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];
    char types[MAX_TOKENS][20];
    int num_tokens = 0;

    // Input a statement
    printf("Enter a statement: ");
    fgets(statement, sizeof(statement), stdin);

    // Remove newline character from input
    if (statement[strlen(statement) - 1] == '\n') {
        statement[strlen(statement) - 1] = '\0';
    }

    // Identify tokens and store them in the tokens array
    identify_tokens(statement, tokens, types, &num_tokens);

    // Print the tokens and their types
    printf("Tokens and their types:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i], types[i]);
    }

    return 0;
}
