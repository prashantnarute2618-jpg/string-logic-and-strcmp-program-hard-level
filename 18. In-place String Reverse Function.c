#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    if (str == NULL) return; // Safety check
    
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while (start < end) {
        // Swap chars
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        // Move pointers
        start++;
        end--;
    }
}

int main() {
    char myName[] = "Adi Eris";
    
    printf("Original: %s\n", myName);
    reverseString(myName);
    printf("Reversed: %s\n", myName);
    
    return 0;
}