#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NUM_NON_TERMINALS 2
#define NUM_TERMINALS 2
#define NUM_PRODUCTIONS 3

enum NonTerminals {
    E, T
};

enum Terminals {
    PLUS, NUM
};

char nonTerminals[NUM_NON_TERMINALS] = {'E', 'T'};
char terminals[NUM_TERMINALS] = {'+', 'n'};

char parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS][NUM_PRODUCTIONS][10] = {
    {{"T+E", ""}, {"", ""}},
    {{ "", ""}, {"", "n"}}
};

bool isNonTerminal(char symbol) {
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        if (nonTerminals[i] == symbol) {
            return true;
        }
    }
    return false;
}

int getNonTerminalIndex(char symbol) {
    for (int i = 0; i < NUM_NON_TERMINALS; i++) {
        if (nonTerminals[i] == symbol) {
            return i;
        }
    }
    return -1;
}

int getTerminalIndex(char symbol) {
    for (int i = 0; i < NUM_TERMINALS; i++) {
        if (terminals[i] == symbol) {
            return i;
        }
    }
    return -1;
}

int main() {
    char input[] = "n+n";

    int stack[100]; // Stack to simulate the parsing process
    int top = -1;    // Top of the stack

    stack[++top] = '$'; // Push the end marker onto the stack
    stack[++top] = nonTerminals[0]; // Push the start symbol onto the stack

    int inputIndex = 0;
    char X = stack[top]; // Current symbol at the top of the stack

    while (X != '$') {
        if (!isNonTerminal(X)) {
            if (X == input[inputIndex]) {
                top--;
                inputIndex++;
            } else {
                printf("Error: Mismatch between %c and %c\n", X, input[inputIndex]);
                return 1;
            }
        } else {
            int i = getNonTerminalIndex(X);
            int j = getTerminalIndex(input[inputIndex]);
            if (i != -1 && j != -1) {
                if (strlen(parsingTable[i][j][0]) > 0) {
                    top--;
                    char production[10];
                    strcpy(production, parsingTable[i][j][0]);

                    for (int k = strlen(production) - 1; k >= 0; k--) {
                        if (production[k] != 'e') { // 'e' represents epsilon
                            stack[++top] = production[k];
                        }
                    }
                } else {
                    printf("Error: No production found for %c and %c\n", X, input[inputIndex]);
                    return 1;
                }
            } else {
                printf("Error: Invalid symbol %c or %c\n", X, input[inputIndex]);
                return 1;
            }
        }
        X = stack[top];
    }

    printf("Input parsed successfully!\n");
    return 0;
}

