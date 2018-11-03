#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "commandsPhoneBook.h"
#include "myUtilsForEntries.h"

void tests()
{
	int testIndexLastEntry = -1;
	int dataIndexLastEntry = -1;
	FILE *testphonebook = fopen("testPhoneBook.txt", "r");
	PhoneBookEntry *testPhoneBook = createPhoneBook(&testIndexLastEntry, testphonebook);
	fclose(testphonebook);
	FILE *testdata = fopen("testData.txt", "r");
	PhoneBookEntry *testData = createPhoneBook(&dataIndexLastEntry, testdata);
	fclose(testdata);
	for (int i = 0; i <= dataIndexLastEntry; ++i)
	{
		if (searchEntry(testPhoneBook, (testData[i]).name, true, testIndexLastEntry) == -1)
		{
			if (searchEntry(testPhoneBook, (testData[i]).phone, false, testIndexLastEntry) == -1)
			{

			}
		}
	}

	deletePhoneBook(testPhoneBook);
	deletePhoneBook(testData);
}