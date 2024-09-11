#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"

struct Library {
    std::vector<Book> books;
};

// функции для работы с библиотекой
void AddBook(Library& library, const Book& book);
void RemoveBook(Library& library, const std::string& title);
std::vector<Book> FindBooks(const Library& library, const std::string& searchTerm);
void PrintBooks(const Library& library);

#endif