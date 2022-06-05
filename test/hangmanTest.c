#include <HangmanLib.h>
#include <ctest.h>
#include <stdlib.h>

CTEST(random_num, get_rand_num)
{
    const int exp1 = 0;
    const int exp2 = 19;
    const int real = getrand();

    ASSERT_INTERVAL(exp1, exp2, real);
}
CTEST(word, word_rand)
{
    char array[22] = "key fish apple wizard";
    char word[7];
    const int rand = 2;
    const int exp = 5;
    const int real = rand_word(array, word, rand);
    ASSERT_EQUAL(exp, real);
}
CTEST(letter, letter_repeat_check)
{
    char letter[1] = "a";
    char used_letters[6] = "abcd";
    const bool real = let_rep_check(letter, used_letters);
    const bool exp = 1;
    ASSERT_EQUAL(exp, real);
}
CTEST(letter, check_alphabet)
{
    char letter[1] = "8";
    const bool exp = 1;
    const bool real = albhabet_check(letter);
    ASSERT_EQUAL(exp, real);
}
CTEST(mistake, check_lose)
{
    const int mistakes = 8;
    const bool exp = 1;
    const bool real = lose_check(mistakes);
    ASSERT_EQUAL(exp, real);
}
CTEST(letter, check_word)
{
    char word[6] = "apple";
    char cells[6] = "_____";
    char letter[1] = "p";
    const int len = 5;
    const bool exp = 1;
    const bool real = word_check(word, cells, letter, len);
    ASSERT_EQUAL(exp, real);
}
CTEST(mistake, action_mistake)
{
    const bool flag = 0;
    int mistakes = 5;
    const int exp = 6;
    const int real = mistakes_action(flag, mistakes);
    ASSERT_EQUAL(exp, real);
}