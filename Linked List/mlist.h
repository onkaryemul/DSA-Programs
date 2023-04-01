//Create a blank file with name mlist.h and write following

#include"slist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to create List
void createList(SLIST *t)
{
    NODE *a,*b;

    int d;

    delAll(t);

    while(1)
    {
        printf("\nData:\n");
        scanf("%d",&d);

        if(d==0)
        {
            break;
        }

        if(t->st==NULL)
        {
            t->st=a=createNode(d);
        }
        else
        {
            if(d<b->data)
            {
                printf("\nInvalid Input");
                continue;
            }

            a=createNode(d);

            b->next=a;
        }

        b=a;

        t->cnt++;
    }
}

//function to merge 2 SLIST
SLIST merge(SLIST *p, SLIST *q)
{
    NODE *a=p->st , *b=q->st;

    NODE *c,*d;

    int data;

    SLIST r;
    init(&r);

    while(a && b)
    {
        if(a->data < b->data)
        {
            data=a->data;
            a=a->next;
        }
        else
        {
            data=b->data;
            b=b->next;           
        }

        c=createNode(data);

        if(r.st==NULL)
        {
            r.st=c;
        }
        else
        {
            d->next=c;
        }

        d=c;

        r.cnt++;
    }

    while(a)
    {
        data=a->data;

        c=createNode(data);

        if(r.st==NULL)
        {
            r.st=c;
        }
        else
        {
            d->next=c;
        }

        d=c;

        r.cnt++;

        a=a->next;
    }

    
    while(b)
    {
        data=b->data;

        c=createNode(data);

        if(r.st==NULL)
        {
            r.st=c;
        }
        else
        {
            d->next=c;
        }

        d=c;

        r.cnt++;

        b=b->next;
    }

    return r;
}


SLIST unionList(SLIST *p,SLIST *q)
{
    SLIST r;

    NODE *a=p->st,*b=q->st,*c,*d;

    int data;
    
    init(&r);

    while(a!=NULL && b!=NULL)
    {
        if(a->data < b->data)
        {
            data=a->data;
            a=a->next;
        }
        else
        {
            data=b->data;
            b=b->next;
        }

        if(r.st==NULL)
        {
            r.st=c=createNode(data);
        }
        else
        {
            if(data==d->data)
            {
                continue;
            }

            c=createNode(data);

            d->next=c;
        }

        d=c;

        r.cnt++;
    }

    while(a != NULL)
    {
        data=a->data;

        a=a->next;

        if(r.st==NULL)
        {
            c=r.st=createNode(data);
        }
        else
        {
            if(data==d->data)
            {
                continue;
            }

            c=createNode(data);

            d->next=c;
        }

        d=c;

        r.cnt++;
    }

     while(b != NULL)
    {
        data=b->data;

        b=b->next;

        if(r.st==NULL)
        {
            c=r.st=createNode(data);
        }
        else
        {
            if(data==d->data)
            {
                continue;
            }

            c=createNode(data);

            d->next=c;
        }

        d=c;

        r.cnt++;
    }

   return r;  
}


SLIST interList(SLIST *p , SLIST *q)
{
    SLIST r;

    NODE *a=p->st,*b=q->st,*c,*d;

    int data;

    init(&r);

    while(a!=NULL && b!=NULL)
    {
        if(a->data < b->data)
        {
            a=a->next;
        }
        else
        {
            data=a->data;

            a=a->next;
            b=b->next;

            if(r.st==NULL)
            {
                r.st=c=createNode(data);
            }
            else
            {
                if(data==d->data)
                {
                    continue;
                }

                c=createNode(data);

                d->next=c;
            }

            d=c;

            r.cnt++;
        }
    }

    return r;
}
