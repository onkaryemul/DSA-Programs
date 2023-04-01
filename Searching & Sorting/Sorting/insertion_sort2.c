
#include<stdio.h>

#define M 5

int main()
{
    int x[M],val,i,j;

    for(i=0;i<M;i++)
    {
        printf("\nEnter No. : ");
        scanf("%d",&val);

        for(j=i-1 ; j>=0 && x[j]>val ;j--)
        {
            x[j+1] = x[j];
        }

        x[j+1] = val;
    }

    printf("\nData : \n");
    for(i=0;i<M;i++)
    {
        printf("%4d",x[i]);
    }

    return 0;
}



