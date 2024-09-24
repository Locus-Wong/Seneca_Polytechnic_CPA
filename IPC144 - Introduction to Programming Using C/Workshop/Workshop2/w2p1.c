/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    float S_Shirt;
    float M_Shirt;
    float L_Shirt;
    float cal_S_Shirt;
    float cal_M_Shirt;
    float cal_L_Shirt;
    float subTotal;
    float taxes;
    int numOfShirt;
    
    printf("Set Shirt Prices\n");
    printf("================\n");
    
    printf("Enter the price for a SMALL shirt: $");
    scanf("%f",&S_Shirt);
    cal_S_Shirt = (int) (S_Shirt*100+0.5);
    
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%f",&M_Shirt);
    cal_M_Shirt = (int) (M_Shirt*100+0.5);

    
    printf("Enter the price for a LARGE shirt: $");
    scanf("%f",&L_Shirt);
    cal_L_Shirt = (int) (L_Shirt*100+0.5);
    
    
    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2f\n",cal_S_Shirt/100);
    printf("MEDIUM : $%.2f\n",cal_M_Shirt/100);
    printf("LARGE  : $%.2f\n\n",cal_L_Shirt/100);
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d",&numOfShirt);
    subTotal = cal_S_Shirt/100*numOfShirt;
    taxes = (int)(subTotal*TAX*100+0.5);
    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n",numOfShirt);
    printf("Sub-total: $%.4f\n",subTotal);
    printf("Taxes    : $ %.4f\n",taxes/100);
    printf("Total    : $%.4f\n",subTotal+taxes/100);
    
              
    


    return 0;
}
