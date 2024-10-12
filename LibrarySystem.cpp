#include "LibrarySystem.h"

// Add a book to the system with validation for unique ID and title
void LibrarySystem::addBook(int id, string title, string author) {
    // Check for unique ID
    if (books.find(Book(id, "", "")) != books.end()) {
        cout << "Error: A book with ID " << id << " already exists." << endl;
        return;
    }

    // Check for unique title
    if (bookTitleToId.find(title) != bookTitleToId.end()) {
        cout << "Error: A book with the title \"" << title << "\" already exists." << endl;
        return;
    }

    books.insert(Book(id, title, author));
    bookTitleToId[title] = id; // map title to book ID
    cout << "Book added successfully!" << endl;
}

// Search for a book by ID
bool LibrarySystem::searchBookById(int id) {
    auto it = books.find(Book(id, "", ""));
    return it != books.end();
}

// Search for a book by title
bool LibrarySystem::searchBookByTitle(const string &title) {
    return bookTitleToId.find(title) != bookTitleToId.end();
}

// Display all books
void LibrarySystem::displayBooks() {
    if (books.empty()) {
        cout << "The library is empty." << endl;  // Message when no books are available
        return;
    }

    for (auto book : books) {
        book.display();
    }
}

// Borrow a book by ID
bool LibrarySystem::borrowBook(int id) {
    auto it = books.find(Book(id, "", ""));
    if (it != books.end() && borrowedBooks.find(id) == borrowedBooks.end()) {
        borrowedBooks[id] = true;
        const_cast<Book&>(*it).isAvailable = false; // Mark as borrowed
        cout << "Book borrowed successfully!" << endl;
        return true;
    }
    cout << "Book not available or already borrowed." << endl;
    return false;
}

// Borrow a book by title
bool LibrarySystem::borrowBookByTitle(const string &title) {
    if (searchBookByTitle(title)) {
        int id = bookTitleToId[title];
        return borrowBook(id); // borrow by ID once title is mapped
    }
    cout << "Book not found by title." << endl;
    return false;
}

// Return a book by ID
bool LibrarySystem::returnBook(int id) {
    if (borrowedBooks.find(id) != borrowedBooks.end()) {
        borrowedBooks.erase(id);
        auto it = books.find(Book(id, "", ""));
        if (it != books.end()) {
            const_cast<Book&>(*it).isAvailable = true; // Mark as available
            cout << "Book returned successfully!" << endl;
            return true;
        }
    }
    cout << "Invalid book ID or not borrowed." << endl;
    return false;
}

// Return a book by title
bool LibrarySystem::returnBookByTitle(const string &title) {
    if (searchBookByTitle(title)) {
        int id = bookTitleToId[title];
        return returnBook(id); // return by ID once title is mapped
    }
    cout << "Invalid book title or not borrowed." << endl;
    return false;
}
