#include <stdio.h>
#include <string.h>

// 1 = true, 0 = false
int isPalindrome(char str[], int start, int end) {
    // Base case 1: String is empty or 1 char
    if (start >= end) {
        return 1;
    }

    // Base case 2: First and last chars do not match
    if (str[start] != str[end]) {
        return 0;
    }

    // Recursive step
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char word[] = "madam";
    int len = strlen(word);

    if (isPalindrome(word, 0, len - 1) == 1) {
        printf("'%s' is a palindrome.\n", word);
    } else {
        printf("'%s' is not a palindrome.\n", word);
    }
    return 0;
}