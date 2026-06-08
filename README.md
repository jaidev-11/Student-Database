# Student-Database Management System

  [![Language](https://img.shields.io/badge/Language-C-08795C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
  [![Data Structure](https://img.shields.io/badge/Data%20Structure-Linked%20List-6A5ACD?style=for-the-badge)](https://en.wikipedia.org/wiki/Linked_list)
  [![Memory](https://img.shields.io/badge/Memory-Dynamic%20Allocation-critical?style=for-the-badge)](https://en.wikipedia.org/wiki/C_dynamic_memory_allocation)
  [![Interface](https://img.shields.io/badge/Interface-CLI%20Linux-0078D6?style=for-the-badge)](https://en.wikipedia.org/wiki/Command-line_interface)
 
---------------------------------------------------------------------------------

## Overview

A console-based **Student Database Management System** implemented from scratch in **C**, using a **singly linked list**.

The goal of this project was to understand how **data can be managed manually in memory** — without arrays. Every node is heap-allocated, manually managed, and every case is been handled explicitly.

It focuses on **manipulation of pointers, dynamic memory allocation, and real-world edge cases** like duplicate names and missing roll numbers.

---------------------------------------------------------------------------------
## 💡 What This Program Do

Using a **menu-driven CLI**, you can:

- ➕ Add new student records
- ❌ Delete records — by roll number or by name
- ✏️  Modify existing records
- 📋 Display all records in a formatted list
- 🔀 Sort records — by roll number, name, or marks
- 🔁 Reverse the entire linked list
- 💾 Save all records to a file
- 🧹 Free's all allocated memory on exit

The program maintains a list of student records where each record contains:

- Roll Number
- Name
- Marks

---------------------------------------------------------------------------------
## ⚙️ How It Works

The entire system is based of linked list, where each student is stored as a node. The program handles multiple scenarios some:

- While adding a student  → it checks for missing roll numbers and fills the gap
- While deleting by name  → it handles duplicate names safely
- While modifying         → it allows selection based on roll number or name
- While sorting           → it rearranges data without changing node links

---------------------------------------------------------------------------------

## 📂 Structure of the project

Student_database

- std_add.c       → Menu system & program entry point
- std_del.c       → Provides options for deletion of data
- std_mod.c       → Provides options for modification of data
- std_save.c      → Provides options for sorting & saving data
- std_show.c      → Provides options for displaying data
- header.h        → Student struct + all function declarations
- student.dat     → Output file where records are saved

---------------------------------------------------------------------------------

## How to Run

# Compile
```bash
gcc std_add.c std_del.c std_mod.c std_save.c std_show.c -o std
```
# Run
```bash
./std
```
---------------------------------------------------------------------------------

## 📌 Example Flow

1. Start the program
2. Add multiple student records
3. Delete or modify specific entries
4. Sort the list (by roll no / name / marks)
5. Save records to file
6. Exit

---------------------------------------------------------------------------------

## 🧠 What I Learned

Upon working on this project, I learned
- Implemeting linked list from scratch
- Managing memory
- Dealing with edge case(Duplicate names/ Missing Rollno.)
- Writing & mantaining C code

---------------------------------------------------------------------------------

## 🚀 Future Improvements

- Load data from file upon startup
- Add search function
- Integration with database

---------------------------------------------------------------------------------
