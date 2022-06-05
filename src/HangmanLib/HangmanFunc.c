#include <HangmanLib.h>

void greetings()
{
    printf("Hello!\n");
    printf("Be careful, you may be hanged!\n");
    printf("Rules: \n");
    printf(" - You can make 8 mistakes.\n");
    printf(" - You can enter Latin characters in any case.\n");
    printf(" - Game starts soon, GLHF\n");
}

int getrand()
{
    int r;
    srand(time(NULL));
    r = rand();
    return r % 19;
}

int rand_word(char* array, char* word, int rand)
{
    int i = 0, counter = 0;
    for (; counter != rand; i++) {
        if (array[i] == ' ') {
            counter++;
        }
    }
    int lw = 0;
    for (; array[i] != ' '; i++) {
        word[lw] = array[i];
        lw++;
    }
    word[lw] = '\0';
    return strlen(word);
}

void print_hangman(int mistakes)
{
    switch (mistakes) {
    case 1:
        printf("      |\n      |\n      |\n      |\n      |\n______|\n \n");
        break;
    case 2:
        printf(" _____\n |    |\n      |\n      |\n      |\n      |\n______|\n "
               "\n");
        break;
    case 3:
        printf(" _____\n |    |\n o    |\n      |\n      |\n      |\n______|\n "
               "\n");
        break;
    case 4:
        printf(" _____\n |    |\n o    |\n |    |\n ^    |\n      |\n______|\n "
               "\n");
        break;
    case 5:
        printf(" _____\n |    |\n o    |\n/|    |\n ^    |\n      |\n______|\n "
               "\n");
        break;
    case 6:
        printf(" _____\n |    |\n o    |\n/|\\   |\n ^    |\n      "
               "|\n______|\n \n");
        break;
    case 7:
        printf(" _____\n |    |\n o    |\n/|\\   |\n ^    |\n/     "
               "|\n______|\n \n");
        break;
    case 8:
        printf(" _____\n |    |\n o    |\n/|\\   |\n ^    |\n/ \\   "
               "|\n______|\n \n");
        break;
    }
}

bool let_rep_check(char* letter, char* used_letters)
{
    int ul = strlen(used_letters);
    bool letter_repeat = 0;
    for (int i = 0; i < ul; i++) {
        if (letter[0] == used_letters[i]) {
            letter_repeat = 1;
        }
    }
    if (letter_repeat == 1) {
        printf("You have already entered this letter!\n");
        return 1;
    } else {
        used_letters[ul] = letter[0];
        ul++;
        return 0;
    }
}

bool albhabet_check(char* letter)
{
    if ((letter[0] < 'a') || (letter[0] > 'z')) {
        printf("Invalid character!\n");
        return 1;
    } else {
        return 0;
    }
}

void array_filling(char* cells, int len)
{
    for (int i = 0; i < len; i++) {
        cells[i] = '_';
    }
    cells[len] = '\0';
    printf("%s\n", cells);
}

bool lose_check(int mistakes)
{
    if (mistakes == 8) {
        printf("You were hanged!\n");
        printf("Hidden word:");
        return 1;
    } else {
        return 0;
    }
}

bool word_check(char* word, char* cells, char* letter, int len)
{
    bool flag = 0;
    for (int i = 0; i <= len; i++) {
        if (word[i] == letter[0]) {
            cells[i] = letter[0];
            flag = 1;
        }
    }
    return flag;
}

int mistakes_action(bool flag, int mistakes)
{
    if (flag == 0) {
        mistakes++;
        printf("Mistake!\n");
        print_hangman(mistakes);
    }
    printf("%d-Mistakes\n", mistakes);
    return mistakes;
}

void word_guess(char* word, int len)
{
    int i = 1;
    char* letter = malloc(sizeof(char));
    int mistakes = 0;
    char* cells = malloc(sizeof(char) * len);
    char* used_letters = malloc(sizeof(char) * len + 20);
    array_filling(cells, len);
    while (strcmp(word, cells) != 0) {
        // printf("\t%s\n", word); //Тестовая проверка
        printf("Enter a letter\n");
        scanf("%s", letter);
        letter[0] = tolower(letter[0]);
        if ((albhabet_check(letter) == 1)
            || (let_rep_check(letter, used_letters) == 1)) {
            printf("Please try another letter\n");
            continue;
        }
        if (mistakes_action(word_check(word, cells, letter, len), mistakes)
            == i) {
            mistakes++;
            i++;
        }

        if (lose_check(mistakes)) {
            printf("%s\n", word);
            break;
        }

        printf("%s\n", cells);
    }
    if (strcmp(word, cells) == 0) {
        printf("Congratulations, you won!\n");
    }
    free(letter);
    free(cells);
    free(used_letters);
    printf("Thanks for playing this game!\n");
}
