#include <stdio.h>
#include <string.h>

// 1 = exists, 0 = not
int userExists(char *user) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) return 0; // No file, so user can't exist
    
    char line[100];
    while(fgets(line, sizeof(line), file)) {
        char *dbUser = strtok(line, ",");
        if (dbUser != NULL && strcmp(user, dbUser) == 0) {
            fclose(file);
            return 1; // Found
        }
    }
    fclose(file);
    return 0; // Not found
}

int main() {
    char user[50], pass[50];
    printf("Enter new username: ");
    scanf("%s", user);

    if (userExists(user) == 1) {
        printf("Error: User '%s' already exists.\n", user);
    } else {
        printf("Enter new password: ");
        scanf("%s", pass);
        
        FILE *file = fopen("users.txt", "a"); // "a" = append
        fprintf(file, "%s,%s\n", user, pass);
        fclose(file);
        printf("User '%s' registered successfully.\n", user);
    }
    return 0;
}