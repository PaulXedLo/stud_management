#ifndef STUDENT_H
#define STUDENT_H

// Structure of a student
struct Student
{
    int id;
    char first_name[50];
    char last_name[50];
    int age;
    float gpa;
    struct Student *next;
};
// Function prototypes
void show_menu();
void add_student();
void display_all_students();
void search_student_by_id(int target_id);
void delete_student(int target_id);
#endif