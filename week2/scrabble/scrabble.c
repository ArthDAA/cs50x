#include <cs50.h>
#include <stdio.h>

int get_letter_value (char c)
{
	
    if (c >= 'a' && c <= 'z') 
		c = c - 32;
    if (c >= 'A' && c <= 'Z') 
	{
        int letter_values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
        return letter_values[c - 'A'];
    }
    return 0;
}


void test(char *str1, char *str2)
{
	int score1;
	int score2;
	int i;

	score1 = 0;
	score2 = 0;
	i = 0;
	while (str1[i] != '\0')
	{
		score1 = score1 + get_letter_value(str1[i]);
		i++;
	}
	i = 0;
	while (str2[i] != '\0')
	{
		score2 = score2 + get_letter_value(str2[i]);
		i++;
	}

	if (score1 > score2)
		printf("Player 1 wins!\n");
	else if (score2 > score1)
		printf("Player 2 wins!\n");
	else
		printf("Tie!\n");
}

int main()
{
	char *str1 = get_string ("Player 1: ");
	char *str2 = get_string ("Player 2: ");
	test(str1, str2);
}
