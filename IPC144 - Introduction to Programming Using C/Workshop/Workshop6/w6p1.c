/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
double monthlyIncome, sumOfCost;
int numOfItems, i;
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
    
    printf("                      $%11.2lf\n\n", sumOfCost);
    printf("Best of luck in all your future endeavours!\n");
   
   
    
    return 0;
}
