#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H

#include <set>
#include <map>
#include "Book.h"

class LibrarySystem {
private:
    set<Book> books; // for ordered storage by ID
    map<string, int> bookTitleToId; // hash table to map title to ID
    map<int, bool> borrowedBooks;   // hash table to track borrowed books

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

#endif // LIBRARYSYSTEM_H
