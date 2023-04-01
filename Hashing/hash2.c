
// Linked List Resolution

#include<stdio.h>
#include<stdlib.h>

struct student
{
    int no;
    char nm[15];
    struct student *next;
}p[10];

void init()
{
    int i=0;

    while( i < 10)
    {
        p[i].no = 0;

        p[i].next = NULL;

        i++;
    }

}

struct student *createNode(int n)
{
    struct student *a;

    a = (struct student *)malloc(sizeof(struct student));

    a->no = n;

    printf("\nEnter Name : ");
    scanf("%s",a->nm);

    a->next = NULL;

    return a;
}

int hash(int no)
{
    return ( no%10 );
}

void insert()
{
    int no,hval;

    struct student *a,*b;

    while(1)
    {
        printf("\nEnter Roll No. : ");
        scanf("%d",&no);

        if( no == 0)
        {
            break;
        }

        hval = hash(no);

        if( p[hval].no == 0)
        {
            p[hval].no = no;

            printf("\nEnter Name : ");
            scanf("%s",p[hval].nm);

            printf("\nInserted in Prime area\n");
        }
        else
        {
            a = createNode(no);

            b = p[hval].next;

            a->next = b;

            p[hval].next = a;

            printf("\nInserted in a Overflow area\n");
        }

    }

}

void search()
{
    int no,hval;

    struct student *a;

    while(1)
    {
        printf("\nEnter Roll No. to search : ");
        scanf("%d",&no);

        hval = hash(no);

        if( p[hval].no == no )
        {
            printf("\nName : %s ",p[hval].nm);
            printf("\nRecord Found in Prime area\n");
        }
        else
        {
            a = p[hval].next;

            while(a != NULL)
            {
                if(a->no == no)
                {
                    break;
                }

                a = a->next;
            }

            if( a == NULL)
            {
                printf("\nRecord Not Found\n");
            }
            else
            {
                printf("\nName : %s\nRecord Found in Overflow area\n",a->nm);
            }

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


