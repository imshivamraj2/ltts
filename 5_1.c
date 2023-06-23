#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* inputString, struct Student* students, int size) {
    char* token;
    int i = 0;

    // Parse the string and initialize the array of structures
    token = strtok((char*)inputString, " ");
    while (token != NULL && i < size) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        if (token != NULL) {
            strcpy(students[i].name, token);

            token = strtok(NULL, " ");
            if (token != NULL) {
                students[i].marks = atof(token);
            }
        }

        i++;
        token = strtok(NULL, " ");
    }
}

int main() {
    int size;
    char inputString[100];
    struct Student* students;

    // Prompt the user to enter the size of the array
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); // Consume the newline character

    // Dynamically allocate memory for the array of structures
    students = (struct Student*)malloc(size * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Prompt the user to enter the input string
    printf("Enter the input string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove the newline character from the input string
    inputString[strcspn(inputString, "\n")] = '\0';

    // Call the parseString function to initialize the array of structures
    parseString(inputString, students, size);

    // Display the contents of the array of structures
    printf("\nArray of structures:\n");
    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
