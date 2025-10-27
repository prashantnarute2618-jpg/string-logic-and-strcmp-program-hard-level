#include <stdio.h>
#include <string.h>

// Function to swap two string pointers
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char *names[] = {"Adi", "Zeal", "Robotics", "Eris", "Pune"};
    int n = 5;

    printf("Original: ");
    for(int i=0; i<n; i++) printf("%s ", names[i]);
    printf("\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // if names[j] > names[j+1]
            if (strcmp(names[j], names[j + 1]) > 0) {
                swap(&names[j], &names[j + 1]);
            }
        }
    }

    printf("Sorted:   ");
    for(int i=0; i<n; i++) printf("%s ", names[i]);
    printf("\n");
    return 0;
}