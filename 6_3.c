#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_SENSOR_NAME 10
#define MAX_TIMESTAMP 9

// Structure to represent each entry in the log
struct LogEntry {
    int entryNo;
    char sensorNo[MAX_SENSOR_NAME];
    float temperature;
    int humidity;
    int light;
    char timestamp[MAX_TIMESTAMP];
};

// Function to extract log entries from the CSV file and store them in the array of structures
int extractLogEntries(struct LogEntry entries[]) {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open data.csv\n");
        return 0;
    }

    char line[100];
    int count = 0;

    // Skip the header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL && count < MAX_ENTRIES) {
        char *token = strtok(line, ",");
        entries[count].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strcpy(entries[count].sensorNo, token);

        token = strtok(NULL, ",");
        entries[count].temperature = atof(token);

        token = strtok(NULL, ",");
        entries[count].humidity = atoi(token);

        token = strtok(NULL, ",");
        entries[count].light = atoi(token);

        token = strtok(NULL, ",");
        strcpy(entries[count].timestamp, token);

        count++;
    }

    fclose(file);

    return count;
}

// Function to display the log entries
void displayLogEntries(struct LogEntry entries[], int count) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t\t%d\t\t%d\t%s\n",
            entries[i].entryNo,
            entries[i].sensorNo,
            entries[i].temperature,
            entries[i].humidity,
            entries[i].light,
            entries[i].timestamp);
    }
}

int main() {
    struct LogEntry entries[MAX_ENTRIES];
    int count = extractLogEntries(entries);

    if (count > 0) {
        displayLogEntries(entries, count);
    }

    return 0;
}
