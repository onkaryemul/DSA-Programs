
//Array Implementation of Stack

#include<stdio.h>
#define M 5

typedef struct stack
{
    int top;
    int arr[M];
}STK;

void init(STK *t)
{
    t->top=-1;
}

int isEmpty(STK *t)
{
    return (t->top == -1);
}

void push(STK *t,int d)
{
    if(t->top == M-1)
    {
        printf("\nOverflow");
    }
    else
    {
        t->top++;
        t->arr[t->top]=d;
    }
}

void pop(STK *t)
{
    if(t->top == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        t->top--;
    }
}

void display(STK *t)
{
    int i;

    if(t->top == -1)
    {
        printf("\nEmpty Stack");
    }
    else
    {
        printf("\nData\n");

        for(i=t->top;i>=0;i--)
        {
            printf("%4d",t->arr[i]);
        }
    }
}


int main()
{
    int d,opt;

    STK p;
    
    init(&p);

    while(1)
    {
        printf("\nStack Menu\n1.Push\n2.Pop\n3.Display\n4.Exit\nOption: ");
        scanf("%d",&opt);

        if(opt>3)
        {
            break;
        }

        switch(opt)
        {
            case 1:
                 if(p.top == M-1)
                 {
                    printf("\nOverflow");
                 }
                 else
                 {
                    printf("\nEnter Data : ");
                    scanf("%d",&d);

                    push(&p,d);
                 }
                 break;

            case 2:
                 pop(&p);
                 break;

            case 3:
                 display(&p);
                 break;
        }

    }

    return 0;
}


