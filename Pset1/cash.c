#include <stdio.h>
#include <cs50.h>

/*
 * This program asks the user(customer) the amount of money cashier should return in dollars and then
 * using a greedy algorithm counts the number of coins it should return given that the coins are:
 * assuming that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
 */
int main(void)
{
    float input;
    int numberOfCoins = 0;
    do
    {
        input = get_float("How much change do I owe you? ");
    }
    while (input < 0);
    int cash = input * 100;

    // check the number of quarters
    if (cash >= 25)
    {
        numberOfCoins = numberOfCoins + cash / 25;
        cash = cash % 25;
    }

    // check the number of dimes
    if (cash >= 10)
    {
        numberOfCoins = numberOfCoins + cash / 10;
        cash = cash % 10;
    }

    //check the number of nickels
    if (cash >= 5)
    {
        numberOfCoins = numberOfCoins + cash / 5;
        // cash will be the number of pennies now
        cash = cash % 5;
    }

    numberOfCoins = numberOfCoins + cash;
    printf("The number of coins are %i.\n", numberOfCoins);
}
