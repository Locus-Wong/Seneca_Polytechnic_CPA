/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

int main(void)
{
    const int JAN = 1, DEC = 12;
    int logDate_Year, logDate_Month,logDate_Days = 1, loopRepeat = 0;
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
 
        switch (logDate_Month)
        {   case 1:
                printf("Log starting date: %d-JAN-0%d\n",logDate_Year,logDate_Days);
                break;
            case 2:
                printf("Log starting date: %d-FEB-0%d\n",logDate_Year,logDate_Days);
                break;
            case 3:
                printf("Log starting date: %d-MAR-0%d\n",logDate_Year,logDate_Days);
                break;
            case 4:
                printf("Log starting date: %d-APR-0%d\n",logDate_Year,logDate_Days);
                break;
            case 5:
                printf("Log starting date: %d-MAY-0%d\n",logDate_Year,logDate_Days);
                break;
            case 6:
                printf("Log starting date: %d-JUN-0%d\n",logDate_Year,logDate_Days);
                break;
            case 7:
                printf("Log starting date: %d-JUL-0%d\n",logDate_Year,logDate_Days);
                break;
            case 8:
                printf("Log starting date: %d-AUG-0%d\n",logDate_Year,logDate_Days);
                break;
            case 9:
                printf("Log starting date: %d-SEP-%d\n",logDate_Year,logDate_Days);
                break;
            case 10:
                printf("Log starting date: %d-OCT-%d\n",logDate_Year,logDate_Days);
                break;
            case 11:
                printf("Log starting date: %d-NOV-%d\n",logDate_Year,logDate_Days);
                break;
            case 12:
                printf("Log starting date: %d-DEC-%d\n",logDate_Year,logDate_Days);
                break;
        }
    
   
    
    return 0;
}
