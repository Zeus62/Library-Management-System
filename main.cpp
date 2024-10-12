#include <iostream>
#include "LibrarySystem.h"
using namespace std;

int main() {
    LibrarySystem library;

    // Add books
    library.addBook(101, "C++ Programming", "Bjarne Stroustrup");
    library.addBook(102, "Clean Code", "Robert C. Martin");
    library.addBook(103, "The Pragmatic Programmer", "Andrew Hunt");

    int choice, id;
    string title;
    do {
        cout << "\nLibrary System Menu:\n";
        cout << "1. Display all books\n";
        cout << "2. Search for a book by ID\n";
        cout << "3. Search for a book by title\n";
        cout << "4. Borrow a book by ID\n";
        cout << "5. Borrow a book by title\n";
        cout << "6. Return a book by ID\n";
        cout << "7. Return a book by title\n";
        cout << "8. Exit\n";
        cout << "Enter your choice:  ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayBooks();
                break;
            case 2:
                cout << "Enter book ID to search: ";
                cin >> id;
                if (library.searchBookById(id)) {
                    cout << "Book found!" << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            case 3:
                cout << "Enter book title to search: ";
                cin.ignore();
                getline(cin, title);
                if (library.searchBookByTitle(title)) {
                    cout << "Book found!" << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            case 4:
                cout << "Enter book ID to borrow: ";
                cin >> id;
                library.borrowBook(id);
                break;
            case 5:
                cout << "Enter book title to borrow: ";
                cin.ignore();
                getline(cin, title);
                library.borrowBookByTitle(title);
                break;
            case 6:
                cout << "Enter book ID to return: ";
                cin >> id;
                library.returnBook(id);
                break;
            case 7:
                cout << "Enter book title to return: ";
                cin.ignore();
                getline(cin, title);
                library.returnBookByTitle(title);
                break;
            case 8:
                cout << "Exiting system." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
