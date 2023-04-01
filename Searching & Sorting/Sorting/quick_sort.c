
// Quick Sort

#include<stdio.h>

#define M 10

void input(int *a)
{
    int i=0;

    printf("\nArray Data :\n");
    while(i < M)
    {
        scanf("%d",(a+i));
        i++;
    }

}

void display(int *a , int flg)
{
    int i=0;

    if(flg == 0)
    {
        printf("\nBefore Sorting :\n");
    }
    else
    {
        printf("\nAfter Sorting :\n");
    }

    while(i < M)
    {
        printf("%4d",a[i]);
        i++;
    }

}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void pivot(int *a , int l , int r)
{
    if( a[l] > a[r])
    {
        swap( a+l , a+r);
    }
}

int partition(int *a , int l , int r)
{
    int i=l , j=r , k;

    pivot(a,l,r);

    k = a[l]; // pivot element

    do
    {
        do
        {
            ++i;
        } while (a[i] < k);

        do
        {
            --j;
        } while (a[j] > k);
        
        if(i < j)
        {
            swap( a+i , a+j);
        }
        
    } while ( i < j);

    swap( a+j , a+l);

    return j;
}

void quick(int *a , int l , int r)
{
    int k;

    if(l < r)
    {
        k = partition( a , l , r);

        quick( a , l , k-1);

        quick( a , k+1 ,r);
    }

}


int main()
{
    int x[M];

    input(x);

    display(x,0);

    quick(x , 0 , M-1);

    display(x , 1);

    return 0;
}


