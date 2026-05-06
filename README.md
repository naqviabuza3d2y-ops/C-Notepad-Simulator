# Notepad Simulation in C++

A console-based Notepad simulation built in C++ using custom data structures. This project demonstrates how text editors manage cursor movement, insertion, deletion, and redo operations internally using a doubly linked list and stack.

## Features

- Character-by-character text insertion
- Cursor movement (left and right)
- Delete functionality
- Enter key / newline handling
- Redo support using stack
- Dynamic memory management using linked lists
- Console-based interface

## Data Structures Used

### Doubly Linked List
Used to store and manage text efficiently while allowing cursor movement in both directions.

### Stack
Used for redo operations following the LIFO (Last In First Out) principle.

## Concepts Demonstrated

- Templates in C++
- Dynamic memory allocation
- Linked list operations
- Stack implementation
- Cursor simulation
- Keyboard input handling using `_getch()`

## Technologies

- C++
- Object-Oriented Programming
- Console Programming

## How It Works

- Each character is stored as a node in a doubly linked list.
- A special cursor node (`|`) represents the current cursor position.
- Characters are inserted before the cursor.
- Cursor movement rearranges nodes dynamically.
- Deleted characters are stored in a stack for redo functionality.


## Author

Developed as a Data Structures and Algorithms practice project in C++.
