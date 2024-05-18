/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  :TSZ WA WONG
Student ID#:152181228
Email      :twwong9@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int numOfApples, numOfApples_Pick;
int numOfOranges, numOfOranges_Pick;
int numOfPears, numOfPears_Pick;
int numOfTomatoes, numOfTomatoes_Pick;
int numOfCabbages, numOfCabbages_Pick;
int doAnothershopping = 0;

int main(void)
{
    do{
        printf("Grocery Shopping\n");
        printf("================\n");
        
        do {
            printf("How many APPLES do you need? : ");
            scanf("%d",&numOfApples);
            if (numOfApples <0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            
        }while (numOfApples< 0);
        printf("\n");
        
        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d",&numOfOranges);
            if (numOfOranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        }while (numOfOranges< 0);
        printf("\n");
        
        do{
            printf("How many PEARS do you need? : ");
            scanf("%d",&numOfPears);
            if (numOfPears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            
        }while (numOfPears < 0);
        printf("\n");
        
        do{
            printf("How many TOMATOES do you need? : ");
            scanf("%d",&numOfTomatoes);
            if (numOfTomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        }while (numOfTomatoes < 0);
        printf("\n");
        
        do{
            printf("How many CABBAGES do you need? : ");
            scanf("%d",&numOfCabbages);
            if (numOfCabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        }while (numOfCabbages < 0);
        printf("\n");
        
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");
        
        if (numOfApples > 0)
        {
            
            while (numOfApples > 0)
            {
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d",&numOfApples_Pick);
                if (numOfApples_Pick > numOfApples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n",numOfApples);
                }
                else if (numOfApples_Pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (numOfApples_Pick == numOfApples)
                {
                    printf("Great, that's the apples done!\n\n");
                    numOfApples = 0;
                }
                else
                {
                    printf("Looks like we still need some APPLES...\n");
                    numOfApples -= numOfApples_Pick;
                }
            }
            
        }
        
        
        if (numOfOranges> 0)
        {
            while (numOfOranges > 0)
            {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d",&numOfOranges_Pick);
                if (numOfOranges_Pick > numOfOranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n",numOfOranges);
                }
                else if (numOfOranges_Pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (numOfOranges_Pick == numOfOranges)
                {
                    printf("Great, that's the oranges done!\n\n");
                    numOfOranges = 0;
                }
                else
                {
                    printf("Looks like we still need some ORANGES...\n");
                    numOfOranges -= numOfOranges_Pick;
                }
            }
        }
        
        if (numOfPears > 0)
        {
            while (numOfPears > 0)
            {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d",&numOfPears_Pick);
                if (numOfPears_Pick > numOfPears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n",numOfPears);
                }
                else if (numOfPears_Pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (numOfPears_Pick == numOfPears)
                {
                    printf("Great, that's the pears done!\n\n");
                    numOfPears = 0;
                }
                else
                {
                    printf("Looks like we still need some PEARS...\n");
                    numOfPears -= numOfPears_Pick;
                }
            }
        }
        
        if (numOfTomatoes > 0)
        {
            while (numOfTomatoes > 0)
            {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d",&numOfTomatoes_Pick);
                if (numOfTomatoes_Pick > numOfTomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n",numOfTomatoes);
                }
                else if (numOfTomatoes_Pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (numOfTomatoes_Pick == numOfTomatoes)
                {
                    printf("Great, that's the tomatoes done!\n\n");
                    numOfTomatoes = 0;
                }
                else
                {
                    printf("Looks like we still need some TOMATOES...\n");
                    numOfTomatoes -= numOfTomatoes_Pick;
                }
            }
        }
        
        if (numOfCabbages > 0)
        {
            while (numOfCabbages > 0)
            {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d",&numOfCabbages_Pick);
                if (numOfCabbages_Pick > numOfCabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n",numOfCabbages);
                }
                else if (numOfCabbages_Pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else if (numOfCabbages_Pick == numOfCabbages)
                {
                    printf("Great, that's the cabbages done!\n\n");
                    numOfCabbages = 0;
                }
                else
                {
                    printf("Looks like we still need some CABBAGES...\n");
                    numOfCabbages -= numOfCabbages_Pick;
                }
            }
        }
        
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &doAnothershopping);
        if (doAnothershopping == 1)
        {
            printf("\n");
        }
    }while (doAnothershopping == 1);
    
    printf("\nYour tasks are done for today - enjoy your free time!\n");
    return 0;
}
