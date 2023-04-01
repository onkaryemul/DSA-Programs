
// Create a header file with name "adjlist1.h"

#include<stdio.h>
#include<stdlib.h>
#define M 10

struct list
{
    int data;
    char ch;
    struct list *next;
}*k[M]; // 20 Bytes memory

char ch[M];

struct list *createNode(int d,char ch)
{
    struct list *a;

    a = (struct list *)malloc(sizeof(struct list));

    a->data = d;
    a->ch = ch;
    a->next = NULL;

    return a;
}

void createList()
{
    int i=1,d;
    char ch;

    struct list *p,*q;

    while(i<M)
    {
        printf("\nVertex : ");
        scanf("%d",&d);

        if(d==0)
        {
            break;
        }

        printf("\nLabel : ");
        scanf(" %c",&ch);

        k[i] = p = createNode(d,ch);

        printf("\nAdjacent Nodes : \n");
        while(1)
        {
            scanf("%d",&d);

            if(d==0)
            {
                break;
            }

            p->next = createNode(d,' ');
            p = p->next;         
        }

        i++;
    }

    return;
}



