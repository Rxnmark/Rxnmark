#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float l = letters / words;    float s = sentences / words;
    float index = 5.88 * l - 29.6 * s - 15.8;
    int i = (int)(index < 0 ? (index - 0.5) : (index + 0.5));
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] != ' ' && isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ' && i > 0)
        {
            words++;
        }
    }
    words++;
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
