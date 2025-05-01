#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "student.h"

int main() {
    Student students[MAX_STUDENTS];
    int size = 0;
    int choice, id;

    loadStudentsFromFile(students, &size, "student_record.txt");

    do {
        printf("\n--- Student Record Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student by ID\n");
        printf("5. Delete Student by ID\n");
        printf("6. Save and Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent(students, &size);
            break;
        case 2:
            displayStudents(students, size);
            break;
        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchStudent(students, size, id);
            break;
        case 4:
            printf("Enter ID to update: ");
            scanf("%d", &id);
            updateStudent(students, size, id);
            break;
        case 5:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteStudent(students, &size, id);
            break;
        case 6:
            saveStudentsToFile(students, size, "student_record.txt");
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
