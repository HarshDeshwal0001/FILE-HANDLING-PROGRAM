#include <stdio.h>
#include <stdlib.h>

void create_and_write_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }

    fprintf(file, "This is the first line of the file.\n");
    fprintf(file, "This is the second line.\n");

    fclose(file);
    printf("File created and written successfully.\n");
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error reading file! File may not exist.\n");
        return;
    }

    char ch;
    printf("\nReading file contents:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void append_to_file(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        exit(1);
    }

    fprintf(file, "This is an appended line.\n");

    fclose(file);
    printf("Data appended to file.\n");
}

int main() {
    const char *filename = "sample_file.txt";

    create_and_write_file(filename);
    read_file(filename);
    append_to_file(filename);
    read_file(filename);

    return 0;
}
