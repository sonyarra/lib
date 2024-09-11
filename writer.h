#ifndef WRITER_H
#define WRITER_H

#include <string>
#include <vector>
#include "book.h"

struct Writer {
    std::string birthday;
    std::string fullName;
    std::vector<Book> books;
    int age;
};

// функции для работы с писателем
void ChangeName(Writer& writer, const std::string& newName);
void ChangeSurname(Writer& writer, const std::string& newSurname);
void WriteBook(Writer& writer, const std::string& title, const std::string& genre, int year);

#endif
