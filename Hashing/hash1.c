
// Collision Resolution using linear Probing

#include<stdio.h>

struct student
{
    int no;
    char nm[15];
}p[10];

void init()
{
    int i=0;

    while(i < 10)
    {
        p[i].no = 0;

        p[i].nm[0]='\0';

        i++;
    }

}

int hash(int n)
{
    return ( n%10 ); // Modulo-division method
}

void insert()
{
    int no , hval , i=0;

    while(1)
    {
        printf("\nRoll No. : ");
        scanf("%d",&no);

        if(no == 0)
        {
            break;
        }

        hval = hash(no);

        if( p[hval].no == 0 ) // home address
        {
            p[hval].no = no;

            printf("\nName : ");
            scanf("%s",p[hval].nm);

            printf("\nInsertion at home address\n");

            continue;
        }

        printf("\nCollision Occured\n");

        for(i=hval+1 ; i<10 ; i++)
        {
            if( p[i].no == 0)
            {
                p[i].no = no;

                printf("\nName : ");
                scanf("%s",p[i].nm);

                printf("\nInsertion on collision path\n");

                break;
            }
        }

        if( i < 10 )
        {
            continue;
        }

        for(i=0 ; i < hval ; i++)
        {
            if( p[i].no == 0)
            {
                p[i].no = no;

                printf("\nName : ");
                scanf("%s",p[i].nm);

                break;
            }
        }

        if( i == hval )
        {
            printf("\nOverflow\n");
        }

    }

}

void search()
{
    int no , hval , i=0;

    while(1)
    {
        printf("\nEnter Roll No. to search : ");
        scanf("%d",&no);

        if( no == 0)
        {
            break;
        }

        hval = hash(no);

        if( p[hval].no == no ) // home address
        {
            printf("\nName : ");
            printf("%s",p[hval].nm);

            printf("\nFound at home address\n");

            continue;
        }

        printf("\nSearch on Collision Path\n");
        for(i=hval+1 ;i<10; i++)
        {
            if( p[i].no == no )
            {
                printf("\nName : ");
                printf("%s",p[i].nm);

                printf("\nFound on Collision path\n");

                break;
            }

        }

        if( i < 10)
        {
            continue;
        }

        for(i=0 ; i < hval ; i++)
        {
            if( p[i].no == no )
            {
                printf("\nName : ");
                printf("%s",p[i].nm);

                printf("\nFound\n");

                break;
            }
        }

        if( i == hval)
        {
            printf("\nNot Found\n");
        }

    }

}


int main()
{
    init();

    insert();

    search();
 
    return 0;
}


