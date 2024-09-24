/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
// include the string library to use strcpy, strcmp
#include <string.h>

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
                suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)

void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int count = 0;
    displayPatientTableHeader();
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            count++;
        }
    }
    putchar('\n');
    if (count == 0) {
        printf("*** No records found ***\n");
    }
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)

void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        selection = inputIntRange(0, 2);
        switch (selection)
        {
            case 0:
                printf("\n");
                break;
            case 1:
                searchPatientByPatientNumber(patient, max);
                suspend();
                getchar();
                break;
            case 2:
                searchPatientByPhoneNumber(patient, max);
                suspend();
                break;
        }
        
    }while (selection);
    
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)

void addPatient(struct Patient patient[], int max)
{
        int i;
        int index = -1;
        int newPatientNum;

        for (i = 0; i < max && index == -1; i++)
        {
            if (patient[i].patientNumber == 0 )
            {
                index = i;
            }
        }

        if (index == -1)
        {
            printf("ERROR: Patient listing is FULL!\n\n");
        }
        else
        {
            newPatientNum = nextPatientNumber(patient, max);
            patient[index].patientNumber = newPatientNum;
            inputPatient(&patient[index]);
            printf("*** New patient record added ***\n\n");
        }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)

void editPatient(struct Patient patient[], int max)
{
        int patientNum;
        int index;
        printf("Enter the patient number: ");
        scanf("%d", &patientNum);
        index = findPatientIndexByPatientNum(patientNum, patient, max);
        if (index == -1)
        {
            printf("ERROR: Patient record not found!\n");
            
        }
        else
        {
            printf("\n");
            menuPatientEdit(&patient[index]);
        }
    
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)

