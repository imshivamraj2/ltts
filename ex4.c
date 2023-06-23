#include <stdio.h>

int main()
{
    int n1, n2;
    char op;
    
    printf("enter first number: ");
    scanf("%d", &n1);
    
    printf("enter operand(+, -, *, /): ");
    getchar();
    scanf("%c", &op);
    
    printf("enter second number: ");
    scanf("%d", &n2);
    
    
    switch(op) {
        case '+': printf("%d + %d = %d", n1, n2, n1 + n2);
        break;
        
        case '-': printf("%d - %d = %d", n1, n2, n1 - n2);
        break;
        
        case '*': printf("%d * %d = %d", n1, n2, n1 * n2);
        break;
        
        case '/': printf("%d / %d = %d", n1, n2, n1 / n2);
        break;
    }

    return 0;
}