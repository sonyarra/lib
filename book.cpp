#include "book.h"

Book CreateBook(const std::string& title, const std::string& author, int year, const std::string& genre) {
    Book book;
    book.title = title;
    book.author = author;
    book.year = year;
    book.genre = genre;
    return book;
}