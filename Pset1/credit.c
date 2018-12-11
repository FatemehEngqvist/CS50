#include <stdio.h>
#include <cs50.h>

/*
 * This program validates a credit card number and identifies which company issued the card.
 */

int numberLength(long long cardNumber);
int oddLengthCard(long long cardNumber);
int evenLengthCard(long long cardNumber);
int firstTwoDigits(long long cardNember);
int firstDigits(long long cardNumber);

int main()
{
    long long n = get_long_long("Number: ");
    if (numberLength(n) == 15 && (firstTwoDigits(n) == 34 || firstTwoDigits(n) == 37))
    {
        if (oddLengthCard(n) % 10 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (numberLength(n) == 16 && (firstTwoDigits(n) == 51 || firstTwoDigits(n) == 52 || firstTwoDigits(n) == 53
                                       || firstTwoDigits(n) == 54 || firstTwoDigits(n) == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((numberLength(n) == 13 || numberLength(n) == 16) && firstDigits(n) == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}


int numberLength(long long cardNumber)
{
    int length = 0;
    while (cardNumber != 0)
    {
        cardNumber = cardNumber / 10;
        length++;
    }
    return length;
}

int oddLengthCard(long long cardNumber)
{
    int sumTotal = 0;
    long long cardNumberTemp = cardNumber;
    int sumSecondPositions = 0;
    int sumNotMultiplied = 0;
    while (cardNumberTemp > 0)
    {
        sumNotMultiplied = sumNotMultiplied + cardNumberTemp % 10;
        //printf("sumNotMultiplied is: %i\n", sumNotMultiplied);
        cardNumberTemp = cardNumberTemp / 10;
        int x = (cardNumberTemp % 10) * 2;
        if (x > 9)
        {
            int x1 = x % 10;
            //printf("x1 is %i\n", x1);
            int x2 = x / 10;
            //printf("x2 is %i\n", x2);
            x = x1 + x2;
        }
        sumSecondPositions = sumSecondPositions + x;
        //printf("Second digit multiply by 2: %i\n",x);
        cardNumberTemp = cardNumberTemp / 10;
    }
    sumTotal = sumNotMultiplied + sumSecondPositions;
    return sumTotal;
}

int evenLengthCard(long long cardNumber)
{
    int sumTotal = 0;
    long long cardNumberTemp = cardNumber;
    int sumSecondPositions = 0;
    int sumNotMultiplied = 0;
    while (cardNumberTemp > 0)
    {
        int x = (cardNumberTemp % 10) * 2;
        if (x > 9)
        {
            int x1 = x % 10;
            //printf("x1 is %i\n", x1);
            int x2 = x / 10;
            //printf("x2 is %i\n", x2);
            x = x1 + x2;
        }
        sumSecondPositions = sumSecondPositions + x;
        //printf("Second digit multiply by 2: %i\n",x);
        sumNotMultiplied = sumNotMultiplied + (cardNumberTemp / 10) % 10;
        cardNumberTemp = cardNumberTemp / 100;
    }
    sumTotal = sumNotMultiplied + sumSecondPositions;
    return sumTotal;
}

int firstTwoDigits(long long cardNumber)
{
    long long cardNumberTemp = cardNumber;
    while (cardNumberTemp > 100)
    {
        cardNumberTemp = cardNumberTemp / 10;
    }
    return cardNumberTemp;
}

int firstDigits(long long cardNumber)
{
    long long cardNumberTemp = cardNumber;
    while (cardNumberTemp > 10)
    {
        cardNumberTemp = cardNumberTemp / 10;
    }
    return cardNumberTemp;
}
