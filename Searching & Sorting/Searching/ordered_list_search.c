
#include<stdio.h>

int main()
{
    int x[11],i=0;

    while(i < 10)
    {
        printf("\nArray Data : ");
        scanf("%d",&x[i]);

        if(i > 0)
        {
            if(x[i] < x[i-1])
            {
                printf("\nInvalid Data\n");
                continue;
            }
        }

        i++;
    }

    printf("\nEnter Search Value : ");
    scanf("%d",&x[10]);

    i=0;

    while(x[i] < x[10])
    {
        i++;
    }

    if(i == 10)
    {
        printf("\nNot Found\n");
    }
    else
    {
        printf("\nFound at position %d\n",i);
    }

    return 0;
}


