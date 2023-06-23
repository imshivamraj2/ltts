#include <stdio.h>
#include <string.h>

int main()
{
    int roll, phy, maths, chem, total;
    float percent;
    char name[20];
    
    printf("Enter roll no: ");
    scanf("%d", &roll);
    getchar();
    
    printf("Enter name: ");
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = '\0';
    
    printf("Enter marks in phy, maths, chem:");
    scanf("%d%d%d", &phy, &maths, &chem);
    
    total = phy + maths + chem;
    percent = total/3;
    
    printf("\nRoll no: %d\nName of student: %s\n", roll, name);
    printf("Marks obtained in Physics: %d\nMarks obtained in Maths: %d\nMarks obtained in Chemistry: %d\n", phy, maths, chem);
    printf("Total marks: %d\nPercentage: %f", total, percent);

    return 0;
}