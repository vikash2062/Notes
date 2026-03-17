// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>   // for isalpha(), tolower()

// Custom String struct
typedef struct String {
    char *str;
} string;

// Safe input function with dynamic reallocation
char *input(FILE *fp, int size, int has_space) {
    int actual_size = 0;
    char *str = (char *)malloc(sizeof(char) * size);
    if (!str) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    char ch;
    while (EOF != (ch = fgetc(fp)) && ch != '\n' && (has_space || ch != ' ')) {
        str[actual_size++] = ch;
        if (actual_size >= size) {
            size *= 2; // double buffer size
            str = realloc(str, sizeof(char) * size);
            if (!str) {
                printf("Memory allocation failed!\n");
                exit(1);
            }
        }
    }
    str[actual_size] = '\0';
    return str;
}

/**
 * Count the number of letters (a-z or A-Z) that appear exactly once.
 * Ignore spaces and other non-letter characters.
 */
int unaffectedChar(string dataStream) {
    int freq[26] = {0}; // for 'a' to 'z'
    int i = 0;

    // Count frequency for letters only (case insensitive)
    while (dataStream.str[i] != '\0') {
        char ch = dataStream.str[i];
        if (isalpha(ch)) {
            ch = tolower(ch); // treat A and a same
            freq[ch - 'a']++;
        }
        i++;
    }

    // Count how many letters appear exactly once
    int answer = 0;
    for (i = 0; i < 26; i++) {
        if (freq[i] == 1) {
            answer++;
        }
    }

    return answer;
}

int main() {
    string dataStream;
    printf("Enter input: ");
    dataStream.str = input(stdin, 200, 1);

    int result = unaffectedChar(dataStream);
    printf("%d\n", result);

    free(dataStream.str);
    return 0;
}

