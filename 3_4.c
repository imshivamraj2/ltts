#include <stdio.h>

int deleteDigitAndGetLargest(int num) {
    int largest = 0;
    int temp = num;

    for (int i = 0; i < 4; i++) {
        int divisor = 1;
        int digitToDelete = (temp % (divisor * 10)) / divisor;
        int remainingNum = (temp / (divisor * 10)) * divisor + (temp % divisor);

        if (remainingNum > largest) {
            largest = remainingNum;
        }

        temp = num;
        divisor *= 10;
    }

    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largest = deleteDigitAndGetLargest(num);

    printf("The largest number by deleting a single digit: %d\n", largest);

    return 0;
}