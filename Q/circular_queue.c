//Circular Queue

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 5

typedef struct cqueue
{
    int arr[M];
    int fr,rr;
}CQ;

void init(CQ *t)
{
    int i=0;

    while(i<M)
    {
        t->arr[i] = -1;

        i++;
    }

    t->rr = t->fr = M-1;
}

int count(CQ *t)
{
    int i=0,cnt=0;

    while(i<M)
    {
        if(t->arr[i] == -1)
        {
            cnt++;
        }

        i++;
    }

    return cnt;
}

void insert(CQ *t,int d)
{
    if(count(t) == 0)
    {
        printf("\nOverflow");
        return ;
    }

    if(t->rr == M-1)
    {
        t->rr=0;
    }
    else
    {
        t->rr++;
    }
    
    t->arr[t->rr]=d;

    return;
}

void remque(CQ *t)
{
    if(count(t) == M)
    {
        printf("\nUnderflow\n");
        return;
    }

    if(t->fr == M-1)
    {
        t->fr = 0;
    }
    else
    {
        t->fr++;
    }

    t->arr[t->fr] = -1;

    return;
}

void display(CQ *t)
{
    int i;

    if(count(t) == M)
    {
        printf("\nEmpty Queue");
        return;
    }

    printf("\nData : \n");
    if(t->fr < t->rr)
    {
        for(i=t->fr+1 ; i<=t->rr ;i++)
        {
            printf("%4d",t->arr[i]);
        }
    }
    else
    {
        for(i=t->fr+1 ; i<M ; i++)
        {
            printf("%4d",t->arr[i]);
        }

        for(i=0 ; i<=t->rr ; i++)
        {
            printf("%4d",t->arr[i]);
        }

    }

    return;
}


int main()
{
    int opt,d;

    CQ p;

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



