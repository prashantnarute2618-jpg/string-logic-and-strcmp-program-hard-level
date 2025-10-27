#include <stdio.h>
#include <string.h>

// Finds value for key in json
void findValue(char *json, char *key, char *result) {
    char *key_pos = strstr(json, key);
    if (key_pos == NULL) {
        strcpy(result, "Not Found");
        return;
    }
    
    // Find the colon ':'
    char *colon_pos = strchr(key_pos, ':');
    // Find the first quote '"' after colon
    char *start_pos = strchr(colon_pos, '\"');
    // Find the second quote '"'
    char *end_pos = strchr(start_pos + 1, '\"');
    
    if (start_pos == NULL || end_pos == NULL) {
        strcpy(result, "Error");
        return;
    }
    
    // Copy the substring
    int len = end_pos - (start_pos + 1);
    strncpy(result, start_pos + 1, len);
    result[len] = '\0'; // Null terminate
}

int main() {
    char json[] = "{\"id\":123, \"name\":\"Adi\", \"status\":\"active\"}";
    char key[] = "\"name\"";
    char value[50];
    
    findValue(json, key, value);
    printf("Found value for 'name': %s\n", value);
    
    return 0;
}