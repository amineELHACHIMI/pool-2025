#include <stdio.h>

int count_words(char *str) {
	int i=0;
    int count = 0;
    int in_word = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            in_word = 0;
        } else if (in_word != 1) {
            in_word = 1;
            count++;
        }
        i++;
    }

    return count;
}

int main() {
    char str[] = "Hello               world   this is   a test";
    printf("Word count: %d\n", count_words(str));
    return 0;
}
