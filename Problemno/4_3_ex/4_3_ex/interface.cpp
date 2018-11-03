#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "interface.h"
#include "commandsPhoneBook.h"
#include "myStructures.h"
#include "myUtilsForEntries.h"

void outputName(PhoneBookEntry entry)
{
	printf("%s: ", entry.name);
}

void outputPhone(PhoneBookEntry entry)
{
	printf("%s", entry.phone);
}

void outputEntry(PhoneBookEntry entry)
{
	outputName(entry);
	outputPhone(entry);
}

void getCommand(PhoneBookEntry phoneBook[], int *indexLastEntry)
{
	printf("\nPlease, enter the command: ");
	const int maxLength = 82;
	char *command = new char[maxLength] {};
	scanf("%s", command);
	if ((command[0] == '0') && (command[1] == '\0'))
	{
		delete[] command;
		deletePhoneBook(phoneBook);
		return;
	}
	else
	{
		//////////////////////////////////////////////////////////////////
		if ((command[0] == '1') && (command[1] == '\0'))
		{
			printf("\nThe correct form for entry is: <name>: <phone>\n");
			printf("Please, enter the entry:\n");
			char *buffer = new char[maxLength] {};
	//		printf("buffer: %s.\n", buffer);
			fflush(stdin);
			scanf("%[^\n]", buffer);
	//		fgets(buffer, maxLength, stdin);
	//		printf("buffer: %s.\n", buffer);
			addEntry(phoneBook, createEntry(buffer, maxLength), indexLastEntry);
			delete[] buffer;
		}
		//////////////////////////////////////////////////////////////////
		else if ((command[0] == '2') && (command[1] == '\0'))
		{
			printf("\nNow Phone Book is:\n\n");
			outputAllEntries(phoneBook);
		}
		else if ((command[0] == '3') && (command[1] == '\0'))
		{
			printf("Please, enter the name:");
			char *buffer = new char[maxLength] {};
			scanf("%[^\n]", buffer);
			printf("buffer: %s.\n", buffer);
		}
		else if ((command[0] == '4') && (command[1] == '\0'))
		{

		}
		else if ((command[0] == '5') && (command[1] == '\0'))
		{
			savePhoneBook(phoneBook, *indexLastEntry);
			printf("\nPhone Book is saved to 'phonebook.txt'\n\n");
		}
		else if ((command[0] == 'H') && (command[1] == 'E') && (command[2] == 'L') && (command[3] == 'P') && (command[4] == '\0'))
		{
			help();
		}
		else
		{
			printf("\nSorry, your command is wrong!\n");
			printf("Enter HELP to see the list of commands.\n\n");
		}
		delete[] command;
		getCommand(phoneBook, indexLastEntry);
	}
}