#include "student.h"

void sortList(SLL **ptr)
{
    char ch;

    if (*ptr == NULL)
    {
        printf("No records available\n");
        return;
    }

    printf("\n");
    printf("N/n : Sort by name\n");
    printf("P/p : Sort by percentage\n");
    printf("Enter choice: ");
    scanf(" %c", &ch);

    if (ch == 'n' || ch == 'N')
    {
        /*
         * Selection sort by changing links, not by copying student data.
         * This keeps the operation focused on the singly linked list.
         */
        SLL *sorted = NULL;

        while (*ptr != NULL)
        {
            SLL **minPtr = ptr;
            SLL **p = ptr;

            while ((*p)->next != NULL)
            {
                if (strcmp((*p)->next->name, (*minPtr)->name) < 0)
                    minPtr = &(*p)->next;

                p = &(*p)->next;
            }

            SLL *min = *minPtr;
            *minPtr = min->next;

            min->next = sorted;
            sorted = min;
        }

        /* Reverse the temporary sorted list to obtain ascending order. */
        while (sorted != NULL)
        {
            SLL *node = sorted;
            sorted = sorted->next;

            node->next = *ptr;
            *ptr = node;
        }

        printf("Sorted by name\n");
    }
    else if (ch == 'p' || ch == 'P')
    {
        /*
         * Sort by descending percentage by rearranging nodes.
         * If percentages are equal, their existing relative order is kept.
         */
        SLL *sorted = NULL;

        while (*ptr != NULL)
        {
            SLL **bestPtr = ptr;
            SLL **p = ptr;

            while ((*p)->next != NULL)
            {
                if ((*p)->next->percentage > (*bestPtr)->percentage)
                    bestPtr = &(*p)->next;

                p = &(*p)->next;
            }

            SLL *best = *bestPtr;
            *bestPtr = best->next;

            best->next = NULL;

            if (sorted == NULL)
            {
                sorted = best;
            }
            else
            {
                SLL *last = sorted;
                while (last->next != NULL)
                    last = last->next;

                last->next = best;
            }
        }

        *ptr = sorted;
        printf("Sorted by percentage\n");
    }
    else
    {
        printf("Invalid choice\n");
    }
}
