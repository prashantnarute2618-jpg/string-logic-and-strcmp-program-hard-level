#include <stdio.h>
#include <string.h>

int main() {
    char data[] = "name,age,city\n"
                  "adi,20,pune\n"
                  "eris,21,mumbai\n"
                  "zeal,22,pune\n";
    
    char *keyCity = "pune";
    char *line = strtok(data, "\n");
    
    // Skip header
    line = strtok(NULL, "\n"); 
    
    while(line != NULL) {
        char tempLine[100];
        strcpy(tempLine, line); // strtok modifies string
        
        char *name = strtok(tempLine, ",");
        char *age = strtok(NULL, ",");
        char *city = strtok(NULL, ",");
        
        if (city != NULL && strcmp(city, keyCity) == 0) {
            printf("Found match: %s is in %s\n", name, city);
        }
        line = strtok(NULL, "\n");
    }
    return 0;
}