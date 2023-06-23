#include <stdio.h>

void printBits(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        unsigned int mask = 1 << i;
        unsigned int bit = (num & mask) ? 1 : 0;
        printf("%u", bit);
    }
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits representation: ");
    printBits(num);
    printf("\n");

    return 0;
}