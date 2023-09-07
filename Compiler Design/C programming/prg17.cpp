#include <stdio.h>

int main() {
    int x = 5;
    int y = 10;
    int z = 0;

    if (x > y) {
        z = x + y;
    } else {
        z = x - y;
    }

    if (z < 0) {
        printf("z is negative.\n");
    } else {
        printf("z is non-negative.\n");
    }

    return 0;
}

