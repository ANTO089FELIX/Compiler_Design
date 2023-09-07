#include <stdio.h>
#include <string.h>

typedef struct {
    char var;
    char op1;
    char operator;
    char op2;
} Subexpression;

void eliminateSubexpression(Subexpression* subexp, char tempVar) {
    printf("%c = %c %c %c\n", tempVar, subexp->op1, subexp->operator, subexp->op2);
    subexp->op1 = tempVar;
    subexp->operator = '=';
    subexp->op2 = '_';
}

int main() {
    char expression[] = "a + b * c + a * b";

    Subexpression subexpressions[100];  // Array to store subexpressions
    int subexpCount = 0;                // Subexpression counter
    char tempVar = 't';                 // Temporary variable counter

    for (int i = 0; i < strlen(expression) - 2; i++) {
        if (expression[i + 1] == '+' || expression[i + 1] == '*') {
            subexpressions[subexpCount++] = (Subexpression){expression[i], expression[i + 2], expression[i + 1], expression[i + 4]};
        }
    }

    printf("Original Expression: %s\n", expression);
    printf("Optimized Expression:\n");

    for (int i = 0; i < strlen(expression) - 2; i++) {
        bool replaced = false;
        for (int j = 0; j < subexpCount; j++) {
            if (expression[i] == subexpressions[j].var &&
                expression[i + 1] == subexpressions[j].operator &&
                expression[i + 2] == subexpressions[j].op2) {
                eliminateSubexpression(&subexpressions[j], tempVar);
                printf("%c %c %c ", expression[i], subexpressions[j].operator, subexpressions[j].op2);
                tempVar++;
                replaced = true;
                break;
            }
        }
        if (!replaced) {
            printf("%c ", expression[i]);
        }
    }

    printf("\n");

    return 0;
}

