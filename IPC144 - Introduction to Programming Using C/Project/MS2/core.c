/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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

#include "core.h"
#include <stdio.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

int num, flag, i, j, string_Length, include_Space, invalid_string;
char character, secondChar;
char string[] = {0};


// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ;// do nothing!
    }
    
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
    
}



int inputInt(void){

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
    
    flag = 0;
    character ='x';
    
    do {
        scanf(" %c",&character);
        
        for (i = 0; string[i] != '\0'; i++)
        {
            
            if (character == string[i])
            {
                flag = 1;
            }
            
        }
        
        if (flag != 1)
        {
            printf("ERROR: Character must be one of [");
           
            for (i = 0; string[i] != '\0'; i++)
            {
                printf("%c", string[i]);
            }
                   
            printf("]: ");
        }
        
    }while(flag != 1);
        

    return character;
        
}



void inputCString(char *ptr, int min_characterLength, int max_characterLength)
{

    flag = 0;
    
    do {
        include_Space = 0;
        string_Length = 0;
        scanf(" %[^\n]", string);
        for (i = 0; string[i] != '\0'; i++)
        {
            if (string[i] == ' ')
            {
                include_Space = 1;
            }
            
            string_Length ++;
            
        }
        if (string_Length > max_characterLength && include_Space == 1)
        {
            printf("ERROR: String length must be no more than %d chars: ", max_characterLength);
        }
        else if (string_Length < min_characterLength || string_Length > max_characterLength)
        {
            
            if (min_characterLength == max_characterLength)
            {
                printf("ERROR: String length must be exactly %d chars: ", min_characterLength);
            }
            else
            {
                printf("ERROR: String length must be between %d and %d chars: ", min_characterLength, max_characterLength);
                
            }
        }
        else
        {
            for (i = 0; string[i] != '\0'; i++)
            {
                ptr[i] = string[i];
            }
            
            ptr[string_Length] = '\0';
                
            flag = 1;
        }
           
        
    }while(flag != 1);
    
    
};


void displayFormattedPhone(const char *phoneNumber)
{
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
