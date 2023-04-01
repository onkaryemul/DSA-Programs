//Probability Search

#include<stdio.h>

int main()
{
    int x[10],sv;
    int i=0;
    int j;
    int tmp;

    printf("\nEnter array Data : \n");

    while(i<10)
    {
        scanf("%d",&x[i]);

        i++;
    }
 
    while(1)
    {
        printf("\nEnter search value : ");
        scanf("%d",&sv);

        if(sv==0)
        {
            break;
        }

        for(i=0;i<10;i++)
        {
            if(x[i]==sv)
            {
                break;
            }
        }

        if(i==10)
        {
            printf("\nNot Found\n");
        }
        else
        {
            printf("\nFound at Position %d",i);

            j=i-1;

            if(j>0)
            {
               tmp=x[j];
               x[j]=x[i];
               x[i]=tmp;
            }

        }

    }

    return 0;
}



