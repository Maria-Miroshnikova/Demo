#pragma once
#include "myStructures.h"

/// ������� ��� �� �������-�����������
void outputName(PhoneBookEntry entry);

/// ������� ������� �� �������-�����������
void outputPhone(PhoneBookEntry entry);

/// ������� ������ �� �������-�����������
void outputEntry(PhoneBookEntry entry);

/// ��������� ������� �� ��� ���, ���� ������� �� �������, � ���������� ��
void getCommand(PhoneBookEntry phoneBook[], int *indexLastEntry);