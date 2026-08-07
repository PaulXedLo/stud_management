#include "student.h"
#include <stdio.h>
#include <stdlib.h>
struct Student *head = NULL;
void show_menu()
{
    printf("--Student management system--\n");
    printf("Choose an option: \n");
    printf("1. Add a new student\n");
    printf("2. Remove a student\n");
    printf("3. Review student list\n");
    printf("4. Search student by ID\n\n");
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
    if (head = NULL)
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
}