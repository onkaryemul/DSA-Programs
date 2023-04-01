
// Create a header file with name "adjlist.h"

#include<stdio.h>
#include<stdlib.h>
#define M 10

struct list
{
    int data;
    struct list *next;
}*k[M]; // 20 Bytes memory

struct list *createNode(int d)
{
    struct list *a;

    a = (struct list *)malloc(sizeof(struct list));

    a->data = d;
    a->next = NULL;

    return a;
}

void createList()
{
    int i=1 , d;

    struct list *p,*q;

    while(i<M)
    {
        printf("\nVertex : ");
        scanf("%d",&d);

        if(d==0)
        {
            break;
        }

        k[i] = p = createNode(d);

        printf("\nAdjacent Nodes : \n");
        while(1)
        {
            scanf("%d",&d);

            if(d==0)
            {
                break;
            }

            p->next = createNode(d);
            p = p->next;         
        }

        i++;
    }

    return;
}



