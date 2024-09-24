/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char sellCoffeeType_1,sellCoffeeType_2,sellCoffeeType_3;
    char servedWithCream_1,servedWithCream_2,servedWithCream_3;
    int bagWeight_1,bagWeight_2,bagWeight_3;
    
    char preferCoffeeStrength;
    char preferWithCream;
    int preferDailyServings;
    

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&sellCoffeeType_1);
    printf("Bag weight (g): ");
    scanf("%d",&bagWeight_1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c",&servedWithCream_1);
    
    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&sellCoffeeType_2);
    printf("Bag weight (g): ");
    scanf("%d",&bagWeight_2);
   printf("Best served with cream ([Y]es,[N]o): ");
   scanf(" %c",&servedWithCream_2);
    
    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c",&sellCoffeeType_3);
    printf("Bag weight (g): ");
    scanf("%d",&bagWeight_3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c",&servedWithCream_3);
    
    
    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",sellCoffeeType_1=='l'||sellCoffeeType_1=='L',sellCoffeeType_1=='m'||sellCoffeeType_1=='M',sellCoffeeType_1=='r'||sellCoffeeType_1=='R',bagWeight_1,bagWeight_1/GRAMS_IN_LBS,servedWithCream_1=='y'||servedWithCream_1=='Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",sellCoffeeType_2=='l'||sellCoffeeType_2=='L',sellCoffeeType_2=='m'||sellCoffeeType_2=='M',sellCoffeeType_2=='r'||sellCoffeeType_2=='R',bagWeight_2,bagWeight_2/GRAMS_IN_LBS,servedWithCream_2=='y'||servedWithCream_2=='Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",sellCoffeeType_3=='l'||sellCoffeeType_3=='L',sellCoffeeType_3=='m'||sellCoffeeType_3=='M',sellCoffeeType_3=='r'||sellCoffeeType_3=='R',bagWeight_3,bagWeight_3/GRAMS_IN_LBS,servedWithCream_3=='y'||servedWithCream_3=='Y');
    
    printf("\nEnter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c",&preferCoffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c",&preferWithCream);
    printf("Typical number of daily servings: ");
    scanf(" %d",&preferDailyServings);
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
           ((preferCoffeeStrength == 'l'||preferCoffeeStrength =='L')&& (sellCoffeeType_1 == 'l'||sellCoffeeType_1 == 'L'))||
           ((preferCoffeeStrength == 'm'||preferCoffeeStrength =='M')&& (sellCoffeeType_1 == 'm'||sellCoffeeType_1 == 'M'))||
           ((preferCoffeeStrength == 'r'||preferCoffeeStrength =='R')&& (sellCoffeeType_1 == 'r'||sellCoffeeType_1 == 'R')),
           
           ((preferDailyServings >=1 && preferDailyServings <= 4)&& (bagWeight_1<=250))||
           ((preferDailyServings >=5 && preferDailyServings <= 9)&& (bagWeight_1>250 && bagWeight_1<= 500 ))||
           ((preferDailyServings >=10) && (bagWeight_1>500 && bagWeight_1<=1000)),
    
           ((preferWithCream == 'Y'||preferWithCream =='y')&& (servedWithCream_1 == 'Y'||servedWithCream_1 == 'y'))||
           ((preferWithCream == 'N'||preferWithCream =='n')&& (servedWithCream_1 == 'N'||servedWithCream_1 == 'n')));
           
    printf(" 2|       %d         |      %d      |   %d   |\n",
           ((preferCoffeeStrength == 'l'||preferCoffeeStrength =='L')&& (sellCoffeeType_2 == 'l'||sellCoffeeType_2 == 'L'))||
           ((preferCoffeeStrength == 'm'||preferCoffeeStrength =='M')&& (sellCoffeeType_2 == 'm'||sellCoffeeType_2 == 'M'))||
           ((preferCoffeeStrength == 'r'||preferCoffeeStrength =='R')&& (sellCoffeeType_2 == 'r'||sellCoffeeType_2 == 'R')),
           
           ((preferDailyServings >=1 && preferDailyServings <= 4)&& (bagWeight_2<=250))||
           ((preferDailyServings >=5 && preferDailyServings <= 9)&& (bagWeight_2>250 && bagWeight_2<= 500 ))||
           ((preferDailyServings >=10) && (bagWeight_2>500 && bagWeight_2<=1000)),
    
           
           ((preferWithCream == 'Y'||preferWithCream =='y')&& (servedWithCream_2 == 'Y'||servedWithCream_2 == 'y'))||
           ((preferWithCream == 'N'||preferWithCream =='n')&& (servedWithCream_2 == 'N'||servedWithCream_2 == 'n')));
    
    printf(" 3|       %d         |      %d      |   %d   |\n",
           ((preferCoffeeStrength == 'l'||preferCoffeeStrength =='L')&& (sellCoffeeType_3 == 'l'||sellCoffeeType_3 == 'L'))||
           ((preferCoffeeStrength == 'm'||preferCoffeeStrength =='M')&& (sellCoffeeType_3 == 'm'||sellCoffeeType_3 == 'M'))||
           ((preferCoffeeStrength == 'r'||preferCoffeeStrength =='R')&& (sellCoffeeType_3 == 'r'||sellCoffeeType_3 == 'R')),
           
           ((preferDailyServings >=1 && preferDailyServings <= 4)&& (bagWeight_3<=250))||
           ((preferDailyServings >=5 && preferDailyServings <= 9)&& (bagWeight_3>250 && bagWeight_3<= 500 ))||
           ((preferDailyServings >=10) && (bagWeight_3>500 && bagWeight_3<=1000)),
    
           
           ((preferWithCream == 'Y'||preferWithCream =='y')&& (servedWithCream_3 == 'Y'||servedWithCream_3 == 'y'))||
           ((preferWithCream == 'N'||preferWithCream =='n')&& (servedWithCream_3 == 'N'||servedWithCream_3 == 'n')));
    
    printf("\nEnter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c",&preferCoffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c",&preferWithCream);
    printf("Typical number of daily servings: ");
    scanf(" %d",&preferDailyServings);
    
    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
           ((preferCoffeeStrength == 'l'||preferCoffeeStrength =='L')&& (sellCoffeeType_1 == 'l'||sellCoffeeType_1 == 'L'))||
           ((preferCoffeeStrength == 'm'||preferCoffeeStrength =='M')&& (sellCoffeeType_1 == 'm'||sellCoffeeType_1 == 'M'))||
           ((preferCoffeeStrength == 'r'||preferCoffeeStrength =='R')&& (sellCoffeeType_1 == 'r'||sellCoffeeType_1 == 'R')),
           
           ((preferDailyServings >=1 && preferDailyServings <= 4)&& (bagWeight_1<=250))||
           ((preferDailyServings >=5 && preferDailyServings <= 9)&& (bagWeight_1>250 && bagWeight_1<= 500 ))||
           ((preferDailyServings >=10) && (bagWeight_1>500 && bagWeight_1<=1000)),
    
           ((preferWithCream == 'Y'||preferWithCream =='y')&& (servedWithCream_1 == 'Y'||servedWithCream_1 == 'y'))||
           ((preferWithCream == 'N'||preferWithCream =='n')&& (servedWithCream_1 == 'N'||servedWithCream_1 == 'n')));
           
    printf(" 2|       %d         |      %d      |   %d   |\n",
           ((preferCoffeeStrength == 'l'||preferCoffeeStrength =='L')&& (sellCoffeeType_2 == 'l'||sellCoffeeType_2 == 'L'))||
           ((preferCoffeeStrength == 'm'||preferCoffeeStrength =='M')&& (sellCoffeeType_2 == 'm'||sellCoffeeType_2 == 'M'))||
           ((preferCoffeeStrength == 'r'||preferCoffeeStrength =='R')&& (sellCoffeeType_2 == 'r'||sellCoffeeType_2 == 'R')),
           
           ((preferDailyServings >=1 && preferDailyServings <= 4)&& (bagWeight_2<=250))||
           ((preferDailyServings >=5 && preferDailyServings <= 9)&& (bagWeight_2>250 && bagWeight_2<= 500 ))||
           ((preferDailyServings >=10) && (bagWeight_2>500 && bagWeight_2<=1000)),
    
           
           ((preferWithCream == 'Y'||preferWithCream =='y')&& (servedWithCream_2 == 'Y'||servedWithCream_2 == 'y'))||
           ((preferWithCream == 'N'||preferWithCream =='n')&& (servedWithCream_2 == 'N'||servedWithCream_2 == 'n')));
    
    printf(" 3|       %d         |      %d      |   %d   |\n",
           ((preferCoffeeStrength == 'l'||preferCoffeeStrength =='L')&& (sellCoffeeType_3 == 'l'||sellCoffeeType_3 == 'L'))||
           ((preferCoffeeStrength == 'm'||preferCoffeeStrength =='M')&& (sellCoffeeType_3 == 'm'||sellCoffeeType_3 == 'M'))||
           ((preferCoffeeStrength == 'r'||preferCoffeeStrength =='R')&& (sellCoffeeType_3 == 'r'||sellCoffeeType_3 == 'R')),
           
           ((preferDailyServings >=1 && preferDailyServings <= 4)&& (bagWeight_3<=250))||
           ((preferDailyServings >=5 && preferDailyServings <= 9)&& (bagWeight_3>250 && bagWeight_3<= 500 ))||
           ((preferDailyServings >=10) && (bagWeight_3>500 && bagWeight_3<=1000)),
    
           
           ((preferWithCream == 'Y'||preferWithCream =='y')&& (servedWithCream_3 == 'Y'||servedWithCream_3 == 'y'))||
           ((preferWithCream == 'N'||preferWithCream =='n')&& (servedWithCream_3 == 'N'||servedWithCream_3 == 'n')));
    
    printf("\nHope you found a product that suits your likes!\n");
    
    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/
