/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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
#define numOfItems_Max 10


#include <stdio.h>
const double monthlyIncome_Min = 500, monthlyIncome_Max = 400000, valueOfItem_Min = 100;
double monthlyIncome = 0, sumOfCost = 0, totalCostByPriority = 0;
int numOfItems = 0, i, selection, isQuit = 0, priority = 0, forecastYear = 0, forecastMonth = 0, isPrint = 0;
char financingOpt;

int main(void)
{
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    
    do{
        printf("\nEnter your monthly NET income: $");
        scanf("%lf",&monthlyIncome);
        if (monthlyIncome < monthlyIncome_Min)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        else if (monthlyIncome > monthlyIncome_Max)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
        
    }while (monthlyIncome < monthlyIncome_Min || monthlyIncome > monthlyIncome_Max);
    
    
    do{
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d",&numOfItems);
        if (numOfItems < 1 || numOfItems > numOfItems_Max)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
        
        
    }while (numOfItems < 1 || numOfItems > numOfItems_Max);
   
    double table [numOfItems][3];
    
    for (i = 0 ; i < numOfItems ; i++)
    {
        printf("\nItem-%d Details:\n",i+1);
       
        do{
            printf("   Item cost: $");
            scanf("%lf",&table[i][0]);
            if (table [i][0] < valueOfItem_Min )
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
            else
            {
                sumOfCost += table[i][0];
            }
        }while (table[i][0] < valueOfItem_Min );
        
        do{
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%lf",&table[i][1]);
            if (table[i][1] < 1 || table[i][1] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        }while (table[i][1] < 1 || table[i][1] > 3);
        
        
       
        do{
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financingOpt);
            if (financingOpt !='y' && financingOpt != 'n')
             {
                 printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
             }
            else
            {
                table[i][2] = (double)financingOpt;
            }
        }while (financingOpt !='y' && financingOpt != 'n');
        
        
    }
   
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i<numOfItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i+1, (int)table[i][1],(char) table[i][2],table[i][0]);
    }
    printf("---- -------- -------- -----------\n");
    
    printf("                      $%11.2lf\n", sumOfCost);
   
    do{
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d",&selection);
        if (selection !=1 && selection !=2 && selection !=0)
        {
            printf("\nERROR: Invalid menu selection.\n");
            isQuit = 0;
        }
        else if (selection == 0)
        {
            isQuit = 1;
        }
        
        if (selection == 1)
        {
            //cal_S_Shirt = (int) (S_Shirt*100+0.5);
            isPrint = 0;
            forecastYear = (int)sumOfCost/monthlyIncome/12;
            forecastMonth = (int)((sumOfCost/monthlyIncome/12 - forecastYear)*12) ;
            
            if ((sumOfCost/monthlyIncome/12-forecastYear)*12 - forecastMonth > 0)
            {
                forecastMonth++;
            }
            printf("\n====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n",sumOfCost);
            printf("Forecast: %d years, %d months\n", forecastYear, forecastMonth);
            for (i = 0; isPrint == 0 && i< numOfItems ; i++)
            {
                if(table[i][2] == 121)
                {
                    isPrint = 1;
                }
            }
            
            if (isPrint == 1)
                {
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
            printf("====================================================\n");
        }
        else if (selection == 2)
        {
            isPrint = 0;
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d",&priority);
            printf("\n====================================================\n");
            if (priority < 1 || priority > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else
            {
                totalCostByPriority = 0;
                printf("Filter:   by priority (%d)\n",priority);
                for (i = 0; i< numOfItems ; i++)
                {
                    if(table[i][1] == priority)
                    {
                        totalCostByPriority += table[i][0];
                        if(table[i][2] == 121)
                        {
                            isPrint = 1;
                        }
                    }
                    
                }
                forecastYear = (int)totalCostByPriority/monthlyIncome/12;
                forecastMonth = (int)((totalCostByPriority/monthlyIncome/12 - forecastYear)*12) ;
                if ((totalCostByPriority/monthlyIncome/12-forecastYear)*12 - forecastMonth > 0)
                {
                    forecastMonth++;
                }
                printf("Amount:   $%1.2lf\n", totalCostByPriority);
                printf("Forecast: %d years, %d months\n", forecastYear, forecastMonth);
                if (isPrint == 1)
                    {
                        printf("NOTE: Financing options are available on some items.\n");
                        printf("      You can likely reduce the estimated months.\n");
                    }
                printf("====================================================\n");
    
            }
        
            
        }
        
    }while (isQuit==0);
    
    printf("\nBest of luck in all your future endeavours!\n");
    return 0;
           
    
}
