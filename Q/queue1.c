//Array Implementation of Queue

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 5

typedef struct queue
{
    int arr[M];
    int fr,rr;
}Q;

void init(Q *t)
{
    t->fr=0;
    t->rr=-1;
}

int isEmpty(Q *t)
{
    return t->rr < t->fr;
}

int isFull(Q *t)
{
    return t->rr == M-1;
}

void insert(Q *t,int d)
{
    if(isFull(t))
    {
        printf("\nOverflow");
        return;
    }
    
    t->rr++;

    t->arr[t->rr]=d;
}

void remque(Q *t)
{
    if(isEmpty(t))
    {
        printf("\nUnderflow");
        return;
    }

    t->fr++;
}

void display(Q *t)
{
    int i;

    if(isEmpty(t))
    {
        printf("\nEmpty Queue");;
        return;
    }

    printf("\nData\n");

    for(i=t->fr ; i<=t->rr ; i++)
    {
        printf("%4d",t->arr[i]);
    }

}


int main()
{
    int opt,d;

    Q p;

    init(&p);

    while(1)
    {
        printf("\nMenu\n1.Inset\n2.Remove\n3.Display\n4.Exit\nOption : ");
        scanf("%d",&opt);

        if(opt>3)
        {
            break;
        }

        switch(opt)
        {
            case 1:
                 printf("\nData : ");
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



