// File: src/myfilefunctions.c
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/myfilefunctions.h"

// Count lines, words and characters in an open file.
// Returns 0 on success, -1 on failure.
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL || lines == NULL || words == NULL || chars == NULL)
        return -1;

    *lines = 0;
    *words = 0;
    *chars = 0;

    int c;
    int inWord = 0;                 // 1 while we are inside a word

    while ((c = fgetc(file)) != EOF) {
        (*chars)++;                 // every character counts
        if (c == '\n')
            (*lines)++;             // every newline ends a line
        if (isspace(c)) {
            inWord = 0;             // whitespace: we left the word
        } else if (!inWord) {
            inWord = 1;             // non-space after space: a new word starts
            (*words)++;
        }
    }
    return 0;
}

// Find all lines that contain search_str.
// Fills *matches with a malloc'd array of malloc'd strings.
// Returns the number of matches, or -1 on failure.
// The caller must free each string and then the array.
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL || search_str == NULL || matches == NULL)
        return -1;

    char** result = NULL;           // the array of matching lines
    int count = 0;
    char* line = NULL;              // getline allocates this buffer
    size_t cap = 0;
    ssize_t len;

    while ((len = getline(&line, &cap, fp)) != -1) {
        if (strstr(line, search_str) != NULL) {
            char** tmp = realloc(result, (count + 1) * sizeof(char*));
            char* copy = malloc(len + 1);
            if (tmp == NULL || copy == NULL) {
                // out of memory: clean up everything and fail
                free(copy);
                if (tmp != NULL) result = tmp;
                for (int i = 0; i < count; i++) free(result[i]);
                free(result);
                free(line);
                return -1;
            }
            result = tmp;
            strcpy(copy, line);
            result[count] = copy;
            count++;
        }
    }

    free(line);
    *matches = result;              // hand the array back to the caller
    return count;
}
