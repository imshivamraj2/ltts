#include <stdio.h>
#include <stdint.h>

void printExponent(double num)
{
    // Extracting the exponent part of the double variable
    uint64_t bits = *(uint64_t*)&num;
    uint16_t exponent = (bits >> 52) & 0x7FF;

    // Printing the exponent in hexadecimal format
    printf("Exponent (Hex): 0x%03X\n", exponent);

    // Printing the exponent in binary format
    printf("Exponent (Binary): ");
    for (int i = 10; i >= 0; i--) {
        int bit = (exponent >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main()
{
    double number; 

    printf("Enter a number: ");
    scanf("%lf", &number);
    
    printf("Number: %lf\n", number);
    printExponent(number);

    return 0;
}