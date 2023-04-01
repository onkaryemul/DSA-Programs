//Evaluation of Postfix Expression

#include<stdio.h>
#include<ctype.h>
#define M 10

typedef struct stack
{
    int top;
    int arr[M];
}STK;

void init(STK *t)
{
    t->top=-1;
}

void push(STK *t,int d)
{
    t->top++;
    t->arr[t->top]=d;
}

int pop(STK *t)
{
    return t->arr[t->top--];
}

int isEmpty(STK *t)
{
    return (t->top==-1);
}

int comp(int a,int b,char opr)
{
    int res=0;

    switch(opr)
    {
        case '+':
              res=a+b;
              break;

        case '-':
              res=a-b;
              break;

        case '*':
              res=a*b;
              break;

        case '/':
              res=a/b;
              break;
    }

    return res;
}


int main()
{
    STK p;

    char pstr[50],ch;

    int i=0,a,b,res,index;

    static int val[26];

    init(&p);

    printf("\nPostfix Expression : ");
    scanf("%s",pstr);

    while(pstr[i]!='\0')
    {
        if(isalpha(pstr[i]))
        {
            index=pstr[i]-65;

            printf("\nValue of %c : ",pstr[i]);
            scanf("%d",&val[index]);
        }

        i++;
    }

    i=0;

    while(pstr[i]!='\0')
    {
        if(isalpha(pstr[i]))
        {
            index=pstr[i]-65;

            push(&p,val[index]);
        }
        else
        {
            b=pop(&p);

            a=pop(&p);

            res=comp(a,b,pstr[i]);

            push(&p,res);
        }

        i++;
    }

    printf("\nResult : %d",pop(&p));

    return 0;
}


