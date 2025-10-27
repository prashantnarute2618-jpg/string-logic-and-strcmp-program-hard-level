#include <stdio.h>
#include <string.h>

int main() {
    char request[] = 
        "GET /index.html HTTP/1.1\n"
        "Host: example.com\n"
        "User-Agent: C-Client\n"
        "Content-Type: application/json\n";
    
    char keyToFind[] = "Content-Type";
    char header[50], value[50];
    
    char *line = strtok(request, "\n");
    while(line != NULL) {
        // sscanf parses a string. "%[^:]" reads until a ':'
        if (sscanf(line, "%[^:]: %s", header, value) == 2) {
            if (strcmp(header, keyToFind) == 0) {
                printf("Found %s: %s\n", header, value);
                break;
            }
        }
        line = strtok(NULL, "\n");
    }
    return 0;
}