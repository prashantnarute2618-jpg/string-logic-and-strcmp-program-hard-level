#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "listen";
    char s2[] = "silent";
    
    // Check if lengths are different
    if (strlen(s1) != strlen(s2)) {
        printf("Not anagrams (different length).\n");
        return 0;
    }

    int alphabet[26] = {0}; // 26 letters, all set to 0
    int len = strlen(s1);

    // Count chars for s1 (add) and s2 (subtract)
    for (int i = 0; i < len; i++) {
        // Assumes lowercase a-z.
        // Fails if there are uppercase or other chars.
        alphabet[s1[i] - 'a']++;
        alphabet[s2[i] - 'a']--;
    }

    // Check if all counts are back to 0
    int isAnagram = 1;
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] != 0) {
            isAnagram = 0;
            break;
        }
    }

    if (isAnagram == 1) {
        printf("'%s' and '%s' are anagrams.\n", s1, s2);
    } else {
        // This was the corrected line:
        printf("'%s' and '%s' are not anagrams.\n", s1, s2);
    }
    
    return 0;
}