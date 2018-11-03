#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "myUtilsForEntries.h"
#include "myStructures.h"
#include "commandsPhoneBook.h"
#include "interface.h"
#include "myUtilsForFIles.h"

int main()
{
	int indexLastEntry = -1;
	FILE *phonebook = fopen("phonebook.txt", "r");
	PhoneBookEntry *phoneBook = createPhoneBook(&indexLastEntry, phonebook);
	fclose(phonebook);
	printf("Now phoneBook is:\n");
	outputAllEntries(phoneBook);
	printf("Thats all!\n");
	help();
	getCommand(phoneBook, &indexLastEntry);
/*	PhoneBookEntry entry = { "Mir Rora Leon", "2 90 56 79" };
	addEntry(phoneBook, entry, &indexLastEntry);
	printf("Now phoneBook is:\n\n");
	outputAllEntries(phoneBook);
	printf("Thats all!\n");
	savePhoneBook(phoneBook, indexLastEntry);*/
	system("pause");
	return 0;
}

/*int main()
{
	int maxLength = 100;
	PhoneBookEntry *phoneBook = new PhoneBookEntry[maxLength]{};
	PhoneBookEntry *testBook = new PhoneBookEntry[20]{};
	phoneBook[0] = { "Mir Rora Leon", "2 90 56 79" };
	testBook[0] = { "Mira Rora Leon", "2-90-56-79" };
	testBook[1] = { "Mera Rora Leon", "2-09-57-69" };
	testBook[2] = { "Kir Rora Leon", "3-90-56-79" };
	testBook[3] = { "Pirt Mari Andr", "4-90-56-79" };
	testBook[4] = { "Mira Ror Andr", "5-90-56-79" };
	testBook[5] = { "Mira Oora Andr", "6-90-56-79" };
	testBook[6] = { "Mira Roara Andr", "8-90-56-79" };
	testBook[7] = { "Mira Ror Andra", "8-90-56-79" };
	testBook[8] = { "Mira Ror Sandr", "9-90-56-79" };
	testBook[9] = { "Mira Ror Sandr", "0-90-56-79" };
	int indexLastEntry = 0;
	for (int i = 0; i < 10; ++i)
	{
//		printf("now add name %d:\n", i);
		addEntry(phoneBook, testBook[i], &indexLastEntry);
		//outputNames(phoneBook, 11);
		//system("pause");
	}
	printf("\nTHE END");
//	outputNames(phoneBook, 12);
	outputAllEntries(phoneBook);
/*	int sortArray[11] = { 1, 1, 3, 4, 5, 5, 5, 6, 7, 8, 9 };
	int numbers[12] = { 1, 3, 4, 5, 6, 7, 8, 9, 0, -1, 2, 10 };
	for (int i = 0; i < 12; ++i)
	{
		printf("is there %d : %d\n", numbers[i], binarySearchEntries(sortArray, numbers[i], 0, 10));
	}*/
/*	for (int i = 0; i < 11; ++i)
	{
		findPhone(phoneBook, phoneBook[i].name, indexLastEntry);
	}
	char testName[14] = { 'M', 'i', 'r', ' ', 'R', 'o', 'r', ' ', 'S', 'a', 'n', 'd', 'r' };
	findPhone(phoneBook, testName, indexLastEntry);*/
/*	char testPhone[11] = { '1', '-', '9', '0', '-', '5', '6', '-', '7', '8' };
	printf("%s\n", testPhone);
	for (int i = 0; i < 11; ++i)
	{
		findName(phoneBook, phoneBook[i].phone, indexLastEntry);
		system("pause");
	}
	findName(phoneBook, testPhone, indexLastEntry);*/
//	savePhoneBook(phoneBook, indexLastEntry);
/*	system("pause");
	return 0;
}*/