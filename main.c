#include <stdio.h>
#include "student.h"

int main(void)
{
    load_students();
    int option;
    while (1)
    {
        show_menu();
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            add_student();
            break;
        case 3:
            display_all_students();
            break;
        default:
            printf("Invalid option, choose between 1-5\n");
            break;
        case 0:
            printf("Exiting.");
            return 0;
        }
    }
    return 0;
}