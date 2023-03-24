#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char *get_string(char *str);
int count_letters(char *text);
int count_words(char *text);
int count_sentences(char *text);

int main(void)
{

    char *text = get_string("Text: ");
    if (text == NULL)
    {
        printf("Seg fault!\n");
        return 1;
    }
  
     // count letters
    int letters = count_letters(text);
    //count words
    int words = count_words(text);
    //count sentences
    int sentences = count_sentences(text);

    // find the average number of sentences and letters per 100 words in the text.
    double L = (double)letters / words * 100;
    double S = (double)sentences / words * 100;

    // calculate the grade
    double index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // print the grade
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    free(text);

}

char *get_string(char *str)
{
    printf("%s", str);
    int n = sizeof(char) * 1000;
    char *text = malloc(n);
    fgets(text, n, stdin);

    return text;
}

int count_letters(char *text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // is alpha looks for alphabetical characters
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(char *text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        // isspace looks for newlines, spaces, and tabs;
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(char *text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}