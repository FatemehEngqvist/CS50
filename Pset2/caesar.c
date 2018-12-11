#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * This program encrypts messages using Caesar’s cipher
 * the program accepts a single command-line argument, a non-negative integer k
 * and then prompt the user for a string of plaintext and encrypts messages by "rotating" each letter by k positions
 * and prints the the output.
 */

void caeser_encrypt(string text,int key);

int main (int argc, string argv[])
{
    // checks if it is one command-line argument
    if (argc != 2)
    {
        printf("Usage: %s k \n", argv[0]);
        return 1;
    }

    int k = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    caeser_encrypt(plaintext, k);
    printf("\n");
    return 0;
}

// This function "rotates" each letter by key positions and prints the the output
void caeser_encrypt(string plaintext,int key)
{
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isalpha(plaintext[i] + key))
            {
                printf("%c",  plaintext[i] + key);
            }
            else
            {
                printf("%c",  plaintext[i] + key - 26);
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
}
