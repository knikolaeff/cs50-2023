#include <stdio.h>
#include <stdlib.h>

int check_card(long);
int find_card_type(long);

int main(void) {
    char buf[32];
    long card_number;

    // prompt for a number and check if the value can be converted to long
    do
    {
        printf("Number: ");
        fgets(buf, sizeof buf, stdin);
        card_number = atol(buf);
    }
    while (card_number <= 0);

    if (check_card(card_number))
    {
        printf("INVALID\n");
        
    }

    else
    {
        find_card_type(card_number);
    }

    return(0);
}

// Luhn's algorithm
int check_card(long card_number)
{
    int first_sum = 0, second_sum = 0;
    long temp = card_number;

    while (temp > 0)
    {
        // first/second from the back
        int first_digit = temp % 10;
        int second_digit = (temp / 10) % 10;

        // removes two digits from the back
        temp /= 100;

        first_sum += first_digit;

        // slices big numbers (>10) into products of the number
        if (second_digit * 2 > 9)
        {
            second_sum += second_digit * 2 / 10;
            second_sum += second_digit * 2 % 10;
        }

        else
        {
            second_sum += second_digit * 2;
        }
    }

    if ((first_sum + second_sum) % 10 != 0)
    {
        return(1);
    }

    else
    {
        return(0);
    }
}

int find_card_type(long card_number)
    {
    int card_num_length = 0;
    long temp = card_number;
    while (temp > 0)
    {
        temp /= 10;
        card_num_length += 1;
    }

    long starting_digits = card_number;
    while (starting_digits > 100)
    {
        starting_digits /= 10;
    }

    // all AMEX cards are 15 digits long and start with 34 or 37
    if (card_num_length == 15 && (starting_digits == 34 || starting_digits == 37))
    {
        printf("AMEX\n");
        return(0);
    }
    // all Mastercard cards are 16 digits long and start with 51-55
    else if (card_num_length == 16 && (51 <= starting_digits && starting_digits <= 55)) {
        printf("MASTERCARD\n");
        return(0);
    }
    // all VISA cards are 13 or 16 digits long and start with 4
    else if ((card_num_length == 13 || card_num_length == 16) && starting_digits / 10 == 4) {
        printf("VISA\n");
        return(0);
    }
    else
    {
        printf("INVALID\n");
        return(0);
    }
    }