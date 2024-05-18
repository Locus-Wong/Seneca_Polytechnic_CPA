#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 30

/*
* Find the position of a string in an array of strings.
* @param str - the string to find
* @param list - the list of strings to search
* @param nstrings - the number of strings in the list
* @returns the position of the string in the list or -1 if not found
*/
int findString(const char str[], const char list[][MAX_STRING_LEN + 1], const int nstrings)
{
    int i, result = -1, found = 0;
    for (i = 0; i < nstrings && !found; i++)
    {
        if (0 == strcmp(str, list[i]))
        {
            result = i;
        }
    }
    return result;
}

/*
* Clear input buffer until next newline character.
*/
void clear1(void)
{
    char ch;
    while ((ch = getchar()) != '\n');
}

int main(void)
{
    // Step 1: Set up the testing environment with some assumptions
    int numProducts = 6;
    char descriptions[][MAX_STRING_LEN + 1] =
    {
        "flour",
        "sugar",
        "bananas",
        "potatoes",
        "milk",
        "tea"
    };
    char productName[MAX_STRING_LEN + 1] = { 0 };
    int finished = 0;
    
    // Step 2: Print a welcome message to customers and notify them what items are currently in stock
    printf("Hello customer, Welcome to Seneca Superstore!\n");
    printf("We now have flour, sugar, bananas, potatoes, milk and tea in stock.\n");
    do
    {
    // Step 3: Ask customers to input the items they want to purchase and let them they can enter end if they want to exit
        printf("Please input any item to purchase (end to stop):\n> ");
        scanf("%30[^\n]", productName);
    // Step 4: Clear input buffer after the user input and notify customers system is ready for the next input
        clear1();
        printf("*** System is ready for the next input. ***\n");
        
    // Step 5: If the customers do not enter "end", find the input item if it is in stock or not
        if (!(finished = !strcmp("end", productName)))
        {
           
            int n = findString(productName, descriptions, numProducts);
    // Step 6: If the input item is in stock, tell customers the item is ready to purchase, otherwise, notify the customers that we do not have the item.
            if (n < 0)
            {
                // print the name of item for comparison
                printf("Sorry, we do not have \"%s\"\n", productName);
            }
            else
            {
                // print the name of item for comparison
                printf("\"%s\" is ready to be purchased.\n", productName);
            }
        }
    } while (!finished);
    
    return 0;
}
    
    

