
#include<stdio.h>

#define M 5

void input(int *a)
{
    int i=0;

    printf("\nArray Data : ");
    while(i < M)
    {
        scanf("%d",a+i);
        i++;
    }

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
        printf("%4d",a[i++]);

        /*
            printf("%4d",*(a+i));
            i++;
        */
    }

}

void insertion(int *a)
{
    int i,j,val;

    for(i=1;i<M;i++) // for(i=0 ; i<(M-1) ;i++)
    {
        for( val=a[i], j=i-1 ; j>=0 ; j--)
        {
            if(a[j]>val)
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }
        }

        a[j+1] = val;
    }

}


int main()
{
    int x[M];

    input(x);

    display(x,0);

    insertion(x);

    display(x,1);

    return 0;
}


