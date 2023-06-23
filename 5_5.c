#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(const struct Student* students, int size, const char* name) {
    int found = 0;
    
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student not found.\n");
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

    // Prompt the user to enter the name to search for
    char searchName[20];
    printf("Enter the name of the student to search for: ");
    scanf("%s", searchName);

    // Search for the student by name
    searchStudentByName(students, size, searchName);

    return 0;
}
