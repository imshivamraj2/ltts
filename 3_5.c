#include <stdio.h>

void findSmallestLargestDigits(int numbers[], int size) {
    int smallestDigit = 9;
    int largestDigit = 0;

    for (int i = 0; i < size; i++) {
        int num = numbers[i];

        while (num != 0) {
            int digit = num % 10;

            if (digit < smallestDigit) {
                smallestDigit = digit;
            }

            if (digit > largestDigit) {
                largestDigit = digit;
            }

            num /= 10;
        }
    }

    printf("Smallest Digit: %d\n", smallestDigit);
    printf("Largest Digit: %d\n", largestDigit);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int numbers[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    findSmallestLargestDigits(numbers, n);

    return 0;
}