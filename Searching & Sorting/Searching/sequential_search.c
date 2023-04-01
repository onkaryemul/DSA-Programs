// Sequential Search

#include<stdio.h>

int main()
{
    int arr[10];
    int sv;
    int i;

    printf("\nEnter 10 elements to store in an array : ");
    for(i=0;i<10;i++)
    {
        printf("\narr[%d] = ",i);
        scanf("%d",&arr[i]);
    }

    printf("\nEnter search value : ");
    scanf("%d",&sv);

    for(i=0;i<10;i++)
    {
        if(arr[i]==sv)
        {
            break;
        }

    }
    
    if(i==10)
    {
        printf("\nNot Found");
    }
    else
    {
        printf("\nFound at position %d \n",i);
    }

    return 0;
}



