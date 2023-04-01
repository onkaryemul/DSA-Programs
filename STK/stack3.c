
//Program to build stack of character type data using array
// 1. Create a header file with name "CSTK.h"
//    Save and close the header file

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CSTK.h"

int main()
{
    CSTK p;

    int i=0,j=0;

    char a[50],b[50];

    init(&p);

    printf("\nString : ");
    gets(a);

    while(a[i]!='\0')
    {
        push(&p,a[i++]);
    }

    while( ! isEmpty(&p) )
    {
        b[j++]=pop(&p);
    }

    b[j]='\0';
    
    puts(a); //Welcome

    puts(b); //emocleW

    return 0;
}

