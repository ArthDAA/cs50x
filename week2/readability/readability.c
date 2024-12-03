#include <cs50.h>
#include <stdio.h>

int letters_number(char *str)
{
    int i = 0;
    int cmptr = 0;

    while (str[i] != '\0')
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            cmptr++;
        }
        i++;
    }
    return cmptr;
}

int word_number(char *str)
{
    int i = 0;
    int cmptr = 0;
    int in_word = 0;

    while (str[i] != '\0')
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            if (!in_word)
            {
                cmptr++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
        }
        i++;
    }
    return cmptr;
}

int sentences_number(char *str)
{
    int i = 0;
    int cmptr = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            cmptr++;
        }
        i++;
    }
    return cmptr;
}

int coleman_liau(int letters, int words, int sentences)
{
    int l;
    int s;
    float final_value;

    l = ((float) letters / words) * 100;
    s = ((float) sentences / words) * 100;

    final_value = (0.0588 * l) - (0.296 * s) - 15.8;
    if (final_value >= 7 && final_value < 8)
        final_value++;
    return (int) (final_value + 0.5);
}

int main()
{
    char *str = get_string("Text: ");
    int letters = letters_number(str);
    int words = word_number(str);
    int sentences = sentences_number(str);
    int score = coleman_liau(letters, words, sentences);
    if (score < 1)
        printf("Before Grade 1\n");
    else if (score > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %d\n", score);
}
