//Linked list implementation of Queue

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct queue
{
    NODE *fr;
    NODE *rr;
}Q;

void init(Q *t)
{
    t->fr=NULL;
    t->rr=NULL;
}

NODE *createNode(int d)
{
    NODE *a=(NODE *)malloc(sizeof(NODE));

    a->data=d;
    a->next=NULL;

    return a;
}

void insert(Q *t, int d)  //insert at the end
{
    NODE *a=createNode(d), *b=t->rr;
    
    if(t->fr == NULL)
    {
        t->fr=a;
    }
    else
    {
        b->next=a;
    }

    t->rr=a;

    return;
}

//function
void remque(Q *t)
{
    NODE *a=t->fr;

    if(t->fr==NULL)
    {
        printf("\nUnderflow");
        return;
    }

    t->fr=a->next;

    if(t->fr==NULL)
    {
        t->rr=NULL;
    }

    free(a);

    return;
}

void display(Q *t)
{
    NODE *a=t->fr;

    if(t->fr==NULL)
    {
        printf("\nEmpty Queue");
    }
    else
    {
        printf("\nData : \n");

        while(a!=NULL)
        {
            printf("%4d",a->data);

            a=a->next;
        }

    }

    return;
}


int main()
{
    int opt,d;

    Q p;

    init(&p);

    while(1)
    {
        printf("\nMenu\n1.Insert\n2.Remove\n3.Display\n4.Exit\nOption : ");
        scanf("%d",&opt);

        if(opt>3)
        {
            break;
        }

        switch(opt)
        {
            case 1:
                printf("\nEnter data : ");
                scanf("%d",&d);
                insert(&p,d);
                break;

            case 2:
                remque(&p);
                break;

            case 3:
                display(&p);
                break;
        }
    }

    return 0;
}

