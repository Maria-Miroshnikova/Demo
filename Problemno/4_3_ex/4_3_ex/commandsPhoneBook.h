#pragma once
#include "myStructures.h"

/// удаляет массив-справочник
void deletePhoneBook(PhoneBookEntry phoneBook[]);

/// выводит содержимое файла "HELP.txt"
void help();

/// выводит все записи из массива-справочника
void outputAllEntries(PhoneBookEntry phoneBook[]);

/// добавляет запись в массив-справочник, увеличив номер последней занятой записи,
/// если такого номера и имени там нет и есть свободное место в массиве,
/// иначе выводит соотвествующее сообщение
void addEntry(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int *indexLastEntry);

/// ищет номер по заданному имени в массиве строк и выводит его на экран, если находит,
/// иначе выводит сообщение об отсуствии записи с таким именем
void findPhone(PhoneBookEntry phoneBook[], char name[], int indexLasrEntry);

/// ищет имя по заданному номеру в массиве строк и выводит его на экран, если находит,
/// иначе выводит сообщение об отсуствии записи с таким номером
void findName(PhoneBookEntry phoneBook[], char phone[], int indexLasrEntry);

/// записывает весь массив-список в файл "phonebook.txt"
void savePhoneBook(PhoneBookEntry phoneBook[], int indexLastEntry);

/// создает массив-справочник, считывает в него данные из начально файла справочника
/// и возвращает указатель на него
PhoneBookEntry *createPhoneBook(int *indexLastEntry, FILE *phonebook);