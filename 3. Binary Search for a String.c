#include <stdio.h>
#include <string.h>

int main() {
    char *words[] = {"apple", "banana", "cherry", "grape", "mango"};
    int n = 5;
    char *key = "cherry";
    
    int low = 0, high = n - 1;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(words[mid], key);

        if (cmp == 0) {
            index = mid; // Found it
            break;
        } else if (cmp < 0) {
            // words[mid] is before key
            low = mid + 1;
        } else {
            // words[mid] is after key
            high = mid - 1;
        }
    }

    if (index != -1) {
        printf("Found '%s' at index %d.\n", key, index);
    } else {
        printf("Could not find '%s'.\n", key);
    }
    return 0;
}