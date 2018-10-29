struct PhoneBookEntry
{
	char surname[100]{};
	char name[100]{};
	char middlename[100]{};
	char phone[30]{};
};


/// возвращает номер (1, 2) той строки, которая должна быть первой в алфавитном порядке
/// и 0, если они одинаковые
int compareStr(char str1[], char str2[]);


/// меняет местами записи в справочнике
void swapEntries();


/// phoneBook - массив, элементы которого - структуры
/// newEntry - новая запись, которую хочется добавить в справочник (массив)
/// indexLastEntry - индекс последнего элемента в массиве, содержащего непустую запись



/// сортирует вставкой справочник
void selectionSortEntries(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int indexLastEntry)
{
	int index = indexLastEntry + 1; // добавляю новую запись в конец массива
	phoneBook[index] = newEntry;    // на первое свободное место
	for (int i = indexLastEntry; i >= 0; --i)
	{
		int minEntrySurname = compareStr(phoneBook[i].surname, newEntry.surname); // сравниваю записи по фамилии
		if (minEntrySurname < 2) // если фамилия в новой записи равна или больше фамилии в справочнике:
		{
			if (minEntrySurname == 1) // если фамилия в новой записи больше фамилии в справочнике - место найдено.
			{
				break;
			}
			else                     // если нашлись однофамильцы, нужно проделать тот же процесс для имен - ?!
			{
				/////////////////////////////////////////////////////////////////
				int minEntryName = compareStr(phoneBook[i].name, newEntry.name);
				if (minEntryName < 2)
				{
					if (minEntryName == 1)
					{
						break;
					}
					else            // если нашлись однофамильцы с одинаковыми именами, нужно сравнить отчества - ?!
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
								///////// что делать с двумя одинаковыми людьми?
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
		else    // продвинуть новую запись к началу справочника, если она меньше старой записи
		{
			swapEntries(phoneBook, i, index);
			--index;
		}
	}
}