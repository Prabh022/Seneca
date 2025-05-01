\# Student Record Management System (C Language)

This project is a simple console-based Student Record Management System written in C. It allows users to add, view, search, update, delete, and save student records using basic arrays and file handling.

---

## 📁 Files Included

- `main.c` – The main file that handles the user interface and calls the required functions.
- `student.c` – Contains function implementations for managing student records.
- `student.h` – Header file with the `Student` struct and function prototypes.
- `student_record.txt` – A text file used for saving and loading student data.

---

## 🧠 Features

- Add new student records (up to 100 students).
- Display all student records.
- Search for a student by ID.
- Update a student record by ID.
- Delete a student record by ID.
- Save and load records using a file (`student_record.txt`).

---

## 🛠️ How to Compile

To compile the program using GCC, use the following command in your terminal or command prompt:

```bash
gcc main.c student.c -o student_program

