#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(Student students[], int* size) {
    if (*size >= MAX_STUDENTS) {
        printf("Maximum student limit reached.\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &students[*size].id);
    printf("Enter Name: ");
    scanf("%s", students[*size].name);
    printf("Enter GPA: ");
    scanf("%f", &students[*size].gpa);

    (*size)++;
    printf("Student added successfully.\n");
}

void displayStudents(const Student students[], int size) {
    if (size == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d | Name: %s | GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
    printf("------------------------\n");
}

void searchStudent(const Student students[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            printf("Found: ID: %d | Name: %s | GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void updateStudent(Student students[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == id) {
            printf("Enter new Name: ");
            scanf("%s", students[i].name);
            printf("Enter new GPA: ");
            scanf("%f", &students[i].gpa);
            printf("Student updated.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void deleteStudent(Student students[], int* size, int id) {
    for (int i = 0; i < *size; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *size - 1; j++) {
                students[j] = students[j + 1];
            }
            (*size)--;
            printf("Student deleted.\n");
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void saveStudentsToFile(const Student students[], int size, const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d %s %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    fclose(fp);
    printf("Records saved to file.\n");
}

void loadStudentsFromFile(Student students[], int* size, const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("No file found. Starting with empty records.\n");
        return;
    }

    *size = 0;
    while (fscanf(fp, "%d %29s %f", &students[*size].id, students[*size].name, &students[*size].gpa) == 3) {
        (*size)++;
        if (*size >= MAX_STUDENTS) break;
    }

    fclose(fp);
    printf("Records loaded from file.\n");
}
