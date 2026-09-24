// File: src/main.c
#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");

    // mystrlen
    const char* s = "Hello";
    printf("mystrlen(\"%s\") = %d\n", s, mystrlen(s));

    // mystrcpy
    char buf1[100];
    int n = mystrcpy(buf1, s);
    printf("mystrcpy: buf1 = \"%s\" (copied %d chars)\n", buf1, n);

    // mystrncpy (copies only the first 9 chars, so we add '\0' ourselves)
    char buf2[100];
    n = mystrncpy(buf2, "Operating System", 9);
    buf2[9] = '\0';
    printf("mystrncpy: buf2 = \"%s\" (copied %d chars)\n", buf2, n);

    // mystrcat
    char buf3[100] = "Hello";
    n = mystrcat(buf3, ", World");
    printf("mystrcat: buf3 = \"%s\" (new length %d)\n", buf3, n);

    printf("\n--- Testing File Functions ---\n");

    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open test.txt\n");
        return 1;
    }

    // wordCount
    int lines, words, chars;
    if (wordCount(fp, &lines, &words, &chars) == 0)
        printf("wordCount: %d lines, %d words, %d chars\n", lines, words, chars);
    else
        printf("wordCount failed\n");

    // go back to the start of the file before searching
    rewind(fp);

    // mygrep
    char** matches = NULL;
    int count = mygrep(fp, "Linux", &matches);
    if (count < 0) {
        printf("mygrep failed\n");
    } else {
        printf("mygrep: %d lines contain \"Linux\":\n", count);
        for (int i = 0; i < count; i++) {
            printf("  %s", matches[i]);
            free(matches[i]);       // free each line
        }
        free(matches);              // then free the array
    }

    fclose(fp);
    return 0;
}
