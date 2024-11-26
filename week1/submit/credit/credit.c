#include <stdio.h>
#include <cs50.h>

int luhn(long cnb);
void check_card_type(long cnb);

int luhn(long cnb)
{
    int sum = 0;
    int digit;
    int alternate = 0;

    while (cnb > 0)
    {
        digit = cnb % 10;

        if (alternate == 1)
        {
            digit = digit * 2;
            if (digit > 9)
            {
                digit = (digit % 10) + 1;
            }
        }

        sum = sum + digit;
        cnb = cnb / 10;
        alternate = 1 - alternate;
    }

    return (sum % 10 == 0);
}

void check_card_type(long cnb)
{
    int length = 0;
    long temp = cnb;

    while (temp > 0)
    {
        temp = temp / 10;
        length = length + 1;
    }

    int first_two_digits = cnb / 100000000000000L;
    int first_digit = cnb / 1000000000000000L;

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main()
{
    long cnb;

    while (1)
    {
        cnb = get_long("Number: ");
        
        int length = 0;
        long temp = cnb;

        while (temp > 0)
        {
            temp = temp / 10;
            length = length + 1;
        }

        if (length == 13 || length == 15 || length == 16)
        {
            break;
        }
        else
        {
            printf("INVALID\n");
        }
    }

    if (luhn(cnb))
    {
        check_card_type(cnb);
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
