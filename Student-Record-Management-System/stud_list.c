#include "student.h"

void deleteAll(SLL **ptr)
{
    SLL *del;
    int count = 0;

    while (*ptr != NULL)
    {
        del = *ptr;
        *ptr = del->next;
        free(del);
        count++;
    }

    if (count > 0)
        printf("%d record(s) deleted\n", count);
    else
        printf("No records available\n");
}

void reverseList(SLL **ptr)
{
    SLL *prev;
    SLL *curr;
    SLL *next;

    if (*ptr == NULL)
    {
        printf("No records available\n");
        return;
    }

    prev = NULL;
    curr = *ptr;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *ptr = prev;

    printf("List reversed successfully\n");
}
