
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
        printf("%4d",*(a+i)); 
        // printf("%4d",a[i]);
        i++; 

        // printf("%4d",a[i++]);
    }

}

void bubble(int *a)
{
    int i,j,tmp,flg;

    for(i=0 ; i < (M-1) ;i++)
    {
        flg=0;

        for(j=0; j < (M-(i+1)) ;j++)
        {
            if(a[j] > a[j+1])
            {
                tmp = a[j];

                a[j] = a[j+1];

                a[j+1] = tmp;

                flg=1;
            }
        }

        if(flg == 0)
        {
            break;
        }

    }

}


int main()
{
    int x[M];

    input(x);

    display(x,0);

    bubble(x);

    display(x,1);

    return 0;
}


