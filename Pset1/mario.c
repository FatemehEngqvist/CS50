#include <cs50.h>
#include <stdio.h>

/* 
 * This program prints out a double half-pyramid of a specified height (max 23).
 */

int main(void)
{
    int height, row;
    
    // checks if the height is between 1 and 23
    do
    {
        height = get_int("Please choose a non-negative integer no greater than 23: ");
    }
    while (height > 23 || height < 1);
    
    // prints the pyramid
    for (row = 0; row < height ; row++)
    {
        for (int i = row + 1 ; i < height ; i++)
        {
            printf(" ");
        }
        for (int j = height - row - 1 ; j < height  ; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = height - row - 1 ; j < height  ; j++)
        {
            printf("#");
        }
        for (int i = row + 1 ; i < height ; i++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
