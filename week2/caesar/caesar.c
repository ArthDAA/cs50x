#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *caesar(char *str, int code);

int main(int argc, char **argv)
{
    int code;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int i = 0;
    while (argv[1][i] != '\0')
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key (key must be a number)\n");
            return 1;
        }
        i++;
    }

    code = atoi(argv[1]) % 26;
    if (code >= 1 && code <= 26)
    {
        char *str = get_string("plaintext:  ");
        printf("ciphertext: %s\n", caesar(str, code));
    }
    else
    {
        printf("Usage: ./caesar key (key must be between 1 and 26)\n");
        return 1;
    }
}

char *caesar(char *str, int code)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = ((str[i] - 'A' + code) % 26 + 26) % 26 + 'A';
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = ((str[i] - 'a' + code) % 26 + 26) % 26 + 'a';
        }
        i++;
    }
    return str;
}
