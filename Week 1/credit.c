#include <stdio.h>
#include <stdlib.h>

int check_card(long);
void find_card_type(long);

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
    int checksum = 0;
    int digit_counter = 0;

    // used to determine digit's position as the second digit must be doubled
    int is_second_digit = 0;

    while (card_number > 0)
    {
        // finds the first digit from the back and removes it from the original card number
        int digit = card_number % 10;
        card_number /= 10;

        if (is_second_digit) {
            digit *= 2;

            // slices big numbers (>10) into products of the number
            // applicable only to the every other digit
            if (digit > 9) {
                digit = digit % 10 + 1;
            }
        }

        checksum += digit;
        is_second_digit = !is_second_digit;
        digit_counter++;

    }

    if (digit_counter < 13 || digit_counter > 16 || checksum % 10 != 0)
    {
        return(1);
    }

    else
    {
        return(0);
    }
}

void find_card_type(long card_number)
    {
    int card_num_length = 0;
    long card_copy = card_number;
    while (card_copy > 0)
    {
        card_copy /= 10;
        card_num_length++;
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
    }
    // all Mastercard cards are 16 digits long and start with 51-55
    else if (card_num_length == 16 && (51 <= starting_digits && starting_digits <= 55)) {
        printf("MASTERCARD\n");
    }
    // all VISA cards are 13 or 16 digits long and start with 4
    else if ((card_num_length == 13 || card_num_length == 16) && starting_digits / 10 == 4) {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    }