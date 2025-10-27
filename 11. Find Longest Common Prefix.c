#include <stdio.h>
#include <string.h>

int main() {
    char *strs[] = {"flower", "flow", "flight"};
    int n = 3;
    if (n == 0) return 0;
    
    char prefix[100];
    strcpy(prefix, strs[0]); // Start with first string
    
    for (int i = 1; i < n; i++) {
        // Shorten prefix until it matches
        while (strncmp(strs[i], prefix, strlen(prefix)) != 0) {
            // Remove last char from prefix
            prefix[strlen(prefix) - 1] = '\0';
            if (strlen(prefix) == 0) {
                printf("No common prefix.\n");
                return 0;
            }
        }
    }

    printf("Longest common prefix: %s\n", prefix);
    return 0;
}