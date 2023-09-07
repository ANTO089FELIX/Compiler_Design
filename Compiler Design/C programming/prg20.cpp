#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char lhs;
    char rhs[10];
} Production;

Production productions[] = {
    {'S', "aSb"},
    {'S', "ab"}
};

int numProductions = sizeof(productions) / sizeof(productions[0]);

bool isAmbiguous() {
    for (int i = 0; i < numProductions; i++) {
        for (int j = i + 1; j < numProductions; j++) {
            if (strcmp(productions[i].rhs, productions[j].rhs) == 0) {
                printf("Ambiguity detected:\n");
                printf("Production %c -> %s\n", productions[i].lhs, productions[i].rhs);
                printf("Production %c -> %s\n", productions[j].lhs, productions[j].rhs);
                return true;
            }
        }
    }
    return false;
}

int main() {
    if (isAmbiguous()) {
        printf("The grammar is ambiguous.\n");
    } else {
        printf("The grammar is not ambiguous.\n");
    }

    return 0;
}

