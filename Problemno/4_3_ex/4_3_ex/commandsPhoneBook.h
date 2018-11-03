#pragma once
#include "myStructures.h"

/// ������� ������-����������
void deletePhoneBook(PhoneBookEntry phoneBook[]);

/// ������� ���������� ����� "HELP.txt"
void help();

/// ������� ��� ������ �� �������-�����������
void outputAllEntries(PhoneBookEntry phoneBook[]);

/// ��������� ������ � ������-����������, �������� ����� ��������� ������� ������,
/// ���� ������ ������ � ����� ��� ��� � ���� ��������� ����� � �������,
/// ����� ������� �������������� ���������
void addEntry(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int *indexLastEntry);

/// ���� ����� �� ��������� ����� � ������� ����� � ������� ��� �� �����, ���� �������,
/// ����� ������� ��������� �� ��������� ������ � ����� ������
void findPhone(PhoneBookEntry phoneBook[], char name[], int indexLasrEntry);

/// ���� ��� �� ��������� ������ � ������� ����� � ������� ��� �� �����, ���� �������,
/// ����� ������� ��������� �� ��������� ������ � ����� �������
void findName(PhoneBookEntry phoneBook[], char phone[], int indexLasrEntry);

/// ���������� ���� ������-������ � ���� "phonebook.txt"
void savePhoneBook(PhoneBookEntry phoneBook[], int indexLastEntry);

/// ������� ������-����������, ��������� � ���� ������ �� �������� ����� �����������
/// � ���������� ��������� �� ����
PhoneBookEntry *createPhoneBook(int *indexLastEntry, FILE *phonebook);