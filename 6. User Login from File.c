#include <stdio.h>
#include <string.h>

int main() {
    char user[50], pass[50];
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    scanf("%s", pass);

    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error: users.txt not found.\n");
        return 1;
    }
    
    char line[100];
    int loggedIn = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // Split line "user,pass"
        char *dbUser = strtok(line, ",");
        char *dbPass = strtok(NULL, "\n"); // Read to newline

        if (dbUser != NULL && dbPass != NULL) {
            if (strcmp(user, dbUser) == 0 && strcmp(pass, dbPass) == 0) {
                loggedIn = 1;
                break;
            }
        }
    }
    
    if (loggedIn == 1) printf("Login Successful!\n");
    else printf("Login Failed.\n");
    
    fclose(file);
    return 0;
}