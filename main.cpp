#include <iostream>
#include "LibrarySystem.h"

int main() {
    LibrarySystem library;

    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary System Menu:\n";
        cout << "1. Display all books\n";
        cout << "2. Add a book\n"; // New option for adding a book
        cout << "3. Search for a book by ID\n";
        cout << "4. Search for a book by title\n";
        cout << "5. Borrow a book by ID\n";
        cout << "6. Borrow a book by title\n";
        cout << "7. Return a book by ID\n";
        cout << "8. Return a book by title\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2: // Adding the new case for adding a book
                cout << "Enter book ID: ";
                cin >> id;
                cin.ignore(); // Clear the newline character from the input buffer
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(id, title, author); // Call the addBook method
                break;
            case 3:
                cout << "Enter book ID to search: ";
                cin >> id;
                if (library.searchBookById(id)) {
                    cout << "Book found!" << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            case 4:
                cout << "Enter book title to search: ";
                cin.ignore();
                getline(cin, title);
                if (library.searchBookByTitle(title)) {
                    cout << "Book found!" << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            case 5:
                cout << "Enter book ID to borrow: ";
                cin >> id;
                library.borrowBook(id);
                break;
            case 6:
                cout << "Enter book title to borrow: ";
                cin.ignore();
                getline(cin, title);
                library.borrowBookByTitle(title);
                break;
            case 7:
                cout << "Enter book ID to return: ";
                cin >> id;
                library.returnBook(id);
                break;
            case 8:
                cout << "Enter book title to return: ";
                cin.ignore();
                getline(cin, title);
                library.returnBookByTitle(title);
                break;
            case 9:
                cout << "Exiting system." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 9);

    return 0;
}
