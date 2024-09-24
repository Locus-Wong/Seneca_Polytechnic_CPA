/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int logDate_Year, logDate_Month,logDate_Days = 1, loopRepeat = 0;
    double morning_Value = 0, evening_Value = 0, morning_SumValue = 0, evening_SumValue = 0;
    
    
    printf("General Well-being Log\n");
    printf("======================\n");
    do{
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d",&logDate_Year,&logDate_Month);
        
        if (logDate_Year >= MIN_YEAR && logDate_Year <= MAX_YEAR && logDate_Month >= JAN && logDate_Month <= DEC)
        {
            printf("\n*** Log date set! ***\n\n");
            loopRepeat = 0;
        }
        
        else
        {
            if (logDate_Year < MIN_YEAR || logDate_Year > MAX_YEAR)
            {
                printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
                loopRepeat = 1;
            }
            if (logDate_Month < JAN || logDate_Month > DEC)
            {
                printf("   ERROR: Jan.(1) - Dec.(12)\n");
                loopRepeat = 1;
            }
            
        }
    } while (loopRepeat == 1);
    for (logDate_Days = 1; logDate_Days<=LOG_DAYS; logDate_Days++)
    {
        if (logDate_Days <=9)
        {
            switch (logDate_Month)
            {   case 1:
                    printf("%d-JAN-0%d\n",logDate_Year,logDate_Days);
                    break;
                case 2:
                    printf("%d-FEB-0%d\n",logDate_Year,logDate_Days);
                    break;
                case 3:
                    printf("%d-MAR-0%d\n",logDate_Year,logDate_Days);
                    break;
                case 4:
                    printf("%d-APR-0%d\n",logDate_Year,logDate_Days);
                    break;
                case 5:
                    printf("%d-MAY-0%d\n",logDate_Year,logDate_Days);
                    break;
                case 6:
                    printf("%d-JUN-0%d\n",logDate_Year,logDate_Days);
                    break;
                case 7:
                    printf("%d-JUL-0%d\n",logDate_Year,logDate_Days);
                    break;
                case 8:
                    printf("%d-AUG-0%d\n",logDate_Year,logDate_Days);
                    break;
                case 9:
                    printf("%d-SEP-%d\n",logDate_Year,logDate_Days);
                    break;
                case 10:
                    printf("%d-OCT-%d\n",logDate_Year,logDate_Days);
                    break;
                case 11:
                    printf("%d-NOV-%d\n",logDate_Year,logDate_Days);
                    break;
                case 12:
                    printf("%d-DEC-%d\n",logDate_Year,logDate_Days);
                    break;
            }
        }
        else
        {
            switch (logDate_Month)
            {   case 1:
                    printf("%d-JAN-%d\n",logDate_Year,logDate_Days);
                    break;
                case 2:
                    printf("%d-FEB-%d\n",logDate_Year,logDate_Days);
                    break;
                case 3:
                    printf("%d-MAR-%d\n",logDate_Year,logDate_Days);
                    break;
                case 4:
                    printf("%d-APR-%d\n",logDate_Year,logDate_Days);
                    break;
                case 5:
                    printf("%d-MAY-%d\n",logDate_Year,logDate_Days);
                    break;
                case 6:
                    printf("%d-JUN-%d\n",logDate_Year,logDate_Days);
                    break;
                case 7:
                    printf("%d-JUL-%d\n",logDate_Year,logDate_Days);
                    break;
                case 8:
                    printf("%d-AUG-%d\n",logDate_Year,logDate_Days);
                    break;
                case 9:
                    printf("%d-SEP-%d\n",logDate_Year,logDate_Days);
                    break;
                case 10:
                    printf("%d-OCT-%d\n",logDate_Year,logDate_Days);
                    break;
                case 11:
                    printf("%d-NOV-%d\n",logDate_Year,logDate_Days);
                    break;
                case 12:
                    printf("%d-DEC-%d\n",logDate_Year,logDate_Days);
                    break;
                    
            }

        }
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf",&morning_Value);
            if (morning_Value < 0.0 || morning_Value > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                loopRepeat = 1;
            }
            else
            {
                loopRepeat = 0;
            }
            
        }while (loopRepeat == 1);
            
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf",&evening_Value);
            if (evening_Value < 0.0 || evening_Value > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                loopRepeat = 1;
            }
            else
            {
                loopRepeat = 0;
            }
            
        }while (loopRepeat == 1);
       
        morning_SumValue += morning_Value;
        evening_SumValue += evening_Value;
        printf("\n");
    }
    
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %0.3lf\n",morning_SumValue);
    printf("Evening total rating:  %0.3lf\n",evening_SumValue);
    printf("----------------------------\n");
    printf("Overall total rating: %0.3lf\n\n",morning_SumValue + evening_SumValue);
    printf("Average morning rating:  %0.1lf\n",morning_SumValue/LOG_DAYS);
    printf("Average evening rating:  %0.1lf\n",evening_SumValue/LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %0.1lf\n",(morning_SumValue + evening_SumValue)/(LOG_DAYS*2));
    
    return 0;
}



