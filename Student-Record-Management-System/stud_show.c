#include "student.h"

void showList(SLL *ptr)
{
    if (ptr == NULL)
    {
        printf("\nNo student records available\n");
        return;
    }

    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("%-10s %-30s %-12s\n", "Roll No.", "Name", "Percentage");
    printf("------------------------------------------------------------\n");

    while (ptr != NULL)
    {
        printf("%-10d %-30s %8.2f\n",
               ptr->rollno, ptr->name, ptr->percentage);
        ptr = ptr->next;
    }

    printf("------------------------------------------------------------\n");
}
