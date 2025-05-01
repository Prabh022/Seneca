#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[30];
    float gpa;
} Student;


void addStudent(Student students[], int* size);
void displayStudents(const Student students[], int size);
void searchStudent(const Student students[], int size, int id);
void updateStudent(Student students[], int size, int id);
void deleteStudent(Student students[], int* size, int id);
void saveStudentsToFile(const Student students[], int size, const char* filename);
void loadStudentsFromFile(Student students[], int* size, const char* filename);

#endif // STUDENT_RECORD_H
