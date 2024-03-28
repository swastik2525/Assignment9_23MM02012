#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_RECORDS 100


struct StudentRecord {
    char name[50];
    int rollNumber;
    float percentage;
};

struct StudentRecord database[MAX_RECORDS];
int numRecords = 0;

void insert(char name[], int rollNumber, float percentage) {
    if (numRecords >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    struct StudentRecord newRecord;
    strcpy(newRecord.name, name);
    newRecord.rollNumber = rollNumber;
    newRecord.percentage = percentage;

    int i = numRecords - 1;
    while (i >= 0 && database[i].rollNumber > rollNumber) {
        database[i + 1] = database[i];
        i--;
    }
    database[i + 1] = newRecord;
    numRecords++;
}

void sortName() {
    for (int i = 0; i < numRecords - 1; i++) {
        for (int j = 0; j < numRecords - i - 1; j++) {
            if (strcmp(database[j].name, database[j + 1].name) > 0) {
                struct StudentRecord temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
            }
        }
    }
}

char* findOne(char prefix[]) {
    for (int i = 0; i < numRecords; i++) {
        if (strncmp(database[i].name, prefix, strlen(prefix)) == 0) {
            return database[i].name;
        }
    }
    return NULL;
}

void delete(int rollNumber) {
    int i;
    for (i = 0; i < numRecords; i++) {
        if (database[i].rollNumber == rollNumber) {
            for (int j = i; j < numRecords - 1; j++) {
                database[j] = database[j + 1];
            }
            numRecords--;
            printf("Record deleted.\n");
            return;
        }
    }
    printf("Record not found.\n");
}

void specs() {
    float sum = 0, mean, variance = 0, stdDeviation;
    float highestPercentage = database[0].percentage;
    float lowestPercentage = database[0].percentage;

    for (int i = 0; i < numRecords; i++) {
        sum += database[i].percentage;
        if (database[i].percentage > highestPercentage)
            highestPercentage = database[i].percentage;
        if (database[i].percentage < lowestPercentage)
            lowestPercentage = database[i].percentage;
    }

    mean = sum / numRecords;

    for (int i = 0; i < numRecords; i++) {
        variance += pow(database[i].percentage - mean, 2);
    }
    variance /= numRecords;

    stdDeviation = sqrt(variance);

    printf("Number of records: %d\n", numRecords);
    printf("Highest percentage: %.2f\n", highestPercentage);
    printf("Lowest percentage: %.2f\n", lowestPercentage);
    printf("Mean: %.2f\n", mean);
    printf("Standard deviation: %.2f\n", stdDeviation);
}

int main() {
    insert("White", 101, 85.5);
    insert("Jessy", 103, 78.3);
    insert("Ajoy", 102, 92.0);

    sortName();

    printf("Records sorted by name:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s, Roll Number: %d, Percentage: %.2f\n", database[i].name, database[i].rollNumber, database[i].percentage);
    }

    printf("\nFound name starting with 'A': %s\n", findOne("A"));

    delete(101);

    printf("\nRecords after deleting roll number 101:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s, Roll Number: %d, Percentage: %.2f\n", database[i].name, database[i].rollNumber, database[i].percentage);
    }

    printf("\nStatistics:\n");
    specs();

    return 0;
}
