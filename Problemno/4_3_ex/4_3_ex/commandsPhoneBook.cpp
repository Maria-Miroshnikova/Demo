#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "commandsPhoneBook.h"
#include "myStructures.h"
#include "myUtilsForEntries.h"
#include "myUtilsForFIles.h"
#include "interface.h"

void deletePhoneBook(PhoneBookEntry phoneBook[])
{
	delete[] phoneBook;
}

void help()
{
	FILE *help = fopen("HELP.txt", "r");
	printf("\n");
	outputFile(help);
	printf("\n");
	fclose(help);
}

void outputAllEntries(PhoneBookEntry phoneBook[])
{
	int i = 0;
	while (!isEmptyEntry(phoneBook[i]))
	{
		outputEntry(phoneBook[i]);
		printf("\n");
		++i;
	}
	printf("\n");
}

void addEntry(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int *indexLastEntry)
{
	if (searchEntry(phoneBook, newEntry.name, true, *indexLastEntry) != -1)
	{
		printf("Sorry, you can`t add new entry: (%s) is already in the Phone Book!\n", newEntry.name);
	}
	else
	{
		if (searchEntry(phoneBook, newEntry.phone, false, *indexLastEntry) != -1)
		{
			printf("Sorry, you can`t add new entry: (%s) is already in the Phone Book!\n", newEntry.phone);
		}
		else
		{
			if (*indexLastEntry == 100)
			{
				printf("Sorry, you can`t add new entry: Phone Book is full!\n");
			}
			else
			{
				selectionSortEntries(phoneBook, newEntry, *indexLastEntry);
				++(*indexLastEntry);
			}
		}
	}
}

void findPhone(PhoneBookEntry phoneBook[], char name[], int indexLasrEntry)
{
	int findResult = searchEntry(phoneBook, name, true, indexLasrEntry);
	if (findResult == -1)
	{
		printf("Sorry, there is no person with name (%s)!\n", name);
	}
	else
	{
		printf("%s has phone: %s\n", name, phoneBook[findResult].phone);
	}
}

void findName(PhoneBookEntry phoneBook[], char phone[], int indexLasrEntry)
{
	int findResult = searchEntry(phoneBook, phone, false, indexLasrEntry);
	if (findResult == -1)
	{
		printf("Sorry, there is no person with phone (%s)!\n", phone);
	}
	else
	{
		printf("%s is phone of: %s\n", phone, phoneBook[findResult].name);
	}
}

void savePhoneBook(PhoneBookEntry phoneBook[], int indexLastEntry)
{
	FILE *phonebook = fopen("phonebook.txt", "w");
	for (int i = 0; i <= indexLastEntry; ++i)
	{
		saveEntry(phoneBook[i], phonebook);
	}
	fclose(phonebook);
}

PhoneBookEntry *createPhoneBook(int *indexLastEntry, FILE *phonebook)
{
	int maxLength = 100;
	PhoneBookEntry *phoneBook = new PhoneBookEntry[maxLength]{};
	readStartPhoneBook(phoneBook, indexLastEntry, phonebook);
	return phoneBook;
}