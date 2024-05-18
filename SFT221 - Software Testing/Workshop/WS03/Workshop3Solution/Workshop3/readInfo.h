#pragma once
#ifndef READINFO_H
#define READINFO_H

struct Customer
{
	char firstName[31];
	char lastName[31];
	char streetAddress[100];
	char city[16];
	char province[3];
	char postalCode[16];
};

void readInfo(struct Customer* c);
void printInfo(const struct Customer* c);
int postalCodeVerification(char* postalCode);
void clearInputBuffer(void);

#endif // !READINFO_H
