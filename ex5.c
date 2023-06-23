#include <stdio.h>

int bit_operations(int n, int op)
{
    switch(op) {
        case 1 : n = n|1;
        break;
        
        case 2 : n = n & ~(1>>31);
        break;
        
        case 3 : n = n ^ (1>>16);
        break;
    }
    return n;
}



int main()
{
    int num, oper_type, result;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Enter operation type (1, 2, 3): ");
    scanf("%d", &oper_type);
    
    result = bit_operations(num, oper_type);
    printf("Result is %d", result);
    
    return 0;
}