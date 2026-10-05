#include "student.h"

static void updateRecord(SLL *ptr)
{
    char newName[50];
    float newPercentage;
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("\nCurrent details\n");
    printf("Roll       : %d\n", ptr->rollno);
    printf("Name       : %s\n", ptr->name);
    printf("Percentage : %.2f\n", ptr->percentage);

    printf("\nEnter new name: ");
    readName(newName, sizeof(newName));

    while (1)
    {
        printf("Enter new percentage: ");

        if (readPercentage(&newPercentage))
            break;

        printf("Invalid percentage. Enter a value from 0.00 to 100.00\n");
    }

    strcpy(ptr->name, newName);
    ptr->percentage = newPercentage;

    printf("Record modified successfully\n");
}

void modifyRec(SLL *ptr)
{
    char ch;

    if (ptr == NULL)
    {
        printf("No records available\n");
        return;
    }

    printf("\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &ch);

    if (ch == 'r' || ch == 'R')
        modifyByRoll(ptr);
    else if (ch == 'n' || ch == 'N')
        modifyByName(ptr);
    else if (ch == 'p' || ch == 'P')
        modifyByPercentage(ptr);
    else
        printf("Invalid choice\n");
}

void modifyByRoll(SLL *ptr)
{
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

    while (ptr != NULL)
    {
        if (ptr->rollno == roll)
        {
            updateRecord(ptr);
            return;
        }

        ptr = ptr->next;
    }

    printf("Record not found\n");
}

void modifyByName(SLL *ptr)
{
    char name[50];
    int roll;
    int found = 0;
    int c;
    SLL *head = ptr;

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Enter name: ");
    readName(name, sizeof(name));

    printf("\nMatching records:\n");

    while (ptr != NULL)
    {
        if (strcmp(ptr->name, name) == 0)
        {
            printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                   ptr->rollno, ptr->name, ptr->percentage);
            found = 1;
        }

        ptr = ptr->next;
    }

    if (!found)
    {
        printf("Record not found\n");
        return;
    }

    printf("Enter roll number to modify: ");

    if (scanf("%d", &roll) != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Invalid roll number\n");
        return;
    }

    ptr = head;

    while (ptr != NULL)
    {
        if (ptr->rollno == roll && strcmp(ptr->name, name) == 0)
        {
            updateRecord(ptr);
            return;
        }

        ptr = ptr->next;
    }

    printf("Selected record not found\n");
}

/*
 * Percentage search is completed in the same way as the assignment requires:
 * all matching records are displayed first, then the selected roll number
 * identifies the record to modify.
 */
void modifyByPercentage(SLL *ptr)
{
    float percentage;
    int roll;
    int found = 0;
    int c;
    SLL *head = ptr;

    printf("Enter percentage: ");

    if (scanf("%f", &percentage) != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Invalid percentage\n");
        return;
    }

    if (percentage < 0.0f || percentage > 100.0f)
    {
        printf("Invalid percentage\n");
        return;
    }

    printf("\nMatching records:\n");

    while (ptr != NULL)
    {
        if (ptr->percentage == percentage)
        {
            printf("Roll No: %d  Name: %s  Percentage: %.2f\n",
                   ptr->rollno, ptr->name, ptr->percentage);
            found = 1;
        }

        ptr = ptr->next;
    }

    if (!found)
    {
        printf("Record not found\n");
        return;
    }

    printf("Enter roll number to modify: ");

    if (scanf("%d", &roll) != 1)
    {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Invalid roll number\n");
        return;
    }

    ptr = head;

    while (ptr != NULL)
    {
        if (ptr->rollno == roll && ptr->percentage == percentage)
        {
            updateRecord(ptr);
            return;
        }

        ptr = ptr->next;
    }

    printf("Selected record not found\n");
}
