#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * This program encrypts messages using Vigenere’s cipher
 */

string changeKeywordStringToNumber(string keyword);


int main(int argc, string argv[])
{
    string filename = argv[0];
    string keyword = argv[1];
    int keywordLength = strlen(keyword);

    // checks if it is one command-line argument
    if (argc != 2)
    {
        printf("Usage: %s k \n", filename);
        return 1;
    }

    // checks if one command-line argument is alphabet
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Wrong type command-line argument\n");
            return 1;
        }
    }
    keyword = changeKeywordStringToNumber(keyword);

    string plaintext = get_string("plaintext: ");
    int plaintextLength = strlen(plaintext);
    for (int i = 0, j = 0; i < plaintextLength + 1; i++)
    {
        if (j >= keywordLength)
        {
            j = 0;
        }
        if (j < keywordLength)
        {
            if (isalpha(plaintext[i]))
            {
                if (isalpha(plaintext[i] + keyword[j]))
                {
                    printf("%c",  plaintext[i] + keyword[j]);
                    j++;
                }
                else
                {
                    printf("%c",  plaintext[i] + keyword[j] - 26);
                    j++;
                }
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }

    }
    printf("\n");
    return 0;
}

string changeKeywordStringToNumber(string keyword)
{
    // program starts here
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        if (isupper(keyword[i]))
        {
            keyword[i] = keyword[i] - 'A';
        }
        else
        {
            keyword[i] = keyword[i] - 'a';
        }
    }
    return keyword;
}
