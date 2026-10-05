#include "student.h"

void displayMenu(void)
{
    printf("\n");
    printf("******** STUDENT RECORD MENU ********\n");
    printf("a/A : Add new record\n");
    printf("d/D : Delete a record\n");
    printf("s/S : Show the list\n");
    printf("m/M : Modify a record\n");
    printf("v/V : Save records\n");
    printf("e/E : Exit\n");
    printf("t/T : Sort the list\n");
    printf("l/L : Delete all the records\n");
    printf("r/R : Reverse the list\n");
    printf("Enter your choice: ");
}

int main(void)
{
    SLL *ptr = NULL;
    char op;
    char ch;

    /* Restore records saved during an earlier execution. */
    loadRecords(&ptr);

    while (1)
    {
        displayMenu();
        scanf(" %c", &op);

        switch (op)
        {
            case 'a':
            case 'A':
                addNew(&ptr);
                break;

            case 'd':
            case 'D':
                deleteRec(&ptr);
                break;

            case 's':
            case 'S':
                showList(ptr);
                break;

            case 'm':
            case 'M':
                modifyRec(ptr);
                break;

            case 'v':
            case 'V':
                saveRec(ptr);
                break;

            case 't':
            case 'T':
                sortList(&ptr);
                break;

            case 'l':
            case 'L':
                deleteAll(&ptr);
                break;

            case 'r':
            case 'R':
                reverseList(&ptr);
                break;

            case 'e':
            case 'E':
                printf("\nS/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter choice: ");
                scanf(" %c", &ch);

                if (ch == 's' || ch == 'S')
                    saveRec(ptr);
                else if (ch != 'e' && ch != 'E')
                {
                    printf("Invalid choice. Returning to main menu.\n");
                    break;
                }

                /* Required memory cleanup before termination. */
                deleteAll(&ptr);

                printf("Program terminated\n");
                return 0;

            default:
                printf("Unknown choice\n");
        }
    }
}
