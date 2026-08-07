#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student *head = NULL;
void show_menu()
{
    // show main menu
    printf("--Student management system--\n");
    printf("Choose an option: \n");
    printf("1. Add a new student\n");
    printf("2. Remove a student\n");
    printf("3. Review student list\n");
    printf("4. Search student by ID\n");
    printf("0. Exit\n");
}
void add_student()
{
    system("cls");
    struct Student *new = malloc(sizeof(struct Student));
    printf("Enter the first name: \n");
    scanf("%s", new->first_name);
    printf("Enter the last name: \n");
    scanf("%s", new->last_name);
    printf("Enter the age: \n");
    scanf("%d", &new->age);
    printf("Enter the GPA: \n");
    scanf("%f", &new->gpa);
    new->next = NULL;
    if (head == NULL)
    {
        new->id = 1;
        head = new;
    }
    else
    {
        struct Student *current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }
        new->id = current->id + 1;
        current->next = new;
    }
    printf("Successfully added a student with the id of: %d\n\n", new->id);
    save_student();
    fflush(stdin);
}
void save_student()
{
    FILE *student_list = fopen("student_list.csx", "w");
    // check to see if file exists
    if (student_list == NULL)
    {
        printf("Couldn't open file!");
        return;
    }
    struct Student *current = head;
    // loop through student list and save
    while (current != NULL)
    {
        fprintf(student_list, "%d,%s,%s,%d,%.2f\n",
                current->id,
                current->first_name,
                current->last_name,
                current->age,
                current->gpa);
        current = current->next;
    }
    fclose(student_list);
}
void display_all_students()
{
    system("cls");
    FILE *student_list = fopen("student_list.csx", "r");
    // check to see if file exists
    if (student_list == NULL)
    {
        printf("No students. File deosn't exist yet!");
        return;
    }
    // check to see if there is any students
    if (head == NULL)
    {
        printf("There are currently no students.\n\n");
    }
    else
    {
        struct Student *current = head;
        // loop through student list and display data
        while (current != NULL)
        {
            printf("ID: %d | Name: %s %s | Age: %d | GPA: %.2f\n",
                   current->id,
                   current->first_name,
                   current->last_name,
                   current->age,
                   current->gpa);
            // go to the next student
            current = current->next;
        }
        printf("\n");
    }
}
void delete_student(int target_id)
{
}
void load_students()
{
    FILE *student_list = fopen("student_list.csx", "r");
    if (student_list == NULL)
    {
        printf("Error opening");
        return;
    }
    // Temporary variables to hold the data as we read it from the file
    int temp_id, temp_age;
    float temp_gpa;
    char temp_first[50], temp_last[50];
    // Read everything until you hit a comma
    while (fscanf(student_list, "%d,%[^,],%[^,],%d,%f\n", &temp_id, temp_first, temp_last, &temp_age, &temp_gpa) == 5)
    {
        struct Student *new = malloc(sizeof(struct Student));

        new->id = temp_id;
        new->age = temp_age;
        new->gpa = temp_gpa;
        // using strcpy to copy the text into the arrays
        strcpy(new->first_name, temp_first);
        strcpy(new->last_name, temp_last);

        new->next = NULL;
        // linking them back to the list so id's stay in order
        if (head == NULL)
        {
            head = new; // loading first student
        }
        else
        {
            struct Student *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new;
        }
        fclose(student_list);
    }
}
