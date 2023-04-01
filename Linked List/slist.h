// Create a new header file slist.h and define data type and approprite function definitions to manupulate the list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

typedef struct slist
{
    NODE *st;
    int cnt;
} SLIST;

// function to initialize SLIST
void init(SLIST *t)
{
    t->st = NULL;
    t->cnt = 0;
}

// function to create new NODE
NODE *createNode(int d)
{
    NODE *a;
    a = (NODE *)malloc(sizeof(NODE));
    a->data = d;
    a->next = NULL;

    return a;
}

// function to retrieve last NODE
NODE *getLastNode(NODE *a)
{
    while (a->next != NULL)
    {
        a = a->next;
    }

    return a;
}

// function to add new NODE at End
void addEnd(SLIST *t, int d)
{
    NODE *a, *b;

    a = createNode(d);

    if (t->st == NULL)
    {
        t->st = a;
    }
    else
    {
        b = getLastNode(t->st);
        b->next = a;
    }

    t->cnt++;
}

// function to add new NODE at Begin
void addBeg(SLIST *t, int d)
{
    NODE *a;

    a = createNode(d);

    a->next = t->st;

    t->st = a;

    t->cnt++;
}

// function to display list data
void display(SLIST *t)
{
    NODE *a = t->st;

    if (t->st == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nData:\n");

        while (a != NULL)
        {
            printf("%4d", a->data);
            a = a->next;
        }
    }
}

// function to compute data sum
int sum(SLIST *t)
{
    NODE *a = t->st;

    int tot = 0;

    while (a != NULL)
    {
        tot += a->data;
        a = a->next;
    }

    return tot;
}

// function to count odd data NODEs
int ocount(SLIST *t)
{
    NODE *a = t->st;
    int tot = 0;

    while (a != NULL)
    {
        tot += (a->data % 2);
        a = a->next;
    }

    return tot;
}

// function to count Even data Nodes
int ecount(SLIST *t)
{
    NODE *a = t->st;
    int tot = 0;

    while (a != NULL)
    {
        tot += (a->data % 2 == 0);
        a = a->next;
    }

    return tot;
}

/*
    int ecount(SLIST *t)
    {
        return t->cnt-ocount(t);
    }

*/

// function to display odd data NODEs
void odisplay(SLIST *t)
{
    NODE *a = t->st;

    if (t->st == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nData:\n");

        while (a != NULL)
        {
            if (a->data % 2 == 1)
            {
                printf("%4d", a->data);
            }

            a = a->next;
        }
    }
}

// function to display even data NODEs
void edisplay(SLIST *t)
{
    NODE *a = t->st;

    if (t->st == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nData:\n");

        while (a != NULL)
        {
            if (a->data % 2 == 0)
            {
                printf("%4d", a->data);
            }

            a = a->next;
        }
    }
}

// function to delete first NODE from SLIST
void delFirst(SLIST *t)
{
    NODE *a = t->st;

    if (t->st == NULL)
    {
        return;
    }

    t->st = a->next;

    free(a);

    t->cnt--;
}

/*
   //call from main
      case 9:
             delFirst(&p);
             break;
*/

// function to delete Last NODE from SLIST
void delLast(SLIST *t)
{
    NODE *a = t->st, *b;

    if (t->st == NULL)
    {
        return;
    }

    if (a->next == NULL)
    {
        t->st = a->next;
    }
    else
    {
        while (a->next != NULL)
        {
            b = a;
            a = a->next;
        }
        b->next = NULL;
    }

    free(a);

    t->cnt--;
}

// function to delete All NODEs from list

/*
   void delAll(SLIST *t)
   {
      while(t->st!=NULL)
      {
        delFirst(t);
      }
   }

*/

void delAll(SLIST *t)
{
    NODE *a = t->st;

    while (t->st != NULL)
    {
        t->st = a->next;

        free(a);

        a = t->st;
    }

    t->cnt = 0;
}

// function to delete ith NODE from SLIST  //BY POSITION
void deliNode(SLIST *t, int pos)
{
    NODE *a, *b, *c;

    int i = 1;

    if (pos == 1)
    {
        delFirst(t);
    }
    else
    {
        if (pos == t->cnt)
        {
            delLast(t);
        }
        else
        {
            a = t->st;

            while (i < pos)
            {
                b = a;
                a = a->next;
                i++;
            }

            c = a->next;

            b->next = c;

            free(a);

            t->cnt--;
        }
    }
}

