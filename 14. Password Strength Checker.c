#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char pass[50];
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    
    printf("Enter password to check: ");
    scanf("%s", pass);

    if (strlen(pass) < 8) {
        printf("Strength: WEAK (too short)\n");
        return 0;
    }

    for (int i = 0; pass[i] != '\0'; i++) {
        if (isupper(pass[i])) hasUpper = 1;
        else if (islower(pass[i])) hasLower = 1;
        else if (isdigit(pass[i])) hasDigit = 1;
        else hasSpecial = 1;
    }

    int score = hasUpper + hasLower + hasDigit + hasSpecial;

    if (score == 4) printf("Strength: STRONG\n");
    else if (score == 3) printf("Strength: MEDIUM\n");
    else printf("Strength: WEAK (missing character types)\n");
    
    return 0;
}