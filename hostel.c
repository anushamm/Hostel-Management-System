#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int roomNumber;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student limit reached.\n");
        return;
    }

    Student newStudent;
    newStudent.id = studentCount + 1;

    printf("Enter student name: ");
    scanf("%s", newStudent.name);

    printf("Enter room number: ");
    scanf("%d", &newStudent.roomNumber);

    students[studentCount++] = newStudent;
    printf("Student added successfully.\n");
}

void viewStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("ID\tName\t\tRoom Number\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%s\t\t%d\n", students[i].id, students[i].name, students[i].roomNumber);
    }
}

void searchStudent() {
    if (studentCount == 0) {
        printf("No students to search.\n");
        return;
    }

    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Student found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Room Number: %d\n", students[i].roomNumber);
            return;
        }
    }

    printf("Student with ID %d not found.\n", id);
}

int main() {
    int choice;

    while (1) {
        printf("\nHostel Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
