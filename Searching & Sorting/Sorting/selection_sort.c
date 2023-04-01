
#include<stdio.h>

int main()
{
    int x[5];
    int i,j,pos,tmp;

    for(i=0;i<5;i++)
    {
        printf("x[%d] : ",i);
        scanf("%d",&x[i]);
    }

    printf("\nBefore Sorting : \n");
    for(i=0;i<5;i++)
    {
        printf("%4d",x[i]);
    }

    for(i=0;i<4;i++)
    {
        pos = i;

        for(j=i+1;j<5;j++)
        {
            if(x[j] < x[pos])
            {
                pos = j;
            }
        }

        if(i != pos)
        {
            tmp = x[i];
            x[i] = x[pos];
            x[pos] = tmp;
        }

    }

    printf("\nAfter Sorting : \n");
    for(i=0;i<5;i++)
    {
        printf("%4d",x[i]);
    }

    return 0;
}


