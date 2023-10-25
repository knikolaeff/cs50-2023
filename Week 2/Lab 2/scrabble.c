#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define WORD_SIZE_LIMIT 128
#define ASCII_LOWERCASE_A 97

const int SCORES[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *);

int main(void)
{
    char word_1[128];
    char word_2[128];

    printf("Player 1: ");
    fgets(word_1, WORD_SIZE_LIMIT, stdin);
    printf("Player 2: ");
    fgets(word_2, WORD_SIZE_LIMIT, stdin);

    int score_1 = compute_score(word_1);
    int score_2 = compute_score(word_2);

    if (score_1 > score_2)
    {
        printf("Player 1 wins!");
    }

    else if (score_2 > score_1)
    {
    printf("Player 2 wins!");
    }

    else
    {
        printf("Tie!");
    }
}

int compute_score(char* word)
{

   int score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        score += (isalpha(word[i])) ? SCORES[tolower(word[i]) - ASCII_LOWERCASE_A] : 0;
    }

    return score;
}