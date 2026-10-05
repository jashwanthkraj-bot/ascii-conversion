#include "student.h"

void saveRec(SLL *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "w");

    if (fp == NULL)
    {
        printf("Unable to open student.dat\n");
        return;
    }

    while (ptr != NULL)
    {
        /*
         * Store one record per line. Tabs separate fields so student names
         * can contain spaces.
         */
        fprintf(fp, "%d\t%s\t%.2f\n",
                ptr->rollno, ptr->name, ptr->percentage);

        ptr = ptr->next;
    }

    fclose(fp);
    printf("Records saved successfully\n");
}

void loadRecords(SLL **ptr)
{
    FILE *fp;
    SLL *temp;
    SLL *last;
    char line[150];

    fp = fopen("student.dat", "r");

    if (fp == NULL)
        return;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        temp = malloc(sizeof(SLL));

        if (temp == NULL)
        {
            printf("Memory allocation failed while loading records\n");
            fclose(fp);
            return;
        }

        if (sscanf(line, "%d\t%49[^\t]\t%f",
                   &temp->rollno, temp->name, &temp->percentage) != 3)
        {
            free(temp);
            continue;
        }

        if (temp->rollno <= 0 ||
            temp->percentage < 0.0f ||
            temp->percentage > 100.0f ||
            temp->name[0] == '\0')
        {
            free(temp);
            continue;
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
    }

    fclose(fp);
}
