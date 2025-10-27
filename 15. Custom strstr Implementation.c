#include <stdio.h>
#include <string.h>

char* my_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') return (char*)haystack;

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;
        
        // Check for match
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        
        // If needle ended, we found a match
        if (*n == '\0') {
            return (char*)haystack; // Return start
        }
        
        haystack++; // Move to next char in haystack
    }
    return NULL; // Not found
}

int main() {
    char *text = "the quick brown fox";
    char *find = "brown";
    
    char *result = my_strstr(text, find);
    
    if (result != NULL) {
        printf("Found '%s' at: %s\n", find, result);
    } else {
        printf("Could not find '%s'.\n", find);
    }
    return 0;
}