//Priority Queue
  
#include<stdio.h>
#define M 5

typedef struct priorityQ
{
    int fr,rr;
    int arr[M];
}PQ;

void init(PQ *t)
{
    t->rr=-1;
    t->fr=0;
}

void insert(PQ *t,int d)
{
    int i=t->rr;

    if(t->rr==M-1)
    {
        printf("\nOverflow");
        return;
    }

    for( ; i>=0 && d<t->arr[i] ; i--)
    {
        t->arr[i+1]=t->arr[i];
    }

    t->arr[i+1]=d;

    t->rr++;

    return;
}
 
void remque(PQ *t)
{
    int i=t->fr;

    if(t->rr < t->fr)
    {
        printf("\nUnderflow");
        return;
    }

    for( ; i<t->rr ; i++)
    {
        t->arr[i] = t->arr[i+1];
    }

    t->rr--;

    return;
}

void display(PQ *t)
{
    int i=t->fr;
    
    if(t->rr < t->fr)
    {
        printf("\nEmpty Queue");
        return;
    }

    printf("\nData : \n ");
    
    while(i <= t->rr)
    {
        printf("%4d", t->arr[i]);
        i++;
    }

    return;
}


int main()
{
    int opt,d;

    PQ p;

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

