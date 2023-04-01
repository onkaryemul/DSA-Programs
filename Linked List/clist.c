
//Implementation of Circular Linked List

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef struct circularlist
{
    NODE *st;
}CLIST;

void init(CLIST *t)
{
    t->st=NULL;
}

NODE *createNode(int d)
{
    NODE *a=(NODE *)malloc(sizeof(NODE));

    a->data=d;

    a->next=NULL;

    return a;
}

//add at End
void addEnd(CLIST *t,int d)
{
    NODE *a=createNode(d), *b;

    if(t->st==NULL)
    {
        a->next=a;
    }
    else
    {
        b=t->st;
        a->next=b->next;
        b->next=a;
    }

    t->st=a;
}

//add at Beg
void addBeg(CLIST *t,int d)
{
    NODE *a=createNode(d), *b;

    if(t->st==NULL)
    {
        a->next=a;

        t->st=a;
    }
    else
    {
        b=t->st;
        a->next=b->next;
        b->next=a;
    }

}

//function to delete first NODE 
void delFirst(CLIST *t)
{
    NODE *a=t->st, *b=t->st;

    if(t->st==NULL) // List is Empty
    {
        return;
    }

    if(a->next==a) //list with only one NODE
    {
        t->st=NULL;
    }
    else
    {
        a=a->next;
        b->next=a->next;
    }

    free(a);
}

//function to delete Last NODE 
void delLast(CLIST *t)
{
    NODE *a=t->st, *b=t->st;

    if(t->st==NULL) // List is Empty
    {
        return;
    }

    if(a->next==a) //list with only one NODE
    {
        t->st=NULL;
    }
    else
    {
        b=b->next;

        while(b->next != a)
        {
            b=b->next;
        }

        b->next=a->next;
        t->st=b;
    }

    free(a);
}

//display
void display(CLIST *t)
{
    NODE *a=t->st;

    if(t->st==NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        a=a->next;

        printf("\nData:\n");

        do
        {
            printf("%4d",a->data);

            if(a==t->st)
            {
                break;
            }

            a=a->next;

        } while (1);
        
    }

}


int main()
{
    int opt,d;

    CLIST p;

    init(&p);

    while(1)
    {
        printf("\nMenu\n1.Add End\n2.Add Beg\n3.Del First\n4.Del Last\n5.Display\n6.Exit\nOption: ");
        scanf("%d",&opt);

        if(opt>5)
        {
            break;
        }

        switch(opt)
        {
            case 3:
                delFirst(&p);
                break;

            case 4:
                delLast(&p);
                break;

            case 5:
                display(&p);
                break;

            case 1:
                printf("\nAdd End Data: ");
                scanf("%d",&d);
                addEnd(&p,d);
                break;

            case 2:
                printf("\nAdd Begin Data: ");
                scanf("%d",&d);
                addBeg(&p,d);
                break;
        }
    }
    
    return 0;
}