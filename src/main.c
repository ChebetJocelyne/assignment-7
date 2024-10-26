#include <stdio.h>


#define FILENAME "data.txt"

// Function to write a sentence to a file
void writeSentenceToFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    char sentence[101];
    printf("Enter a sentence (up to 100 characters): ");
    fgets(sentence, sizeof(sentence), stdin);

    fprintf(file, "%s", sentence);
    fclose(file);
    printf("Sentence written to file.\n");
}

// Function to read content from a file and display it
void readFromFile() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char buffer[101];
    printf("File content:\n");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
}

// Function to append a sentence to a file
void appendSentenceToFile() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        exit(EXIT_FAILURE);
    }

    char sentence[101];
    printf("Enter another sentence (up to 100 characters): ");
    fgets(sentence, sizeof(sentence), stdin);

    fprintf(file, "%s", sentence);
    fclose(file);
    printf("Sentence appended to file.\n");
}

int main() {
    writeSentenceToFile();
    readFromFile();
    appendSentenceToFile();
    readFromFile();

    return 0;
}


