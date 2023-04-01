//Sentinel Search

#include<stdio.h>

int main()
{
    int x[11],i=0;

    printf("\nEnter array Data : \n");

    while(i<10)
    {
        scanf("%d",&x[i]);

        i++;
    }
    
    printf("\nEnter search value : ");
    scanf("%d",&x[10]);

    for(i=0; x[i] != x[10] ;i++)
    {
        ;   //NULL statements
    }
    
    if(i==10)
    {
        printf("\nNot Found\n");
    }
    else
    {
        printf("\nFound at position %d",i);
    }

    return 0;
}