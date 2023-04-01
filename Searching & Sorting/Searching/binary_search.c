
// Ordered List

//  Binary Search ---> Sorted List

#include<stdio.h>

int main()
{
    int x[10],i,sv,l,r,mid;

    i=0;

    while(i < 10)
    {
        printf("\nData : ");
        scanf("%d",&x[i]);

        if(i>0)
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

    l=0,r=9;

    do
    {
        mid = (l+r)/2;

        if(x[mid] == sv)
        {
            break;
        }

        if(sv < x[mid])
        {
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }

    } while(l <= r);

    if(l <= r)
    {
        printf("\nFound\n");
    }
    else
    {
        printf("\nNot Found\n");
    }
 
    return 0;
}