void removePatient(struct Patient patient[], int max)
{
        int patientNum;
        int index;
        char confirmDelete;
        printf("Enter the patient number: ");
        scanf("%d", &patientNum);
        index = findPatientIndexByPatientNum(patientNum, patient, max);
        if (index == -1)
        {
            printf("\n");
            printf("ERROR: Patient record not found!\n\n");
        }
        else
        {
            printf("\n");
            displayPatientData(&patient[index], FMT_FORM);
            printf("\nAre you sure you want to remove this patient record? (y/n): ");
            confirmDelete = inputCharOption("yn");
            if (confirmDelete == 'y')
            {
                printf("Patient record has been removed!\n");
                strcpy(patient[index].name, "");
                patient[index].patientNumber = 0;
                strcpy(patient[index].phone.description,"");
                strcpy(patient[index].phone.number,"");
            }
            else if (confirmDelete == 'n')
            {
                printf("Operation aborted.\n");
            }
            printf("\n");
        }
        
        getchar();
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(const struct ClinicData* data)
{
    int isAllRecords = 1, includeDateField = 1, i,j;
    
    sortAppointments(data->appointments,data->maxAppointments);
    displayScheduleTableHeader(&data->appointments->date, isAllRecords);

    for (i = 0; i < data->maxAppointments; i++)
    {
           for (j = 0; j < data->maxPatient; j++)
           {
               if (data->appointments[i].patientNumber != 0 && data->patients[j].patientNumber != 0)
               {
                   if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                   {
                       displayScheduleData(&data->patients[j], &data->appointments[i], includeDateField);
                   }
               }
           }
    }
    
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(const struct ClinicData* data)
{
        int i, j, isAllRecords = 0, includeDateField = 0;
        int lastDay = 31;
        struct Date inputDate;
        
        printf("Year        : ");
        inputDate.year = inputIntPositive();
        printf("Month (1-12): ");
        inputDate.month = inputIntRange(1, 12);
        printf("Day (1-");
        if (inputDate.month == 4 || inputDate.month == 9 ||  inputDate.month == 11)
        {
            lastDay = 30;
        }
        else if (inputDate.year % 4 == 0 && inputDate.month == 2)
        {
            lastDay = 29;
        }
        else if(inputDate.month == 2)
        {
            lastDay = 28;
        }
    
        printf("%d)  : ", lastDay);
        inputDate.day = inputIntRange(1, lastDay);
        printf("\n");
        sortAppointments(data->appointments, data->maxAppointments);
        displayScheduleTableHeader(&inputDate, isAllRecords);
    
        for (i = 0; i < data->maxAppointments; i++)
        {
            for (j = 0; j < data->maxPatient; j++)
            {
                if (data->appointments[i].patientNumber != 0 && data->patients[j].patientNumber != 0)
                {
                    if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
                    {
                        if (data->appointments[i].date.year == inputDate.year && data->appointments[i].date.month == inputDate.month && data->appointments[i].date.day == inputDate.day)
                        {
                            displayScheduleData(&data->patients[j], &data->appointments[i], includeDateField);
                        }
                    }
                }
            }
        }

        printf("\n");
        
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient patient[], int maxPatient)
{
        int patientNumber, index, flag = 0, lastDay = 0;
        struct Date inputDate;
        struct Time inputTime;

        printf("Patient Number: ");
        patientNumber = inputIntPositive();
        index = findPatientIndexByPatientNum(patientNumber, patient, maxPatient);

        if (index >= 0)
        {
            while (flag != 1)
            {
                printf("Year        : ");
                inputDate.year = inputIntPositive();
                
                printf("Month (1-12): ");
                inputDate.month = inputIntRange(1,12);
                
                printf("Day (1-");
                if (inputDate.month == 4 || inputDate.month == 6 || inputDate.month == 9 ||  inputDate.month == 11) {
                    lastDay = 30;
                }
                else if (inputDate.year % 4 == 0 && inputDate.month == 2)
                {
                    lastDay = 29;
                }
                else if(inputDate.month == 2)
                {
                    lastDay = 28;
                }
                else
                {
                    lastDay = 31;
                }
                
                printf("%d)  : ", lastDay);
                inputDate.day = inputIntRange(1, lastDay);
                
                printf("Hour (0-23)  : ");
                inputTime.hour = inputIntRange(0,23);
                
                printf("Minute (0-59): ");
                inputTime.min = inputIntRange(0,59);
                
                while ((inputTime.hour < START_HOURS || inputTime.hour > END_HOURS) || (inputTime.hour == END_HOURS && inputTime.min > 0) || (inputTime.min % APPOINT_INTERVAL != 0))
                {
                    printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HOURS, END_HOURS, APPOINT_INTERVAL);
                    printf("Hour (0-23)  : ");
                    inputTime.hour = inputIntRange(0,23);
                    printf("Minute (0-59): ");
                    inputTime.min = inputIntRange(0,59);
                }
                
                if (timeSlotAvailable(appointments, inputDate, inputTime, maxAppointments) == 1 )
                {
                    index = nextTimeSlotAvailable(appointments, maxAppointments);
                    appointments[index].date = inputDate;
                    appointments[index].time = inputTime;
                    appointments[index].patientNumber = patientNumber;
                    printf("\n*** Appointment scheduled! ***\n\n");
                    flag = 1;
                }
                else
                {
                    printf("\nERROR: Appointment timeslot is not available!\n\n");
                }
            }
        }
        else
        {
            printf("\nERROR: Patient record not found!\n\n");
        }
            
            
        
}
// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments,struct Patient patient[], int maxPatient)
{
        int patientNumber = 0, patientIndex = -1, appointIndex = 0, lastDay = 0;
        char confirmDelete;
        struct Date inputDate;
        printf("Patient Number: ");
        patientNumber = inputIntPositive();
        patientIndex = findPatientIndexByPatientNum(patientNumber, patient, maxPatient);

        if (patientIndex >= 0)
        {
            printf("Year        : ");
            inputDate.year = inputIntPositive();
            
            printf("Month (1-12): ");
            inputDate.month = inputIntRange(1,12);

            printf("Day (1-");
            if (inputDate.month == 4 || inputDate.month == 6 || inputDate.month == 9 ||  inputDate.month == 11) {
                lastDay = 30;
            }
            else if (inputDate.year % 4 == 0 && inputDate.month == 2)
            {
                lastDay = 29;
            }
            else if(inputDate.month == 2)
            {
                lastDay = 28;
            }
            else
            {
                lastDay = 31;
            }
            
            printf("%d)  : ", lastDay);
            inputDate.day=inputIntRange(1,lastDay);

            if (validateAppointment(appointments, inputDate, patientNumber, &appointIndex, maxAppointments) == 1)
            {
        
                printf("\n");
                displayPatientData(&patient[patientIndex],FMT_FORM);
                printf("Are you sure you want to remove this appointment (y,n): ");
                confirmDelete = inputCharOption("yn");
                clearInputBuffer();
                if (confirmDelete == 'y')
                {
                    printf("\nAppointment record has been removed!\n\n");
                    appointments[appointIndex].patientNumber = 0;
                    appointments[appointIndex].date.year = 0;
                    appointments[appointIndex].date.month = 0;
                    appointments[appointIndex].date.day = 0;
                    appointments[appointIndex].time.hour = 0;
                    appointments[appointIndex].time.min = 0;
                }
                else if (confirmDelete == 'n')
                {
                    printf("Operation aborted.\n");
                }
               
            }
            else
            {
                printf("ERROR: No appointment for this date!\n\n");
            }
        }
        else
        {
            printf("ERROR: Patient record not found!\n\n");
        }
}

    


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)

void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber, index;
    printf("\nSearch by patient number: ");
    scanf("%d", &patientNumber);
    index=findPatientIndexByPatientNum(patientNumber, patient,max);
    
    if (index == -1)
    {
        printf("\n*** No records found ***\n\n");
    }
    else
    {
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");
    }
    
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)

void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i;
    int found = 0;
    char phoneNumber[PHONE_LEN + 1];
    printf("\nSearch by phone number: ");
    inputCString(phoneNumber,PHONE_LEN,PHONE_LEN);
    printf("\n");
    displayPatientTableHeader();
    for (i = 0; i<max ; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0)
        {
            if (strcmp(patient[i].phone.number, phoneNumber) == 0)
            {
                displayPatientData(&patient[i], FMT_TABLE);
                found = 1;
            }
        }
    }
    printf("\n");
    if (!found)
    {
        printf("\n*** No records found ***\n");
    }

  
}

