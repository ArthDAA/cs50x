#include <stdio.h>
#include <cs50.h>

int main()
{
    int nbr = 0;
    while (nbr < 1 || nbr > 8)
        nbr = get_int("Number : ");
    
    int i = 0;
    int j = 0;
    int space = nbr - 1;
    int ref = space;
    int hashtag = 0;
    while(i != nbr)
    {
        while(j != nbr)
        {
            while(space != 0)
            {
                printf(" ");
                space--;
                j++;
            }
            printf("#");
            j++;
            hashtag++;
        }
        printf(" ");
        while (hashtag != 0)
        {
            printf("#");
            hashtag--;
        }
        printf("\n");
        j = 0;
        space = ref - 1;
        hashtag = 0;
        ref--;
        i++;
    }
}