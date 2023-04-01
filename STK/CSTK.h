

//Program to build stack of character type data using array
// 1. Create a header file with name "CSTK.h"

#include<stdio.h>
#include<stdlib.h>
#define M 50

typedef struct charstack
{
    int top;
    char arr[M];
}CSTK;

void init(CSTK *t)
{
    t->top=-1;
}

int isFull(CSTK *t)
{
    return (t->top == M-1);
}

int isEmpty(CSTK *t)
{
    return (t->top == -1);
}

void push(CSTK *t,char ch)
{
    t->top++;
    t->arr[t->top]=ch;
}

char pop(CSTK *t)
{
    return t->arr[t->top--];
}

//Save and close the header file