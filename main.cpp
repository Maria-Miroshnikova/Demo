struct PhoneBookEntry
{
	char surname[100]{};
	char name[100]{};
	char middlename[100]{};
	char phone[30]{};
};


/// ���������� ����� (1, 2) ��� ������, ������� ������ ���� ������ � ���������� �������
/// � 0, ���� ��� ����������
int compareStr(char str1[], char str2[]);


/// ������ ������� ������ � �����������
void swapEntries();


/// phoneBook - ������, �������� �������� - ���������
/// newEntry - ����� ������, ������� ������� �������� � ���������� (������)
/// indexLastEntry - ������ ���������� �������� � �������, ����������� �������� ������



/// ��������� �������� ����������
void selectionSortEntries(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int indexLastEntry)
{
	int index = indexLastEntry + 1; // �������� ����� ������ � ����� �������
	phoneBook[index] = newEntry;    // �� ������ ��������� �����
	for (int i = indexLastEntry; i >= 0; --i)
	{
		int minEntrySurname = compareStr(phoneBook[i].surname, newEntry.surname); // ��������� ������ �� �������
		if (minEntrySurname < 2) // ���� ������� � ����� ������ ����� ��� ������ ������� � �����������:
		{
			if (minEntrySurname == 1) // ���� ������� � ����� ������ ������ ������� � ����������� - ����� �������.
			{
				break;
			}
			else                     // ���� ������� ������������, ����� ��������� ��� �� ������� ��� ���� - ?!
			{
				/////////////////////////////////////////////////////////////////
				int minEntryName = compareStr(phoneBook[i].name, newEntry.name);
				if (minEntryName < 2)
				{
					if (minEntryName == 1)
					{
						break;
					}
					else            // ���� ������� ������������ � ����������� �������, ����� �������� �������� - ?!
					{
						/////////////////////////////////////////////////////////
						int minEntryMiddlename = compareStr(phoneBook[i].middlename, newEntry.middlename);
						if (minEntryMiddlename < 2)
						{
							if (minEntryMiddlename == 1)
							{
								break;
							}
							else
							{
								///////// ��� ������ � ����� ����������� ������?
							}
						}
						else
						{
							swapEntries(phoneBook, i, index);
							--index;
						}
						/////////////////////////////////////////////////////////
					}
				}
				else
				{
					swapEntries(phoneBook, i, index);
					--index;
				}
				/////////////////////////////////////////////////////////////////
			}
		}
		else    // ���������� ����� ������ � ������ �����������, ���� ��� ������ ������ ������
		{
			swapEntries(phoneBook, i, index);
			--index;
		}
	}
}