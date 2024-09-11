#include "writer.h"
#include "book.h"
#include <iostream>
#include <sstream>
#include <ctime>


void ChangeName(Writer& writer, const std::string& newName) {
    std::size_t spacePos = writer.fullName.find(' ');
    if (spacePos != std::string::npos) {
        writer.fullName = newName + writer.fullName.substr(spacePos);
    }
    std::cout << "Имя изменено!\n";
}

void ChangeSurname(Writer& writer, const std::string& newSurname) {
    std::size_t spacePos = writer.fullName.find_last_of(' ');
    if (spacePos != std::string::npos) {
        writer.fullName = writer.fullName.substr(0, spacePos) + " " + newSurname;
    }
    std::cout << "Фамилия изменена!\n";
}

void WriteBook(Writer& writer, const std::string& title, const std::string& genre, int year) {
    Book newBook = CreateBook(title, writer.fullName, year, genre);
    writer.books.push_back(newBook);
    std::cout << "Книга добавлена в список написанных книг!\n";
}