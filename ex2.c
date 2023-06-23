#include <stdio.h>

void grade(int m)
{
    if (m>=90 && m<=100)
        printf("Grade A");
        
    else if (m>=75 && m<=89)
        printf("Grade B");
        
    else if (m>=60 && m<=74)
        printf("Grade C");
        
    else if (m>=50 && m<=59)
        printf("Grade B");
        
    else if (m>=0 && m<=49)
        printf("Grade B");
        
    else
        printf("One can not score more than 100");
}

int main()
{
    int marks;
    
    printf("enter marks: ");
    scanf("%d", &marks);
    
    grade(marks);

    return 0;
}