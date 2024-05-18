/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    int isQuit = 0;
    int numOfIteration = 0;
    char desiredLoopType;
    
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    
    while (isQuit != 1)
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &desiredLoopType, &numOfIteration);
        
        if (desiredLoopType == 'Q')
        {
            if(numOfIteration == 0)
            {
                printf("\n+--------------------+\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n");
                isQuit = 1;
            }
            else
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            }
        }
        else if (desiredLoopType == 'D'|| desiredLoopType =='W'||desiredLoopType == 'F')
        {
            
            if (numOfIteration >=3 && numOfIteration <=20)
            {
                switch (desiredLoopType)
                {
                        
                    case 'D':{
                        printf("DO-WHILE: ");
                        do {
                            printf("D");
                            numOfIteration--;
                        }
                        while (numOfIteration > 0);
                        printf("\n\n");
                        break;
                    }
                    case 'W':
                        
                        printf("WHILE   : ");
                        while (numOfIteration > 0)
                        {
                            printf("W");
                            numOfIteration--;
                        }
                        printf("\n\n");
                        break;
                        
                    case 'F':
                        printf("FOR     : ");
                        for (isQuit = 0; isQuit < numOfIteration ; isQuit++)
                        {
                            printf("F");
                        }
                        printf("\n\n");
                        break;
                }
            }
            
            else
            {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
        
        
    }
    
    
    return 0;
}
