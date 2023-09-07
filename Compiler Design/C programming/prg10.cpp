#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char op;
    char arg1;
    char arg2;
    char result;
} Quadruple;

void generateQuadruple(char op, char arg1, char arg2, char result) {
    printf("(%c, %c, %c, %c)\n", op, arg1, arg2, result);
}

int main() {
    Quadruple quadruples[100];  // Array to store quadruples
    int quadCount = 0;          // Quadruple counter

    // Generate some sample quadruples
    quadruples[quadCount++] = (Quadruple) {'+', 'a', 'b', 't'};
    quadruples[quadCount++] = (Quadruple) {'*', 't', 'c', 'x'};
    quadruples[quadCount++] = (Quadruple) {'=', 'x', '_', 'y'};

    // Print generated quadruples
    printf("Generated Quadruples:\n");
    for (int i = 0; i < quadCount; i++) {
        printf("%d: ", i);
        generateQuadruple(quadruples[i].op, quadruples[i].arg1, quadruples[i].arg2, quadruples[i].result);
    }

    return 0;
}

