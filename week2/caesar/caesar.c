#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

char *caesar(char *str, int code);

int main(int argc, char **argv)
{
    int code;
    if (argc = 2)
    {
        code = atoi(argv[1]) % 26;
        if (code >= 1 && code <= 26)
        {
            char *str = get_string("plaintext:  ");
            printf("ciphertext: %s\n", caesar(str, code));
        }
    }
}

char *caesar(char *str, int code)
{

    int i;
    i = 0;
    while(str[i] != '\0')
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] = str[i] + code;
        }
        i++;
    }
    return str;
}