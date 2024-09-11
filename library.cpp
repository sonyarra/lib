#include "library.h"
#include <iostream>

void AddBook(Library& library, const Book& book) {
    library.books.push_back(book);
    std::cout << "Книга добавлена!\n";
}

void RemoveBook(Library& library, const std::string& title) {
    auto it = std::find_if(library.books.begin(), library.books.end(),
        [&title](const Book& book) { return book.title == title; });

    if (it != library.books.end()) {
        library.books.erase(it);
        std::cout << "Книга удалена!\n";
    }
    else {
        std::cout << "Книга не найдена.\n";
    }
}

std::vector<Book> FindBooks(const Library& library, const std::string& searchTerm) {
    std::vector<Book> results;
    for (const Book& book : library.books) {
        if (book.title.find(searchTerm) != std::string::npos ||
            book.author.find(searchTerm) != std::string::npos) {
            results.push_back(book);
        }
    }
    return results;
}

void PrintBooks(const Library& library) {
    if (library.books.empty()) {
        std::cout << "Библиотека пуста.\n";
        return;
    }

    std::cout << "Список книг:\n";
    for (const Book& book : library.books) {
        std::cout << "Название: " << book.title << "\n";
        std::cout << "Автор: " << book.author << "\n";
        std::cout << "Год издания: " << book.year << "\n";
        std::cout << "Жанр: " << book.genre << "\n\n";
    }
}