#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int ID;
    char department[3];
    int age;
    char gender;
    float cgpa;
    char mobileNumber[11];
    struct Student *next;
};

void addStudent();
void searchStudentByID();
void updateStudent();
void displayStudentsByDepartment();
void displayAllStudents();

struct Student *head = NULL;

int main() {
    int choice;
    
    do {
        printf("\nStudent Management System\n");
        printf("1. Store new student information\n");
        printf("2. Search students by ID\n");
        printf("3. Update student information\n");
        printf("4. Display department-wise all students\n");
        printf("5. Display all students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudentByID();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                displayStudentsByDepartment();
                break;
            case 5:
                displayAllStudents();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);
    
    return 0;
}

void addStudent() {
    struct Student *newStudent = (struct Student*)malloc(sizeof(struct Student));
    
    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent->ID);
    printf("Enter student department: ");
    scanf("%s", newStudent->department);
    printf("Enter student age: ");
    scanf("%d", &newStudent->age);
    printf("Enter student gender (M/F): ");
    scanf(" %c", &newStudent->gender);
    printf("Enter student CGPA: ");
    scanf("%f", &newStudent->cgpa);
    printf("Enter student mobile number: ");
    scanf("%s", newStudent->mobileNumber);
    
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        struct Student *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    
    printf("Student added successfully.\n");
}

void searchStudentByID() {
    int searchID;
    printf("Enter student ID to search: ");
    scanf("%d", &searchID);
    
    struct Student *temp = head;
    int found = 0;
    
    while (temp != NULL) {
        if (temp->ID == searchID) {
            printf("Student found:\n");
            printf("Name: %s\nID: %d\nDepartment: %s\nAge: %d\nGender: %c\nCGPA: %.2f\nMobile: %s\n",
                   temp->name, temp->ID, temp->department, temp->age, temp->gender,
                   temp->cgpa, temp->mobileNumber);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    
    if (!found)
        printf("Student with ID %d not found.\n", searchID);
}

void updateStudent() {
    int updateID;
    printf("Enter student ID to update: ");
    scanf("%d", &updateID);
    
    struct Student *temp = head;
    int found = 0;
    
    while (temp != NULL) {
        if (temp->ID == updateID) {
            printf("Enter new CGPA: ");
            scanf("%f", &temp->cgpa);
            printf("Enter new mobile number: ");
            scanf("%s", temp->mobileNumber);
            printf("Student information updated successfully.\n");
            found = 1;
            break;
        }
        temp = temp->next;
    }
    
    if (!found)
        printf("Student with ID %d not found.\n", updateID);
}

void displayStudentsByDepartment() {
    char searchDepartment[50];
    printf("Enter department name to display students: ");
    scanf("%s", searchDepartment);
    
    struct Student *temp = head;
    int found = 0;
    
    printf("Students in department %s:\n", searchDepartment);
    while (temp != NULL) {
        if (strcmp(temp->department, searchDepartment) == 0) {
            printf("Name: %s\nID: %d\nAge: %d\nGender: %c\nCGPA: %.2f\nMobile: %s\n\n",
                   temp->name, temp->ID, temp->age, temp->gender, temp->cgpa, temp->mobileNumber);
            found = 1;
        }
        temp = temp->next;
    }
    
    if (!found)
        printf("No students found in department %s.\n", searchDepartment);
}

void displayAllStudents() {
    struct Student *temp = head;
    
    printf("List of all students:\n");
    while (temp != NULL) {
        printf("Name: %s\nID: %d\nDepartment: %s\nAge: %d\nGender: %c\nCGPA: %.2f\nMobile: %s\n\n",
               temp->name, temp->ID, temp->department, temp->age, temp->gender, temp->cgpa, temp->mobileNumber);
        temp = temp->next;
    }
}
