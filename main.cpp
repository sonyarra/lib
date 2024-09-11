#include <iostream>
#include <string>
#include "book.h"
#include "library.h"
#include "writer.h"
#include <limits>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    Library library;
    Writer writer1 = { "01:01:1980", "Lev Nikolaevich Tolstoy", {}, 42 };
    Writer writer2 = { "15:03:1975", "Ivan Alexandrovich Goncharov", {}, 47 };
    Writer writer3 = { "13:02:1960", "Pushkin Aleksandr Sergeevich", {}, 39 };


    WriteBook(writer1, "The War and Peace", "roman", 1869);
    WriteBook(writer2, "Oblomov", "roman", 1877);
    WriteBook(writer3, "Evgeny Onegin", "roman", 1831);

    AddBook(library, CreateBook("The War and Peace", "Лев Николаевич Толстой", 1869, "roman"));
    AddBook(library, CreateBook("Oblomov", "Ivan Alexandrovich Goncharov", 1877, "roman"));
    AddBook(library, CreateBook("Evgeny Onegin", "Pushkin Aleksandr Sergeevich", 1831, "roman"));

    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить книгу\n";
        cout << "2. Удалить книгу\n";
        cout << "3. Найти книгу\n";
        cout << "4. Вывести список всех книг\n";
        cout << "5. Выход\n";
        cout << "Введите номер действия: ";

        if (!(cin >> choice)) {
            cout << "Некорректный ввод. Введите число.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            string title, author, genre;
            int year;

            do {
                cout << "Введите название книги: ";
                cin.ignore();
                getline(cin, title);
                if (title.empty()) {
                    cout << "Название книги не может быть пустым. Попробуйте снова.\n";
                }
            } while (title.empty());

            do {
                cout << "Введите автора книги: ";
                getline(cin, author);

                if (author.empty()) {
                    cout << "Автор книги не может быть пустым. Введите автора. Попробуйте снова.\n";
                    continue; 
                }

                bool onlyDigits = true;
                for (char c : author) {
                    if (!isdigit(c)) {
                        onlyDigits = false;
                        break;
                    }
                }
                if (onlyDigits) {
                    cout << "Имя автора книги не может состоять только из цифр. Введите автора. Попробуйте снова.\n";
                    continue; 
                }

                break; 
            } while (true);


            do {
                cout << "Введите год издания книги: ";
                string yearStr;
                getline(cin, yearStr); // считываем год как строку

              
                if (yearStr.empty()) {
                    cout << "Год издания не может быть пустым. Введите число. Попробуйте снова.\n";
                    continue; 
                }

                // преобразуем строку в число
                try {
                    year = stoi(yearStr); // stoi бросает исключение, если преобразование не удается
                    if (year < 0) {
                        cout << "Год издания не может быть отрицательным. Введите заново.\n";
                        continue; 
                    }
                    else {
                        break; 
                    }
                }
                catch (const std::invalid_argument& e) {
                    cout << "Год издания не может быть введен буквами. Введите число. Попробуйте снова.\n";
                }
                catch (const std::out_of_range& e) {
                    cout << "Введенное значение года выходит за пределы допустимого диапазона. Введите заново.\n";
                }
            } while (true);

            do {
                cout << "Введите жанр книги: ";
                getline(cin, genre); // считываем жанр как строку

                if (genre.empty()) {
                    cout << "Жанр книги не может быть пустым. Введите жанр. Попробуйте снова.\n";
                    continue; 
                }

                bool onlyDigits = true;
                for (char c : genre) {
                    if (!isdigit(c)) {
                        onlyDigits = false;
                        break;
                    }
                }
                if (onlyDigits) {
                    cout << "Жанр книги не может состоять только из цифр. Введите жанр. Попробуйте снова.\n";
                    continue; 
                }

                break; 
            } while (true);

            Book newBook = CreateBook(title, author, year, genre);
            AddBook(library, newBook);
            break;
        }
        case 2: {
            string title;
            cout << "Введите название книги для удаления: ";
            cin.ignore();
            getline(cin, title);
            RemoveBook(library, title);
            break;
        }
        case 3: {
            string searchTerm;
            while (true) {
                cout << "Введите название или автора для поиска: ";
                cin.ignore();
                getline(cin, searchTerm);

                // Проверяем, состоит ли строка только из пробелов
                bool isOnlySpaces = true;
                for (char c : searchTerm) {
                    if (!isspace(c)) {
                        isOnlySpaces = false;
                        break;
                    }
                }

                // Проверяем, является ли строка пустой или содержит только пробелы
                if (searchTerm.empty() || isOnlySpaces) {
                    cout << "Ошибка: поле не может быть пустым или содержать только пробелы. Попробуйте снова.\n";
                }
                else {
                    break; // Если ввод корректен, выходим из цикла
                }
            }

            vector<Book> results = FindBooks(library, searchTerm);

            if (results.empty()) {
                cout << "Книги не найдены.\n";
            }
            else {
                cout << "Найденные книги:\n";
                for (const Book& book : results) {
                    cout << "Название: " << book.title << "\n";
                    cout << "Автор: " << book.author << "\n";
                    cout << "Год издания: " << book.year << "\n";
                    cout << "Жанр: " << book.genre << "\n\n";
                }
            }
            break;
        }

        case 4:
            PrintBooks(library);
            break;
       
        case 5:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный ввод. Введите число от 1 до 5. Попробуйте снова.\n";
        }
    } while (choice != 6);

    return 0;
}