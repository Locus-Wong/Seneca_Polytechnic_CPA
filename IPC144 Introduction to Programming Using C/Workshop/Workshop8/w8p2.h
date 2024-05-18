/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  :TSZ WA WONG
Student ID#:152181228
Email      :twwong9@myseneca.ca
Section    :NFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros

#define max_number_product 3
#define num_of_grams 64

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
    
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int *int_Num);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double *double_Num);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int numOfProduct);

// 4. Get user input for the details of cat food product

struct CatFoodInfo getCatFoodInfo(const int sequence_Num);


// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData (int sku, double *price, double *weight, int calories);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg


// 9. convert lbs: g


// 10. convert lbs: kg / g


// 11. calculate: servings based on gPerServ


// 12. calculate: cost per serving


// 13. calculate: cost per calorie


// 14. Derive a reporting detail record based on the cat food product data


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table


// 17. Display the findings (cheapest)


// ----------------------------------------------------------------------------

// 7. Logic entry point
