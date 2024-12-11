#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define WORD_LENGTH 50

// Structure for anagram pairs
typedef struct {
    char word1[WORD_LENGTH];
    char word2[WORD_LENGTH];
} AnagramPair;

// Function prototypes
char *sortString(const char *str);
int areAnagrams(const char *word1, const char *word2);
void saveAnagramsToFile(AnagramPair *pairs, int count, const char *filename);

int main() {
    char inputFile[] = "words.txt";
    char outputFile[] = "anagrams.bin";
    FILE *file = fopen(inputFile, "r");

    if (!file) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    // Count the number of words in the file
    int wordCount = 0;
    char buffer[WORD_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        wordCount++;
    }

    // Allocate memory for words and read them into an array
    rewind(file);
    char **words = (char **)malloc(wordCount * sizeof(char *));
    for (int i = 0; i < wordCount; i++) {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline
        words[i] = strdup(buffer);
    }
    fclose(file);

    // Pick a random word
    srand(time(NULL));
    int randomIndex = rand() % wordCount;
    char *randomWord = words[randomIndex];
    printf("Random word: %s\n", randomWord);

    // Find all anagrams of the random word
    AnagramPair *anagrams = (AnagramPair *)malloc(wordCount * sizeof(AnagramPair));
    int anagramCount = 0;
    for (int i = 0; i < wordCount; i++) {
        if (i != randomIndex && areAnagrams(randomWord, words[i])) {
            strncpy(anagrams[anagramCount].word1, randomWord, WORD_LENGTH);
            strncpy(anagrams[anagramCount].word2, words[i], WORD_LENGTH);
            anagramCount++;
        }
    }

    // Save anagrams to binary file
    saveAnagramsToFile(anagrams, anagramCount, outputFile);

    // Free allocated memory
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(words);
    free(anagrams);

    printf("Anagram pairs saved to '%s'.\n", outputFile);
    return EXIT_SUCCESS;
}

// Function to sort the characters of a string
char *sortString(const char *str) {
    char *sorted = strdup(str);
    int len = strlen(sorted);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (sorted[i] > sorted[j]) {
                char temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    return sorted;
}

// Function to check if two words are anagrams
int areAnagrams(const char *word1, const char *word2) {
    if (strlen(word1) != strlen(word2)) {
        return 0;
    }

    char *sorted1 = sortString(word1);
    char *sorted2 = sortString(word2);

    int result = strcmp(sorted1, sorted2) == 0;

    free(sorted1);
    free(sorted2);

    return result;
}

// Function to save anagram pairs to a binary file
void saveAnagramsToFile(AnagramPair *pairs, int count, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    fwrite(&count, sizeof(int), 1, file); // Write the number of pairs
    fwrite(pairs, sizeof(AnagramPair), count, file); // Write the pairs

    fclose(file);
}
