#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

struct Book {
    std::string title;
    std::string author;
    int year;
    std::string genre;
};

// функция для создания новой книги
Book CreateBook(const std::string& title, const std::string& author, int year, const std::string& genre);

#endif