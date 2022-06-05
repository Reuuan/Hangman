#include "HangmanLib.h"
#include <stdio.h>
#include <string.h>

int main()
{
    FILE* file;
    char* word = malloc(sizeof(char) * 20);
    char* buffer = malloc(sizeof(char) * 400);
    int diff;
    int len;
    greetings();
    printf("Enter 1, 2 or 3 to select difficulty\n");
    scanf("%d", &diff);
    switch (diff) {
    case 1:
        file = fopen("src/Dictionares/level-1.txt", "r");
        break;
    case 2:
        file = fopen("src/Dictionares/level-2.txt", "r");
        break;
    case 3:
        file = fopen("src/Dictionares/level-3.txt", "r");
        break;
    default:
        printf("Invalid character entered! Please enter 1, 2 or 3!\n");
        return 0;
    }
    int rand = getrand();
    fgets(buffer, 400, file);
    len = rand_word(buffer, word, rand);
    word_guess(word, len);
    fclose(file);
    free(buffer);
    free(word);
    return 0;
}
