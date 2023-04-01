
// Radix Sort 

/*
   1. This sorting technique uses queue data structure.
   2. Every element from array must be with same length.
*/

#include<stdio.h>

#define M 10

void input(int *a)
{
    int i=0;

    printf("\nData : \n");
    while(i < M)
    {
        scanf("%d",a+i);

        if( (a[i] < 100) || (a[i] > 999) )
        {
            printf("\nInvalid Input\n");
        }
        else
        {
            i++;
        }

    }

    return;
}

void display(int *a,int flg)
{
    int i=0;

    if(flg == 0)
    {
        printf("\nBefore Sorting : \n");
    }
    else
    {
        printf("\nAfter Sorting : \n");
    }

    while(i < M)
    {
        printf("%4d",a[i]);
        i++;
    }

    return;
}

struct queue
{
    int arr[M];
    int fr,rr;
}Q[10];

void init()
{
    int i=0;

    while(i < M)
    {
        Q[i].fr = 0;
        Q[i].rr = -1;
        i++;
    }

}

int getIndex(int no, int pos)
{
    int index;

    switch(pos)
    {
        case 1: // right most
            index = no%10;
            break;

        case 2: // middle digit
            index = (no/10)%10;
            break;
        
        case 3: // left most
            index = (no/100);
            break;
        
    }

    return index;
}

void insert(int *a,int pos)
{
    int i=0,index,j;

    while(i < M)
    {
        index = getIndex( a[i] , pos);

        j = ++Q[index].rr;
        
        Q[index].arr[j] = a[i];

        i++;
    }

}

void remque(int *a)
{
    int i=0,j=0,k=0;

    while(i<M)
    {
        j=0;

        while(j <= Q[i].rr)
        {
            a[k++] = Q[i].arr[j];
            j++;
        }

        i++;
    }

}

void radix(int *a)
{
    int i=1;

    while(i<=3)
    {
        init();

        insert(a,i);

        remque(a);

        i++;
    }

}


int main()
{
    int x[M];
    
    input(x);

    display(x,0);

    radix(x);

    display(x,1);

    return 0;
}


