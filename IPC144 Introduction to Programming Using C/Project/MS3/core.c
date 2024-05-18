/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :TSZ WA WONG
Student ID#:152181228
Email      :twwong9@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"



//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

int inputInt(void){

    char secondChar;
    int flag, num;
    flag = 0;
    num = -1;
    secondChar ='x';
    do {
        
    if(scanf("%d%c", &num, &secondChar) != 2 || secondChar != '\n')
    {
        printf("Error! Input a whole number: ");
        clearInputBuffer();
    }
    else
    {
        flag = 1;
    }
    
    }while (flag != 1);
    
    return num;
    
}

int inputIntPositive(void){
   
    char secondChar;
    int flag, num;
    flag = 0;
    num = -1;
    secondChar ='x';
    do {
        
    if(scanf("%d%c", &num, &secondChar) != 2 || secondChar != '\n')
    {
        printf("Error! Input a whole number: ");
        clearInputBuffer();
    }
    else
    {
        if (num <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
        else
        {
            flag = 1;
        }
    }
    
    }while (flag != 1);
    
    return num;
    
}

int inputIntRange(int lowerBound, int upperBound){
    
    char secondChar;
    int flag, num;
    flag = 0;
    num = -1;
    secondChar ='x';
    
    do {
        
    if(scanf("%d%c", &num, &secondChar) != 2 || secondChar != '\n')
    {
        printf("Error! Input a whole number: ");
        clearInputBuffer();
    }
    else
    {
        if (num < lowerBound || num > upperBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ",lowerBound,upperBound);
        }
        else
        {
            flag = 1;
        }
    }
    
    }while (flag != 1);
    
    return num;
    

}

char inputCharOption(const char string[]){
    
    int flag, i;
    char characterInput[] = {0};
    flag = 0;
    
    do {
        
        scanf(" %s",characterInput);
        if (strlen(characterInput) > 1)
        {
            printf("ERROR: Character must be one of [%s]: ", string);
            clearInputBuffer();
        }
        else
        {
            for (i = 0; string[i] != '\0'; i++)
            {
               if (characterInput[0] == string[i])
               {
                   flag = 1;
                   
               }
            }
            if (!flag)
            {
                printf("ERROR: Character must be one of [%s]: ", string);
            }
        }
        
      
        
    }while(flag != 1);
        
    return characterInput[0];
}

void inputCString(char *ptr, int min_characterLength, int max_characterLength)
{
    char character = 'x';
    int flag = 0, invalid = 0;
    while (flag != 1)
    {
        int string_Length = 0;
        invalid = 0;
        while (character != '\n' && string_Length < max_characterLength + 1)
        {
            character = getchar();
            ptr[string_Length] = character;
            string_Length++;
        };
        
        if (character == '\n' && string_Length - 1 <= max_characterLength)
        {
            ptr[string_Length - 1] = '\0';
        }
        else
        {
             ptr[max_characterLength] = '\0';
             invalid = 1;
             clearInputBuffer();
        }
        
            if (min_characterLength == max_characterLength && string_Length - 1 != max_characterLength)
            {
                printf("ERROR: String length must be exactly %d chars: ", max_characterLength );
                character = 'x';
            }
            else if(invalid)
            {
                if (string_Length > max_characterLength)
                {
                    printf("ERROR: String length must be no more than %d chars: ", max_characterLength);
                    character = 'x';
                }
                else if (string_Length - 1 < min_characterLength)
                {
                    printf("ERROR: String length must be between %d and %d chars: ", min_characterLength, max_characterLength);
                    character = 'x';
                }
               
            }
            else
            {
                flag = 1;
            }
        
    }
}


void inputCStringNumber(char *ptr, int min_characterLength, int max_characterLength)
{
    char character = 'x';
    int flag = 0, invalid = 0;;
    while (flag != 1)
    {
        int string_Length = 0;
        invalid = 0;
        while (character != '\n' && string_Length < max_characterLength + 1)
        {
            character = getchar();
            ptr[string_Length] = character;
            string_Length++;
        };
        
        if (character == '\n' && string_Length <= (max_characterLength + 1))
        {
            ptr[string_Length - 1] = '\0';
        }
        else
        {
            ptr[max_characterLength] = '\0';
            invalid = 1;
            clearInputBuffer();
        }
        
        if ((min_characterLength == max_characterLength && string_Length - 1 != max_characterLength ) || invalid == 1)
        {
            printf("Invalid 10-digit number! Number: ");
            character = 'x';
        }
        else
        {
            flag = 1;
        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

void displayFormattedPhone(const char *phoneNumber)
{
    int invalid_string,string_Length,i;
    invalid_string = 0;
    string_Length = 0;

        if (phoneNumber != NULL)
        {
            for (i = 0; phoneNumber[i] != '\0'; i++)
            {
                if ((phoneNumber[i] != '0') && (phoneNumber[i] != '1') && (phoneNumber[i] != '2') && (phoneNumber[i] != '3') && (phoneNumber[i] != '4') && (phoneNumber[i] != '5') && (phoneNumber[i] != '6') && (phoneNumber[i] != '7') && (phoneNumber[i] != '8') && (phoneNumber[i] != '9'))
                {
                    invalid_string = 1;
                }
                string_Length ++;
                 
            }
            
        }
        else
        {
            invalid_string = 1;
        }
        
        if (invalid_string == 1 || string_Length != 10 || string_Length == 0)
        {
            printf("(___)___-____");
        }
        else
        {
            printf("(");
            for (i = 0; i < 3; i++)
            {
                printf("%c", phoneNumber[i]);
            }
            printf(")");
            for (i = 3; i < 6; i++)
            {
                printf("%c", phoneNumber[i]);
            }
            printf("-");
            for (i = 6; i < 10; i++)
            {
                printf("%c", phoneNumber[i]);
            }
            
            
        }
    
}
