#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <pattern> <filename>\n", argv[0]);
        return 1;
    }

    char *pattern = argv[1];
    char *filename = argv[2];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    char line[500];
    int lineNum = 1;
    
    while (fgets(line, sizeof(line), file) != NULL) {
        // Check if pattern exists in the line
        if (strstr(line, pattern) != NULL) {
            printf("%d: %s", lineNum, line);
        }
        lineNum++;
    }

    fclose(file);
    return 0;
}