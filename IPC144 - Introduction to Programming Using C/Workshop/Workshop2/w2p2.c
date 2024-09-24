/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    float S_Shirt;
    float M_Shirt;
    float L_Shirt;
    float cal_S_Shirt;
    float cal_M_Shirt;
    float cal_L_Shirt;
    float subTotal_Patty;
    float subTotal_Tommy;
    float subTotal_Sally;
    float subTotal;
    float taxes_Patty;
    float taxes_Tommy;
    float taxes_Sally;
    float totalTaxes;
    int numOfShirt_Patty;
    int numOfShirt_Tommy;
    int numOfShirt_Sally;
    int qtyOfCoin;
    double balance;
    
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
    scanf("%d",&numOfShirt_Patty);
    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d",&numOfShirt_Tommy);
    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d",&numOfShirt_Sally);
    //printf("Patty   %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
    printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    subTotal_Patty = cal_S_Shirt/100*numOfShirt_Patty;
    taxes_Patty = (int)(subTotal_Patty*TAX*100+0.5);
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",patSize,cal_S_Shirt/100,numOfShirt_Patty,subTotal_Patty,taxes_Patty/100,subTotal_Patty+taxes_Patty/100);
    
    subTotal_Sally = cal_M_Shirt/100*numOfShirt_Sally;
    taxes_Sally = (int)(subTotal_Sally*TAX*100+0.5);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",salSize,cal_M_Shirt/100,numOfShirt_Sally,subTotal_Sally,taxes_Sally/100,subTotal_Sally+taxes_Sally/100);
           
    subTotal_Tommy = cal_L_Shirt/100*numOfShirt_Tommy;
    taxes_Tommy = (int)(subTotal_Tommy*TAX*100+0.5);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",tomSize,cal_L_Shirt/100,numOfShirt_Tommy,subTotal_Tommy,taxes_Tommy/100,subTotal_Tommy+taxes_Tommy/100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    subTotal = subTotal_Patty+subTotal_Sally+subTotal_Tommy;
    totalTaxes = (taxes_Patty+taxes_Sally+taxes_Tommy)/100;
    printf("%33.4lf %9.4lf %9.4lf\n\n",subTotal,totalTaxes,subTotal+totalTaxes);
    
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n",subTotal);
    qtyOfCoin = subTotal/2;
   // balance = (int)(subTotal*100)%200;
    balance = subTotal-qtyOfCoin*2;
    printf("Toonies  %3d %9.4lf\n",qtyOfCoin,balance);
    
    qtyOfCoin = balance/1;
    balance = balance - qtyOfCoin*1;
    printf("Loonies  %3d %9.4lf\n",qtyOfCoin,balance);
    
    qtyOfCoin = balance/0.25;
    balance = balance - qtyOfCoin*0.25;
    printf("Quarters %3d %9.4lf\n",qtyOfCoin,balance);
    
    qtyOfCoin = balance/0.1;
    balance = balance - qtyOfCoin*0.1;
    printf("Dimes    %3d %9.4lf\n",qtyOfCoin,balance);

    qtyOfCoin = balance/0.05;
    balance = balance - qtyOfCoin*0.05;
    printf("Nickels  %3d %9.4lf\n",qtyOfCoin,balance);
    
    qtyOfCoin = balance/0.01;
    balance = balance - qtyOfCoin*0.01;
    printf("Pennies  %3d %9.4lf\n\n",qtyOfCoin,balance);
    printf("Average cost/shirt: $%.4f\n",subTotal/(numOfShirt_Patty+numOfShirt_Sally+numOfShirt_Tommy));
    
    printf("\nSales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n",subTotal+totalTaxes);
    
    qtyOfCoin = (subTotal+totalTaxes)/2;
   // balance = (int)(subTotal*100)%200;
    balance = (subTotal+totalTaxes)-qtyOfCoin*2;
    printf("Toonies  %3d %9.4lf\n",qtyOfCoin,balance);
    
    qtyOfCoin = balance/1;
    balance = balance - qtyOfCoin*1;
    printf("Loonies  %3d %9.4lf\n",qtyOfCoin,balance);
    
    qtyOfCoin = balance/0.25;
    balance = balance - qtyOfCoin*0.25;
    printf("Quarters %3d %9.4lf\n",qtyOfCoin,balance);
    
    qtyOfCoin = balance/0.1;
    balance = balance - qtyOfCoin*0.1;
    printf("Dimes    %3d %9.4lf\n",qtyOfCoin,balance);

    qtyOfCoin = balance/0.05;
    balance = balance - qtyOfCoin*0.05;
    printf("Nickels  %3d %9.4lf\n",qtyOfCoin,balance);
    
    qtyOfCoin = balance/0.01;
    balance = balance - qtyOfCoin*0.01;
    printf("Pennies  %3d %9.4lf\n\n",qtyOfCoin,balance);
    printf("Average cost/shirt: $%.4f\n",(subTotal+totalTaxes)/(numOfShirt_Patty+numOfShirt_Sally+numOfShirt_Tommy));
    
    return 0;
}

