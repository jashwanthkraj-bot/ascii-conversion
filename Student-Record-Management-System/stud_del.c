#include "student.h"

void deleteRec(SLL **ptr)
{
    char ch;
    int c;

    if (*ptr == NULL)
    {
        printf("No records available\n");
        return;
    }

    printf("\n");
    printf("R/r : Enter roll number to delete\n");
    printf("N/n : Enter name to delete\n");
    printf("Enter choice: ");
    scanf(" %c", &ch);

    if (ch == 'r' || ch == 'R')
    {
        deleteByRoll(ptr);
    }
    else if (ch == 'n' || ch == 'N')
    {
        deleteByName(ptr);
    }
    else
    {
        printf("Invalid choice\n");
    }

    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void deleteByRoll(SLL **ptr)
{
    SLL *del;
    SLL *prev;
    int roll;

    printf("Enter roll number: ");

    if (scanf("%d", &roll) != 1)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Invalid roll number\n");
        return;
    }

    if (roll <= 0)
    {
        printf("Roll number must be positive\n");
        return;
    }

    del = *ptr;
    prev = NULL;

    while (del != NULL)
    {
        if (del->rollno == roll)
        {
            if (prev == NULL)
                *ptr = del->next;
            else
                prev->next = del->next;

            free(del);
            printf("Record deleted successfully\n");
            return;
        }

        prev = del;
        del = del->next;
    }

    printf("Record not found\n");
}

void deleteByName(SLL **ptr)
{
    SLL *p;
    SLL *del;
    SLL *prev;
    char name[50];
    int roll;
    int found = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Enter name: ");
    readName(name, sizeof(name));

    p = *ptr;

    printf("\nMatching records:\n");

    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                   p->rollno, p->name, p->percentage);
            found = 1;
        }

        p = p->next;
    }

    if (!found)
    {
        printf("Record not found\n");
        return;
    }

    printf("Enter roll number of record to delete: ");

    if (scanf("%d", &roll) != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Invalid roll number\n");
        return;
    }

    del = *ptr;
    prev = NULL;

    while (del != NULL)
    {
        if (del->rollno == roll && strcmp(del->name, name) == 0)
        {
            if (prev == NULL)
                *ptr = del->next;
            else
                prev->next = del->next;

            free(del);
            printf("Record deleted successfully\n");
            return;
        }

        prev = del;
        del = del->next;
    }

    printf("Selected record not found\n");
}
