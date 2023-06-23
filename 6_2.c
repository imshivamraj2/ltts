#include <stdio.h>
#include <ctype.h>

// Function to convert file content to upper case
void convertToUpper(FILE* inputFile, FILE* outputFile) {
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(toupper(ch), outputFile);
    }
}

// Function to convert file content to lower case
void convertToLower(FILE* inputFile, FILE* outputFile) {
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(tolower(ch), outputFile);
    }
}

// Function to convert file content to purely upper case
void convertToPurelyUpper(FILE* inputFile, FILE* outputFile) {
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (isalpha(ch)) {
            fputc(toupper(ch), outputFile);
        } else {
            fputc(ch, outputFile);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments!\n");
        printf("Usage: ./cp [option] <source_file> <destination_file>\n");
        printf("Options:\n");
        printf("  -u : Convert file content to upper case\n");
        printf("  -l : Convert file content to lower case\n");
        printf("  -s : Convert file content to purely upper case\n");
        return 1;
    }

    // Open the source file in read mode
    FILE* inputFile = fopen(argv[2], "r");
    if (inputFile == NULL) {
        printf("Failed to open source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    FILE* outputFile = fopen(argv[3], "w");
    if (outputFile == NULL) {
        printf("Failed to create destination file.\n");
        fclose(inputFile);
        return 1;
    }

    // Determine the option and perform the corresponding transformation
    if (argv[1][0] == '-' && argv[1][1] == 'u') {
        convertToUpper(inputFile, outputFile);
    } else if (argv[1][0] == '-' && argv[1][1] == 'l') {
        convertToLower(inputFile, outputFile);
    } else if (argv[1][0] == '-' && argv[1][1] == 's') {
        convertToPurelyUpper(inputFile, outputFile);
    } else {
        char ch;
        while ((ch = fgetc(inputFile)) != EOF) {
            fputc(ch, outputFile);
        }
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File copied successfully.\n");

    return 0;
}
