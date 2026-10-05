#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
} SLL;

/* Main / menu */
void displayMenu(void);

/* Add */
void addNew(SLL **ptr);

/* Delete */
void deleteRec(SLL **ptr);
void deleteByRoll(SLL **ptr);
void deleteByName(SLL **ptr);

/* Display */
void showList(SLL *ptr);

/* Modify */
void modifyRec(SLL *ptr);
void modifyByRoll(SLL *ptr);
void modifyByName(SLL *ptr);
void modifyByPercentage(SLL *ptr);

/* Save / Load */
void saveRec(SLL *ptr);
void loadRecords(SLL **ptr);

/* Sort */
void sortList(SLL **ptr);

/* List operations */
void deleteAll(SLL **ptr);
void reverseList(SLL **ptr);

/* Input helpers */
void readName(char *name, int size);
int readPercentage(float *percentage);

#endif
