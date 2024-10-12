#include "LibrarySystem.h"
#include <iostream>
using namespace std;

void LibrarySystem::addBook(int id, string title, string author) {
    books.insert(Book(id, title, author));
    bookTitleToId[title] = id;
}

bool LibrarySystem::searchBookById(int id) {
    auto it = books.find(Book(id, "", ""));
    return it != books.end();
}

bool LibrarySystem::searchBookByTitle(const string &title) {
    return bookTitleToId.find(title) != bookTitleToId.end();
}

void LibrarySystem::displayBooks() {
    for (const auto& book : books) {
        book.display();
    }
}

bool LibrarySystem::borrowBook(int id) {
    auto it = books.find(Book(id, "", ""));
    if (it != books.end() && borrowedBooks.find(id) == borrowedBooks.end()) {
        borrowedBooks[id] = true;
        const_cast<Book&>(*it).isAvailable = false;
        cout << "Book borrowed successfully!" << endl;
        return true;
    }
    cout << "Book not available or already borrowed." << endl;
    return false;
}

bool LibrarySystem::borrowBookByTitle(const string &title) {
    if (searchBookByTitle(title)) {
        int id = bookTitleToId[title];
        return borrowBook(id);
    }
    cout << "Book not found by title." << endl;
    return false;
}

bool LibrarySystem::returnBook(int id) {
    if (borrowedBooks.find(id) != borrowedBooks.end()) {
        borrowedBooks.erase(id);
        auto it = books.find(Book(id, "", ""));
        if (it != books.end()) {
            const_cast<Book&>(*it).isAvailable = true;
            cout << "Book returned successfully!" << endl;
            return true;
        }
    }
    cout << "Invalid book ID or not borrowed." << endl;
    return false;
}

bool LibrarySystem::returnBookByTitle(const string &title) {
    if (searchBookByTitle(title)) {
        int id = bookTitleToId[title];
        return returnBook(id);
    }
    cout << "Invalid book title or not borrowed." << endl;
    return false;
}
