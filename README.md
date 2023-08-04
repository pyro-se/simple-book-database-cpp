# Book Database Management System (C++) - 13.05.2021

This C++ program serves as a book database management system and was created by me for the purpose of passing the 'Programming in C' course at the university on May 13, 2021. It allows users to add, display, search, and delete books from the database. Book data, including author's first name and last name, book title, publisher, and price, is stored in a binary file named "dane.bin". Users can search for books using various criteria such as the author's name, book title, publisher, or price. The program also calculates the total value of all books in the database.

## Features
- Add books to the database
- Display the book database
- Search books based on different criteria
- Delete books from the database
- Calculate the total value of all books

## How to Use
1. Compile the program using a C++ compiler.
2. Run the executable file.
3. Choose from the menu options to perform various actions.

## Important Note
- The program uses some C-style headers (`stdio.h`, `conio.h`), consider making necessary modifications for compatibility.
- The fixed-size array `Book ks[N]` may limit the number of books in the database. Consider using dynamic memory allocation or `std::vector` for a variable number of books.
- The code uses polish names of functions and variables.

