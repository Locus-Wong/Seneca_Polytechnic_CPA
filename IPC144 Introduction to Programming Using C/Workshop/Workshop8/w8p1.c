/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

int enter_int_Num, i;
double enter_double_Num;
struct CatFoodInfo catFood[max_number_product] = {{0}};

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *int_Num) // &intA
{
    do{
        scanf("%d", &enter_int_Num);
        if (enter_int_Num <= 0)
        {
            printf("ERROR: Enter a positive value: ");
            
        }
    }
    while (enter_int_Num <= 0);
    
    if (int_Num != NULL)
    {
        *int_Num = enter_int_Num;
    }
    // pointer argument = entered value
    return enter_int_Num;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double *double_Num)
{
    do{
        scanf("%lf", &enter_double_Num);
        if (enter_double_Num <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
    }
    while (enter_double_Num <= 0);
    
    if (double_Num != NULL)
    {
        *double_Num = enter_double_Num;
    }
    // pointer argument = entered value
    return enter_double_Num;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numOfProduct)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n",numOfProduct);
    printf("NOTE: A 'serving' is %dg\n",num_of_grams);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence_Num) // i:1,2,3
{
        printf("\nCat Food Product #%d\n", sequence_Num);
        printf("--------------------\n");
        
        printf("SKU           : ");
        getIntPositive(&catFood[sequence_Num-1].sku);

        printf("PRICE         : $");
        getDoublePositive(&catFood[sequence_Num-1].price);
    
        printf("WEIGHT (LBS)  : ");
        catFood[sequence_Num-1].weight = getDoublePositive(NULL);
    
        printf("CALORIES/SERV.: ");
        catFood[sequence_Num-1].calories = getIntPositive(NULL);
    
    return catFood[sequence_Num-1];
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData (int sku, double *price, double *weight, int calories)
{
    printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calories);

       // sku, calaories pass by value
       // price, weight pass by address
    
}
// 7. Logic entry point
int start(void)
{
    openingMessage(max_number_product);
    
    for (i = 1 ; i <= max_number_product; i++)
    {
        getCatFoodInfo(i);
    }
    
    printf("\n");
    displayCatFoodHeader();
    
    for (i = 0 ; i < max_number_product; i++)
    {
        displayCatFoodData(catFood[i].sku, &catFood[i].price, &catFood[i].weight, catFood[i].calories);
    }
    
    return 0;
}