// Get the next highest patient number
// (Copy your code from MS#2)

int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, maxPatientNumber = 0;
    
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber > maxPatientNumber)
            {
                maxPatientNumber = patient[i].patientNumber;
            }
        }

        return maxPatientNumber + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i;
    for (i = 0; i< max ; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }
        return  -1;
}

void sortAppointments (struct Appointment appoints[], int max)
{
    int i,j,min_index;
    struct Appointment temp[1] = { {0} };
        
    for (i = 0; i < max; i++)
    {
        min_index = i;
        for (j = i + 1; j < max; j++)
        {
            if ((365*24*60*(appoints[j].date.year) + 365/12*24*60* (appoints[j].date.month) + 24*60*appoints[j].date.day + 60*(appoints[j].time.hour) + (appoints[j].time.min)) < (365*24*60*(appoints[min_index].date.year) + 365/12*24*60* (appoints[min_index].date.month) + 24*60*appoints[min_index].date.day + 60*appoints[min_index].time.hour +  appoints[min_index].time.min))
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            temp[0] = appoints[i];
            appoints[i] = appoints[min_index];
            appoints[min_index] =  temp[0] ;
        }
    }

}


int timeSlotAvailable(struct Appointment* appoint, struct Date inputDate, struct Time inputTime, int maxAppointments)
{
    int i, slotAvailable = -1;

    for (i = 0; i < maxAppointments && slotAvailable != 0; i++)
    {
        if (appoint[i].date.year == inputDate.year  &&  appoint[i].date.month ==  inputDate.month && appoint[i].date.day == inputDate.day && appoint[i].time.hour == inputTime.hour && appoint[i].time.min == inputTime.min)
        {
            slotAvailable = 0;
        }
        else
        {
            slotAvailable = 1;
        }
    }

    return slotAvailable;
}

int nextTimeSlotAvailable(struct Appointment *appoint, int maxAppointments)
{
    int index = 0, isAvailable = 0, i;
   
    for (i = 0; i < maxAppointments && isAvailable != 1; i++)
    {
        if (appoint[i].patientNumber == 0)
        {
            isAvailable = 1;
            index = i;
        }
        
    }
    
    return index;
}

int validateAppointment(struct Appointment *appoint, struct Date inputDate, int patientNumber, int* appointIndex, int maxAppointments)
{
    int i = 0, isValid = 0;

    for (i = 0; i < maxAppointments && isValid != 1; i++)
    {
        if ((appoint[i].patientNumber == patientNumber) && (appoint[i].date.year == inputDate.year) && (appoint[i].date.month == inputDate.month) && (appoint[i].date.day == inputDate.day))
        {
            isValid = 1;
            *appointIndex = i;
        }
        
    }
    
    return isValid;
    
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)

void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n",patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name,1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
    
   
}

// Get user input for phone contact information
// (Copy your code from MS#2)

void inputPhoneData(struct Phone* phone)
{
    int selection;
    char inputPhoneNumber [PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    selection = inputIntRange(1, 4);
    putchar('\n');
    switch (selection)
    {
        case 1:
            strncpy(phone->description,"CELL", PHONE_DESC_LEN);
            break;
        case 2:
            strncpy(phone->description,"HOME",PHONE_DESC_LEN);
            break;
        case 3:
            strncpy(phone->description,"WORK",PHONE_DESC_LEN);
            break;
        case 4:
            strncpy(phone->description,"TBD",PHONE_DESC_LEN);
            break;
    }
    if (selection != 4)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCStringNumber(inputPhoneNumber,PHONE_LEN,PHONE_LEN);
        strcpy(phone->number, inputPhoneNumber);
        printf("\n");
    }
  
    
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int i, c, numOfRecords = 0;
    FILE *fp = NULL;
    fp = fopen(datafile,"r");
    if (fp != NULL)
    {
        do {
            c = fgetc(fp);
            if (c != EOF)
            {
                if ((char) c == '\n' && numOfRecords < max)
                {
                    numOfRecords++;
                }
            }
        }while (feof(fp) == 0);
        
        rewind(fp);
        
        for (i = 0 ; i < max ; i++)
        {
            fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",&patients[i].patientNumber,patients[i].name, patients[i].phone.description, patients[i].phone.number);

        }
        fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }
    return numOfRecords;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    int i, c, numOfRecords = 0;
    FILE *fp = NULL;
    fp = fopen(datafile,"r");
    if (fp != NULL)
    {
        do {
            c = fgetc(fp);
            if (c != EOF)
            {
                if ((char) c == '\n'&& numOfRecords < max)
                {
                    numOfRecords++;
                }
            }
        }while (feof(fp) == 0);
        
        rewind(fp);
        
        for (i = 0 ; i < max ; i++)
        {
            fscanf(fp, "%d,%d,%d,%d,%d,%d", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour,&appoints[i].time.min);
        }
        fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }
    
    return numOfRecords;
    
}

