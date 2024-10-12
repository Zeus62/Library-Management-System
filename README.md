# Library Management System

This Library Management System is a console-based C++ application designed to manage books, user interactions, and the borrowing/returning of books efficiently. It simulates key functionalities of a real-world library, allowing users to search for, borrow, and return books using either their ID or title.

## Features

- **Book Management:** Easily add and organize books using unique IDs, titles, and authors. The system ensures ordered storage of books, simplifying book searches.

- **Search Functionality:**
  - **Search by ID:** Locate a book quickly using its unique identifier.
  - **Search by Title:** Find books by their title, mapped to their corresponding ID for fast look-up using a hash table.

- **Borrowing & Returning:**
  - **Borrow a Book:** Users can borrow books based on their ID or title. The system ensures that unavailable books cannot be borrowed twice.
  - **Return a Book:** After a book is returned, it becomes available for other users to borrow again, tracked via a hash table for efficiency.

- **Availability Tracking:** Each book's availability is dynamically updated, making it easy to keep track of which books are currently in circulation.

## Technical Highlights

- **Data Structures:** The system uses a combination of efficient data structures for optimal performance:
  - **std::set:** Books are stored in an ordered set by their ID for fast look-up.
  - **std::map:** Hash tables are used to map book titles to IDs and track borrowed books for quick access and state management.

- **Object-Oriented Programming (OOP):** Encapsulation and data abstraction principles are followed, making the system modular, maintainable, and extensible. Books are represented as objects, with each book encapsulating its ID, title, author, and availability status.

- **User Interaction:** The application features a simple, interactive console menu allowing users to navigate through different functionalities like displaying books, searching, borrowing, and returning with ease.

## Future Improvements

- Add support for user registration and login.
- Integrate a graphical user interface (GUI) for a more interactive experience.
- Implement book categorization and sorting by different criteria (e.g., author, genre).
