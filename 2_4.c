#include <stdio.h>

// Function to count the number of set bits in a given number
int countSetBits(int num) {
    int count = 0;
    
    while (num != 0) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }
    
    return count;
}

int main() {
    int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);
    int totalBits = 0;
    
    for (int i = 0; i < size; i++) {
        totalBits += countSetBits(arr[i]);
    }
    
    printf("Total number of set bits in the given array: %d\n", totalBits);

    return 0;
}