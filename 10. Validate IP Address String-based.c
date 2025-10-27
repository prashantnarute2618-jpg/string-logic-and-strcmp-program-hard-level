#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for atoi
#include <ctype.h>  // for isdigit

int main() {
    char ip_str[] = "192.168.0.1";
    char *token = strtok(ip_str, ".");
    int parts = 0, isValid = 1;

    while (token != NULL) {
        parts++;
        int val = atoi(token); // Convert string to int
        
        // Check if token is a number and in range
        if (val < 0 || val > 255) isValid = 0;
        // Check if token has non-digit chars
        for(int i=0; token[i]!='\0'; i++) {
            if(isdigit(token[i]) == 0) isValid = 0;
        }

        token = strtok(NULL, ".");
    }

    // Final check
    if (parts != 4) isValid = 0;

    if (isValid == 1) printf("IP address is valid.\n");
    else printf("IP address is invalid.\n");
    
    return 0;
}