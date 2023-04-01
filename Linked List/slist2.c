// Implementation of a Single Linked List using Local Head Node Pointer

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

// function tO create node
NODE *createNode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;

    return a;
}

// function to retrieve last NODE address
NODE *getLastNode(NODE *a)
{
    while (a->next != NULL)
    {
        a = a->next;
    }

    return a;
}

// function to add new NODE at End
void addEnd(NODE **p, int d)
{
    NODE *a = createNode(d);
    NODE *b;

    if (*p == NULL)
    {
        *p = a;
    }
    else
    {
        b = getLastNode(*p);
        b->next = a;
    }
}

// function to add new NODE at Begin
void addBeg(NODE **p, int d)
{
    NODE *a = createNode(d);
    a->next = *p;
    *p = a;
}

// function to display list data
void display(NODE **p)
{
    NODE *a = *p;

    if (a == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nData\n");

        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}

// function to count  NODES
int count(NODE **p)
{
    NODE *a = *p;

    int cnt = 0;

    while (a != NULL)
    {
        cnt++;
        a = a->next;
    }

    return cnt;
}

int main()
{
    int opt, d;

    NODE *st = NULL; // Local HEad NODE Pointer

    while (1)
    {
        printf("\nSingle Linked List\nMenu\n1.Add end\n2.Add Beg\n3.Display\n4.Count\n5.Exit\nOption: ");
        scanf("%d", &opt);

        if (opt > 4)
        {
            break;
        }

        switch (opt)
        {
        case 1:
            printf("\nAdd Data at End: ");
            scanf("%d", &d);
            addEnd(&st, d);
            break;

        case 2:
            printf("\nAdd data at Beg: ");
            scanf("%d", &d);
            addBeg(&st, d);
            break;

        case 3:
            display(&st);
            break;

        case 4:
            printf("\nNode Count: %d", count(&st));
            break;
        }
    }

    return 0;
}