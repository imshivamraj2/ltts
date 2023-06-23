#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

// Function to read a complex number
void readComplex(struct Complex* c) {
    printf("Enter the real part: ");
    scanf("%f", &(c->real));
    printf("Enter the imaginary part: ");
    scanf("%f", &(c->imaginary));
}

// Function to write a complex number
void writeComplex(struct Complex c) {
    printf("%.2f + %.2fi\n", c.real, c.imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
    result.imaginary = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&num1);

    printf("Enter the second complex number:\n");
    readComplex(&num2);

    printf("\nFirst complex number: ");
    writeComplex(num1);

    printf("Second complex number: ");
    writeComplex(num2);

    sum = addComplex(num1, num2);
    printf("\nSum of the complex numbers: ");
    writeComplex(sum);

    product = multiplyComplex(num1, num2);
    printf("Product of the complex numbers: ");
    writeComplex(product);

    return 0;
}
