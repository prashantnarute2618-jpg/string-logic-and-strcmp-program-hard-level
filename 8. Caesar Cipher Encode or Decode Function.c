#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesar(char *str, int key, char *mode) {
    int shift = key;
    
    if (strcmp(mode, "decode") == 0) {
        shift = -key;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char base = isupper(str[i]) ? 'A' : 'a';
            // Modulo math to wrap around the alphabet
            str[i] = (str[i] - base + shift + 26) % 26 + base;
        }
    }
}

int main() {
    char msg[] = "Hello";
    
    caesar(msg, 3, "encode");
    printf("Encoded: %s\n", msg); // "Khoor"

    caesar(msg, 3, "decode");
    printf("Decoded: %s\n", msg); // "Hello"
    
    return 0;
}