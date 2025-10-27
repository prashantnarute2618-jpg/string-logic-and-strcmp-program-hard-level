#include <stdio.h>
#include <string.h>

int main() {
    int currentRoom = 1; // 1: Hall, 2: Kitchen, 3: Library
    int hasKey = 0;
    char cmd[20];

    while (1) {
        // 1. Print description based on state
        if (currentRoom == 1) printf("\nYou are in a hall. (n)orth, (e)ast\n");
        if (currentRoom == 2) printf("\nYou are in a kitchen. (s)outh\n");
        if (currentRoom == 3 && hasKey==0) printf("\nYou see a shiny (k)ey. (w)est\n");
        if (currentRoom == 3 && hasKey==1) printf("\nYou are in an empty library. (w)est\n");
        
        printf("> ");
        scanf("%s", cmd);

        // 2. Update state based on input
        if (strcmp(cmd, "n") == 0 && currentRoom == 1) {
            currentRoom = 2;
        } else if (strcmp(cmd, "e") == 0 && currentRoom == 1) {
            currentRoom = 3;
        } else if (strcmp(cmd, "s") == 0 && currentRoom == 2) {
            currentRoom = 1;
        } else if (strcmp(cmd, "w") == 0 && currentRoom == 3) {
            currentRoom = 1;
        } else if (strcmp(cmd, "k") == 0 && currentRoom == 3) {
            hasKey = 1; printf("You took the key!\n");
        } else {
            printf("You can't do that.\n");
        }
    }
    return 0;
}