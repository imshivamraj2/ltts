#include <stdio.h>

// Function to swap two values of any type
void swap(void* a, void* b, size_t size) {
    unsigned char* p = (unsigned char*)a;
    unsigned char* q = (unsigned char*)b;
    
    for (size_t i = 0; i < size; i++) {
        unsigned char temp = p[i];
        p[i] = q[i];
        q[i] = temp;
    }
}

int main() {
    int num1 = 10, num2 = 20;
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2, sizeof(int));
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    
    double d1 = 3.14, d2 = 1.23;
    printf("Before swapping: d1 = %lf, d2 = %lf\n", d1, d2);
    swap(&d1, &d2, sizeof(double));
    printf("After swapping: d1 = %lf, d2 = %lf\n", d1, d2);
    
    char c1 = 'A', c2 = 'B';
    printf("Before swapping: c1 = %c, c2 = %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("After swapping: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}