// function to implement Sequential Search  // return 1 if found , otherwise 0
// function to search data from SLIST
int search(SLIST *t, int sv)
{
    NODE *a = t->st;

    while (a != NULL)
    {
        if (a->data == sv)
        {
            break;
        }

        a = a->next;
    }

    if (a != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// function to implement find and replace
int findRepl(SLIST *t, int sv, int rv)
{
    NODE *a = t->st;
    int flg = 0;

    while (a != NULL)
    {
        if (a->data == sv)
        {
            a->data = rv;
            flg = 1;
        }

        a = a->next;
    }

    return flg;
}

// function to reverse the list
void reverse(SLIST *t)
{
    NODE *a = t->st, *b, *c = NULL;

    while (a != NULL)
    {
        b = a->next;
        a->next = c;
        c = a;
        a = b;
    }

    t->st = c;
}

// function to display list in reverse order
void rdisplay(NODE *a)
{
    if (a == NULL)
    {
        return;
    }

    rdisplay(a->next);

    printf("%4d", a->data);
}

// find out maximum data from the list
int findMax(SLIST *t)
{
    NODE *a = t->st;
    int max = a->data;

    for (a = a->next; a != NULL; a = a->next)
    {
        if (a->data > max)
        {
            max = a->data;
        }
    }

    return max;
}

// find out minimum data from the list
int findMin(SLIST *t)
{
    NODE *a = t->st;
    int min = a->data;

    for (a = a->next; a != NULL; a = a->next)
    {
        if (a->data < min)
        {
            min = a->data;
        }
    }

    return min;
}

//
void insertA2(SLIST *t)
{
    NODE *a=t->st,*b,*c;
    
    int d;

    while(a!=NULL)
    {
        if(a->next==NULL)
        {
            break;
        }

        b=a->next;

        d=a->data+b->data;

        c=createNode(d);

        c->next=b->next;

        b->next=c;

        a=c->next;

        t->cnt++;
    }
}

//
void insertB2(SLIST *t)
{
    NODE *a=t->st,*b,*c,*tmp;

    int d;

    while(a!=NULL)
    {
        if(a->next==NULL)
        {
            break;
        }

        b=a->next;

        d=a->data+b->data;

        c=createNode(d);

        if(t->st==a)
        {
            t->st=c;
        }
        else
        {
            tmp->next=c;
        }

        c->next=a;

        tmp=b;

        a=b->next;

        t->cnt++;
    }
}

//
void copyList(SLIST *d,SLIST *s)
{
    NODE *a=s->st,*b,*c;

    while(a!=NULL)
    {
        c=createNode(a->data);

        if(d->st==NULL)
        {
            d->st=c;
        }
        else
        {
            b->next=c;
        }

        b=c;

        d->cnt++;
        
        a=a->next;
    }
}

//function to append the list
void appendList(SLIST *d,SLIST *s)
{
    NODE *a=s->st; //source
    NODE *b=d->st; //destination
    NODE *c;

    if(d->st==NULL)
    {
        copyList(d,s);
    }
    else
    {
        b=getLastNode(d);

        while(a!=NULL)
        {
            b->next=createNode(a->data);
            b=b->next;
            a=a->next;
            d->cnt++;
        }
    }

}

//function to check list data is in ascendiing order 
//Return 1 if ordered ,otherwise return 0 if unordered
int isOrdered(SLIST *t)
{
    NODE *a=t->st;
    int min=a->data;

    for(a=a->next;a!=NULL;a=a->next)
    {
        if(a->data>=min)
        {
            min=a->data;
        }
        else
        {
            break;
        }
    }

    if(a!=NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

//function to sort the list using selection sort method
void sort(SLIST *t)
{
    NODE *a=t->st,*b,*c;
    int tmp;

    while(a->next!=NULL)
    {
        c=a;

        for(b=a->next;b!=NULL;b=b->next)
        {
            if(b->data<c->data)
            {
                c=b;
            }
        }

        if(a!=c)
        {
            tmp=a->data;
            a->data=c->data;
            c->data=tmp;
        }
        
        a=a->next;
    }
    
}

//function to copy array data to list
//function to build list from array
void arrayToList(SLIST *t,int *ptr,int n)
{
    NODE *a,*b;

    int i=0;

    if(t->st!=NULL)
    {
        delAll(t);
    }

    for(i=0;i<n;i++)
    {
        a=createNode(ptr[i]);

        if(t->st==NULL)
        {
            t->st=a;
        }
        else
        {
            b->next=a;
        }

        b=a;

        t->cnt++;
    }

}

//function to copy SLIST data to an array
int *listToArray(SLIST *t)
{
    int i=0;

    NODE *a=t->st;

    int *ptr=(int *)malloc(t->cnt*sizeof(int));

    while(a!=NULL)
    {
        ptr[i++]=a->data;
        a=a->next;
    }

    return ptr;
}

//functiom to copy SLIST data to the file number.txt
void listToFile(SLIST *t)
{
    int data;
    NODE *a=t->st;

    FILE *f1=fopen("number.txt","w");

    while(a!=NULL)
    {
        data=a->data;

        putw(data,f1);

        a=a->next;
    }

    fclose(f1);
}

//function to build SLIST from from the file number.txt
void fileToList(SLIST *t)
{
    int data;
    NODE *a=t->st,*b;
    FILE *f1=fopen("number.txt","r");

    if(f1==NULL)
    {
        printf("\nFile Not Found");
        return;
    }

    if(t->st!=NULL)
    {
        delAll(t);
    }

    while(1)
    {
        data=getw(f1);

        if(feof(f1))
        {
            break;
        }

        a=createNode(data);

        if(t->st==NULL)
        {
            t->st=a;
        }
        else
        {
            b->next=a;
        }

        b=a;
        t->cnt++;
    }

    fclose(f1);
}

//function to insert NODE before position
void insertB(SLIST *t,int pos,int d)
{
    NODE *a=t->st,*b,*c;
    int i=1;

    if(pos==1)
    {
        addBeg(t,d);
    }
    else
    {
        while(i<pos)
        {
            b=a;
            a=a->next;
            i++;
        }

        c=createNode(d);

        b->next=c;

        c->next=a;

        t->cnt++;
    }

}

//function to insert NODE after position
void insertA(SLIST *t,int pos,int d)
{
    NODE *a=t->st,*b,*c;
    int i=1;

    if(pos==t->cnt)
    {
        addEnd(t,d);
    }
    else
    {
        while(i<=pos)
        {
            b=a;
            a=a->next;
            i++;
        }

        c=createNode(d);

        b->next=c;

        c->next=a;

        t->cnt++;
    }

}

//function to copy LIST data in reverse order
SLIST revCopy(SLIST *t)
{
    SLIST b;
    
    NODE *a=t->st;

    init(&b);

    while(a!=NULL)
    {
        addBeg(&b,a->data);
        a=a->next;
    }

    return b;
}


