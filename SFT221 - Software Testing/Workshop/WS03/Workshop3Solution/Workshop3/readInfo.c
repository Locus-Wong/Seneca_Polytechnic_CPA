#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "readInfo.h"

void readInfo(struct Customer* c)
{
	int result = 0;
	char unVerifiedPostalCode[16] = { 0 };
	do
	{
		printf("Enter your first name: ");
		fgets(c->firstName, 31, stdin);
		if (c->firstName[strlen(c->firstName) - 1] == '\n') // Check if the last character is a newline character
		{
			c->firstName[strlen(c->firstName) - 1] = '\0';  // Remove the newline character
		}
		else
		{
			clearInputBuffer();
		}
		if (strlen(c->firstName) == 0)
		{
			printf("Invalid first name, empty string received!\n");
		}
	}while (strlen(c->firstName) == 0);
	
	do{
		printf("Enter your last name: ");
		fgets(c->lastName, 31, stdin);
		if (c->lastName[strlen(c->lastName) - 1] == '\n')
		{
			c->lastName[strlen(c->lastName) - 1] = '\0';
		}
		else
		{
			clearInputBuffer();
		}

		if (strlen(c->lastName) == 0)
		{
			printf("Invalid last name, empty string received!\n");
		}
	}while (strlen(c->lastName) == 0);
	
	do
	{
		printf("Enter your street address: ");
		fgets(c->streetAddress, 100, stdin);
		if (c->streetAddress[strlen(c->streetAddress) - 1] == '\n')
		{
			c->streetAddress[strlen(c->streetAddress) - 1] = '\0';
		}
		else
		{
			clearInputBuffer();
		}
		if (strlen(c->streetAddress) == 0)
		{
			printf("Invalid street address, empty string received!\n");
		}
	}while (strlen(c->streetAddress) == 0);
	
	do
	{
		printf("Enter your city: ");
		fgets(c->city, 16, stdin);
		if (c->city[strlen(c->city) - 1] == '\n')
		{
			c->city[strlen(c->city) - 1] = '\0';
		}
		else
		{
			clearInputBuffer();
		}
		if(strlen(c->city) == 0)
		{
			printf("Invalid city, empty string received!\n");
		}
	}while (strlen(c->city) == 0);
	
	do
	{
		printf("Enter your province: ");
		fgets(c->province, 3, stdin);
		if (c->province[strlen(c->province) - 1] == '\n')
		{
			c->province[strlen(c->province) - 1] = '\0';
		}
		else
		{
			clearInputBuffer();
		}
		if(strlen(c->province) == 0)
		{
			printf("Invalid province, empty string received!\n");
		}
	}while (strlen(c->province) == 0);
	
	do
	{
		printf("Enter your postal code: ");
		fgets(unVerifiedPostalCode, 16, stdin);
		if (unVerifiedPostalCode[strlen(unVerifiedPostalCode) - 1] == '\n')
		{
			unVerifiedPostalCode[strlen(unVerifiedPostalCode) - 1] = '\0';
		}
		else
		{
			clearInputBuffer();
		}
		result = postalCodeVerification(unVerifiedPostalCode);
		if (result == 0)
		{
			printf("Please try again!\n");
		}
		else
		{
			strcpy(c->postalCode, unVerifiedPostalCode);
		}
	}while (result == 0);
}

	int postalCodeVerification(char* postalCode)
{
		if (strlen(postalCode) < 6)
		{
			printf("Invalid postal code, too short!\n");
			return 0;

		}
	int whitespaceCount = 0;
	for (int i = 0; i < strlen(postalCode); i++)
	{
		if (!isalpha(postalCode[i]) && !isdigit(postalCode[i]))
		{
			if (postalCode[i] != ' ')
			{
				printf("Invalid postal code, include non-valid characters!");
				return 0;
			}
			else 
			{
				whitespaceCount++;
			}
			
		}
	}
	if (whitespaceCount == strlen(postalCode))
	{
		printf("Invalid postal code, empty string received!\n");
		return 0;
	}
	if (strlen(postalCode) == 6)
	{
		char formattedPostalCode[8] = { 0 };
		for (int i = 0; i < 6; i++)
		{
			if (i == 0 || i == 2 || i == 4)
			{
				if (!isalpha(postalCode[i]))
				{
					printf("Invalid postal code, include non-letter characters at %dth character!\n", i + 1);
					return 0;
				}
			}
			if (i == 1 || i == 3 || i == 5)
			{
				if (!isdigit(postalCode[i]))
				{
					printf("Invalid postal code, include non-digit characters at %dth character!\n", i + 1);
					return 0;
				}
			}

		}
		for (int i = 0; i < 3; i++)
		{
			postalCode[i] = toupper((unsigned char)postalCode[i]);
		}
		for (int i = 6; i > 3; i--)		// 6 5 4 to prevent overwriting
		{
			postalCode[i] = toupper((unsigned char)postalCode[i-1]);
		}
		postalCode[3] = ' ';
		postalCode[7] = '\0';
		return 1;


	}
	else if (strlen(postalCode) == 7)
	{
		for (int i = 0; i < 7; i++)
		{
			if (i == 0 || i == 2 || i == 5)
			{
				if (!isalpha(postalCode[i]))
				{
					printf("Invalid postal code, include non-letter characters at %dth character!\n", i + 1);
					return 0;
				}
			}
			if (i == 1 || i == 4 || i == 6)
			{
				if (!isdigit(postalCode[i]))
				{
					printf("Invalid postal code, include non-digit characters at %dth character!\n", i+1);
					return 0;
				}
			}
			if (i == 3)
			{
				if (postalCode[i] != ' ')
				{
					printf("Invalid postal code, include non-whitspace characters at %dth character!\n", i + 1);
					return 0;
				}
			}

			postalCode[i] = toupper(postalCode[i]);

		}
		return 1;
	}
	else
	{
		if (whitespaceCount > 1)
		{
			const char delimiter[] = " ";
			char* token = strtok(postalCode, delimiter);
			char formattedPostalCode[8] = { 0 };
			strcat(formattedPostalCode, token);

			while ((token = strtok(NULL, delimiter)) != NULL)
			{
				strcat(formattedPostalCode, token);
			
			}

			for (int i = 0; i < 3; i++)
			{
				postalCode[i] = toupper(formattedPostalCode[i]);
			}
			for (int i = 6; i > 3; i--)		// 6 5 4 to prevent overwriting
			{
				postalCode[i] = toupper(formattedPostalCode[i - 1]);
			}
			postalCode[3] = ' ';
			postalCode[7] = '\0';
			return 1;
		}
	}
	
	return 0;
}

void clearInputBuffer(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void printInfo(const struct Customer* c)
{
	printf("\nYou entered:\n");
	printf("First name: %s\n", c->firstName);
	printf("Last name: %s\n", c->lastName);
	printf("Street address: %s\n", c->streetAddress);
	printf("City: %s\n", c->city);
	printf("Province: %s\n", c->province);
	printf("Postal code: %s\n", c->postalCode);
}

int main(void)
{
	struct Customer c = { 0 };
	readInfo(&c);
	printInfo(&c);
	return 0;
}