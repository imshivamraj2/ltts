#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compareMarks(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;
    
    if (studentA->marks < studentB->marks) {
        return 1;
    } else if (studentA->marks > studentB->marks) {
        return -1;
    } else {
        return 0;
    }
}

void sortStudents(struct Student* students, int size) {
    qsort(students, size, sizeof(struct Student), compareMarks);
}

void displayStudents(const struct Student* students, int size) {
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int size;
    struct Student students[5];

    // Prompt the user to enter the size of the array
    printf("Enter the number of students: ");
    scanf("%d", &size);

    // Read the data for each student
    for (int i = 0; i < size; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].rollno);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
        printf("\n");
    }

    // Sort the array of structures based on marks in descending order
    sortStudents(students, size);

    // Display the sorted array of structures
    printf("Sorted array of structures:\n");
    displayStudents(students, size);

    return 0;
}
