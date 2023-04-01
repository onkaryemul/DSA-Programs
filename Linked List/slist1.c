// Implementation of a Single linked list using  Global Head Node Pointer:

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *st = NULL; // Global Head Node Pointer

// function to create node
NODE *createNode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;

    return a;
}

// function to retrieve last NODE address
NODE *getLastNode()
{
    NODE *a = st;

    while (a->next != NULL)
    {
        a = a->next;
    }

    return a;
}

// function to display list data
void display()
{
    NODE *a = st;

    if (st == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nData: ");

        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}

// function to add new NODE at End
void addEnd(int d)
{
    NODE *a, *b;

    a = createNode(d);

    if (st == NULL)
    {
        st = a;
    }
    else
    {
        b = getLastNode();
        b->next = a;
    }
}

// function to add new NODE at Begin
void addBeg(int d)
{
    NODE *a;

    a = createNode(d);

    a->next = st;

    st = a;
}

// function to count the no. of nodes from the list
int count()
{
    int cnt = 0;
    NODE *a = st;

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

    while (1)
    {
        printf("\nSingle Linked List\nMenu\n1.Add End\n2.Add Beg\n3.Display\n4.Count\n5.Exit\noption: ");
        scanf("%d", &opt);

        if (opt > 4)
            break;

        switch (opt)
        {
        case 1:
            printf("\nAdd Data at End: ");
            scanf("%d", &d);
            addEnd(d);
            break;

        case 2:
            printf("\nAdd data at Beg: ");
            scanf("%d", &d);
            addBeg(d);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nNode Count: %d", count());
            break;
        }
    }

    return 0;
}