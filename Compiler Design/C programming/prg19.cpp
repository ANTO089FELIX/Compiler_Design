#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Production structure
typedef struct {
    char lhs;
    char rhs[10];
} Production;

// Grammar rules
Production productions[] = {
    {'S', "E"},
    {'E', "E+T"},
    {'E', "T"},
    {'T', "T*F"},
    {'T', "F"},
    {'F', "(E)"},
    {'F', "id"}
};

char terminals[] = {'+', '*', '(', ')', 'id', '$'};
char nonTerminals[] = {'S', 'E', 'T', 'F'};
char parsingTable[5][6][10] = {
    {"S->E", "", "", "S->E", "", ""},
    {"", "E->T+E", "", "", "E->T", ""},
    {"T->F", "", "T->F", "", "", "T->F"},
    {"", "F->id", "", "", "F->(E)", ""},
    {"", "", "", "acc", "", ""}
};

bool isTerminal(char symbol) {
    for (int i = 0; i < 6; i++) {
        if (terminals[i] == symbol) {
            return true;
        }
    }
    return false;
}

int getTerminalIndex(char symbol) {
    for (int i = 0; i < 6; i++) {
        if (terminals[i] == symbol) {
            return i;
        }
    }
    return -1;
}

int getNonTerminalIndex(char symbol) {
    for (int i = 0; i < 4; i++) {
        if (nonTerminals[i] == symbol) {
            return i;
        }
    }
    return -1;
}

void parseInput(char input[]) {
    char stack[100];
    int top = -1;
    stack[++top] = '$';
    stack[++top] = 'S';
    int inputIndex = 0;

    while (top >= 0) {
        char X = stack[top];
        char a = input[inputIndex];

        if (isTerminal(X)) {
            if (X == a) {
                top--;
                inputIndex++;
            } else {
                printf("Error: Mismatch between %c and %c\n", X, a);
                return;
            }
        } else {
            int i = getNonTerminalIndex(X);
            int j = getTerminalIndex(a);

            if (i != -1 && j != -1) {
                if (strcmp(parsingTable[i][j], "") != 0) {
                    top--;

                    char production[10];
                    strcpy(production, parsingTable[i][j]);

                    for (int k = strlen(production) - 1; k >= 3; k--) {
                        stack[++top] = production[k];
                    }
                } else {
                    printf("Error: No production found for %c and %c\n", X, a);
                    return;
                }
            } else {
                printf("Error: Invalid symbol %c or %c\n", X, a);
                return;
            }
        }
    }

    printf("Input parsed successfully!\n");
}

int main() {
    char input[] = "id+id*id$"; // Replace with your input

    parseInput(input);

    return 0;
}

