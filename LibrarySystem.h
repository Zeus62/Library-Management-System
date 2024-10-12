#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <set>
#include <map>
#include <string>
#include "Book.h"
using namespace std;

class LibrarySystem {
private:
    set<Book> books;
    map<string, int> bookTitleToId;
    map<int, bool> borrowedBooks;

public:
    void addBook(int id, string title, string author);
    bool searchBookById(int id);
    bool searchBookByTitle(const string &title);
    void displayBooks();
    bool borrowBook(int id);
    bool borrowBookByTitle(const string &title);
    bool returnBook(int id);
    bool returnBookByTitle(const string &title);
};

#endif
