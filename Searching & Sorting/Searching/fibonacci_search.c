
// Fibonacci Search ----> Ordered list

#include<stdio.h>

int main()
{
    int x[10],f1,f2,mid,sv,i=0;

    int first,index;

    f1=0;
    f2=0;
    mid=2;

    printf("\nEnter Ordered Data(in increasing Order) : ");
    while(i < 10)
    {
        scanf("%d",&x[i]);

        if(i > 0)
        {
            if(x[i] < x[i-1])
            {
                printf("\nInvalid\n");
                continue;
            }
        }

        i++;
    }

    printf("\nSearch Value : ");
    scanf("%d",&sv);

    f1=1;
    f2=0;
    mid=2;

    while(f1 < 10)
    {
        f1 = f1 + f2;
        f2 = f1 - f2;
        mid++;
    }

    f2 = f1 - f2;
    f1 = f1 - f2;
    mid--;

    first=0;

    while(mid > 0)
    {
        index = first + f1;

        if( (index > 10) || (sv < x[index]) )
        {
            mid--;
            f2 = f1 - f2;
            f1 = f1 - f2;
        }
        else
        {
            if(sv == x[index])
            {
                break;
            }
            else
            {
                first=index;
                mid = mid - 2;
                f1 = f1 - f2;
                f2 = f2 - f1;
            }

        }

    }

    if(mid > 0)
    {
        printf("\nFound\n");
    }
    else
    {
        printf("\nNot Found\n");
    }

    return 0;
}


