#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char filename[100] = "default.txt";
    int verbose = 0; // 0 = false

    // Loop starts at 1 to skip program name
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            // Check if next argument exists
            if (i + 1 < argc) {
                strcpy(filename, argv[i + 1]);
                i++; // Skip the next argument (filename)
            } else {
                printf("Error: -f flag needs a filename.\n");
            }
        } else if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        } else {
            printf("Unknown option: %s\n", argv[i]);
        }
    }

    printf("Running with settings:\n");
    printf("Filename: %s\n", filename);
    printf("Verbose: %s\n", (verbose == 1) ? "ON" : "OFF");
    return 0;
}