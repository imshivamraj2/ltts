#include <stdio.h>

void biggerOf2(int n1, int n2) { 
    if (n1 > n2) {
        printf("%d is bigger", n1);
    }
    else {
        printf("%d is bigger", n2);
    }
}

void biggerOf2(int n1, int n2) 
{ 
    (n1 > n2) ? printf("%d is bigger", n1) : printf("%d is bigger", n2);
}
int main()
{
    int num1, num2;

    printf("Enter 2 numbers\n");
    scanf("%d%d",&num1, &num2);

    biggerOf2(num1, num2);

    return 0;
}