#include "student.h"

void readName(char *name, int size)
{
    int c;
    size_t len;

    while (1)
    {
        if (fgets(name, size, stdin) == NULL)
        {
            name[0] = '\0';
            return;
        }

        len = strlen(name);

        if (len > 0 && name[len - 1] == '\n')
        {
            name[len - 1] = '\0';
        }
        else
        {
            /* Clear remaining characters if the input was too long. */
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }

        if (name[0] != '\0')
            return;

        printf("Name cannot be empty. Enter student name: ");
    }
}

int readPercentage(float *percentage)
{
    if (scanf("%f", percentage) != 1)
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        return 0;
    }

    if (*percentage < 0.0f || *percentage > 100.0f)
        return 0;

    return 1;
}

void addNew(SLL **ptr)
{
    SLL *temp;
    SLL *last;
    SLL *p;
    int roll = 1;
    int c;

    temp = malloc(sizeof(SLL));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    /* Find the smallest positive roll number not already in use. */
    while (1)
    {
        int found = 0;
        p = *ptr;

        while (p != NULL)
        {
            if (p->rollno == roll)
            {
                found = 1;
                break;
            }
            p = p->next;
        }

        if (!found)
            break;

        roll++;
    }

    temp->rollno = roll;

    /* Remove the newline left by scanf before using fgets. */
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Roll number : %d\n", temp->rollno);
    printf("Enter student name: ");
    readName(temp->name, sizeof(temp->name));

    while (1)
    {
        printf("Enter percentage: ");

        if (readPercentage(&temp->percentage))
            break;

        printf("Invalid percentage. Enter a value from 0.00 to 100.00\n");
    }

    temp->next = NULL;

    if (*ptr == NULL)
    {
        *ptr = temp;
    }
    else
    {
        last = *ptr;

        while (last->next != NULL)
            last = last->next;

        last->next = temp;
    }

    printf("Record added successfully\n");
}
