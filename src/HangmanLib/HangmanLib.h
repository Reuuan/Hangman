#pragma once
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void greetings();
int getrand();
int rand_word(char* array, char* word, int rand);
void print_hangman(int mistakes);
bool let_rep_check(char* letter, char* used_letters);
bool albhabet_check(char* letter);
void array_filling(char* cells, int len);
bool lose_check(int mistakes);
bool word_check(char* word, char* cells, char* letter, int len);
int mistakes_action(bool flag, int mistakes);
void word_guess(char* word, int len);