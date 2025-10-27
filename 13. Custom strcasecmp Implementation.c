#include <stdio.h>
#include <string.h>
#include <ctype.h>

int my_strcasecmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        char c1 = tolower(*s1);
        char c2 = tolower(*s2);

        if (c1 < c2) return -1;
        if (c1 > c2) return 1;

        s1++;
        s2++;
    }
    // Check if one string is shorter
    if (*s1 == *s2) return 0; // Both are '\0'
    if (*s1 == '\0') return -1; // s1 is shorter
    return 1; // s2 is shorter
}

int main() {
    char s1[] = "Hello";
    char s2[] = "hello";
    char s3[] = "hellp";

    if (my_strcasecmp(s1, s2) == 0) {
        printf("'%s' and '%s' are equal (case-insensitive).\n", s1, s2);
    }
    if (my_strcasecmp(s1, s3) != 0) {
        printf("'%s' and '%s' are NOT equal.\n", s1, s3);
    }
    return 0;
}