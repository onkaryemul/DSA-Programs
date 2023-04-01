
//  

#include<stdio.h>
#include<stdlib.h>
#define M 10

struct list 
{
    int data;
    char ch;
    struct list *next;
}*k[M];

int visited[M];

struct queue
{
    int arr[M];
    int fr,rr;
}q;

void init()
{
    q.rr = -1; 
    q.fr = 0;
}

int isEmpty()
{
    return (q.rr < q.fr);
}

void insert(int d)
{
    q.rr++;
    q.arr[q.rr]=d;
}

int remque()
{
    return q.arr[q.fr++];
}

struct list *createNode(int d , char ch)
{
    struct list *a;

    a = (struct list *)malloc(sizeof(struct list));

    a->data = d;
    a->ch = ch;
    a->next = NULL;

    return a;
}

void createList()
{
    int i=1,d;
    char ch;

    struct list *p;

    init();

    while(1)
    {
        printf("\nVertex %d : ",i);
        scanf("%d",&d);

        if(d==0)
        {
            break;
        }
        
        printf("\nLabel for Vertex %d : ",i);
        scanf(" %c",&ch);

        k[i] = p = createNode(d,ch);

        printf("\nEnter Adjacent Vertices\n ");
        while(1)
        {
            printf("\nVertex : ");
            scanf("%d",&d);

            if(d==0)
            {
                break;
            }

            printf("\nLabel for Vertex %d : ",d);
            scanf(" %c",&ch);

            p->next = createNode(d,ch);
            
            p = p->next;
        }

        i++;
    }

    return;
}

void bfs(int v)
{
    struct list *p;

    visited[v] = 1;

    p = k[v];

    printf("%c",p->ch);

    insert(v);

    while( ! isEmpty() )
    {
        v = remque();

        p = k[v];

        while(p!=NULL)
        {
            if(visited[p->data]==0)
            {
                insert(p->data);

                printf("%c",p->ch);

                visited[p->data] = 1;
            }

            p = p->next;
        }
    }

    return;
}



int main()
{
    createList();

    bfs(1);

    return 0;
}



