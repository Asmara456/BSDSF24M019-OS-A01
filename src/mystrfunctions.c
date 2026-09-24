// File: src/mystrfunctions.c
#include "../include/mystrfunctions.h"

// Count characters until the end marker '\0'
int mystrlen(const char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

// Copy all of src into dest, including the end marker
int mystrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';   // the loop stops before copying '\0', so add it
    return i;         // number of characters copied
}

// Copy at most n characters from src into dest
int mystrncpy(char* dest, const char* src, int n) {
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    int copied = i;
    while (i < n) {   // if src was shorter than n, pad the rest with '\0'
        dest[i] = '\0';
        i++;
    }
    return copied;
}

// Append src to the end of dest
int mystrcat(char* dest, const char* src) {
    int len = mystrlen(dest);   // find where dest ends
    int i = 0;
    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return len + i;             // new length of dest
}
