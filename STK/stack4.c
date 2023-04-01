
//Program to check inputed expression has balanced parenthesis or not

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CSTK.h"

int main()
{
    char p[50],ch;
    
    int i=0,flg=0;

    CSTK a;

    init(&a);

    printf("\nExpression : ");
    scanf("%s",p);

    while(p[i]!='\0')
    {
        if(p[i]=='(')
        {
            push(&a,p[i]);
            flg=1;
        }
        else
        {
            if(p[i]==')')
            {
                if(isEmpty(&a))
                {
                    break;
                }

                pop(&a);
            }

        }

        i++;
    }

    if(p[i]=='\0')
    {
        if(isEmpty(&a))
        {
            if(flg==0)
            {
                printf("\nNo Parenthesis");
            }
            else
            {
                printf("\nBalanced");
            }
        }
        else
        {
            printf("\nUnbalanced EX Lt");
        }
    }
    else
    {
        printf("\nUnbalanced Ex Rt");
    }

    return 0;
}