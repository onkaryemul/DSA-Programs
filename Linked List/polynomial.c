
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int coe;
    int man;
    struct node *next;
}NODE;

typedef struct polynomial
{
    NODE *st;
}POLY;

void init(POLY *t)
{
    t->st=NULL;
}

//function to create NODE
NODE *createNode(int c,int m)
{
    NODE *a;

    a=(NODE *)malloc(sizeof(NODE));

    a->coe=c;
    a->man=m;
    a->next=NULL;

    return a;
}

//function to delete all NODE's
void delAll(POLY *t)
{
    NODE *a=t->st;

    while(t->st != NULL)
    {
        t->st=a->next;
        
        free(a);

        a=t->st;
    }

}

//function to create polynomial expression
void createPoly(POLY *t)
{
    NODE *a, *b;

    int c,m;

    delAll(t);

    while(1)
    {
        printf("\nCoe Man\n");
        scanf("%d %d",&c,&m);

        if(c==0 && m==0)
        {
            break;
        }

        if(m<0)
        {
            printf("\nInvalid Term\n");
            continue;
        }

        if(t->st==NULL)
        {
            t->st=a=createNode(c,m);
        }
        else
        {
            if(m>=b->man)
            {
                printf("\nInvalid Term\n");
                continue;
            }

            a=createNode(c,m);

            b->next=a;
        }
        b=a;
    }

}

//
void display(POLY *t)
{
    NODE *a=t->st;

    if(t->st==NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nPolynomial Expression :\n");

        while(a!=NULL)
        {
            if(a->coe > 0)
            {
               printf("+"); 
            }

            printf("%dX%d",a->coe,a->man);
            a=a->next;
        }
    }
}

//Addition
POLY add(POLY *p,POLY *q)
{
    int co,ma;

    POLY r;

    NODE *a=p->st,*b=q->st;

    NODE *c,*d;

    init(&r);

    while(a && b)
    {
        if(a->man == b->man)
        {
            ma=a->man;

            co=a->coe + b->coe;

            a=a->next;
            b=b->next;
        }
        else
        {
            if(a->man > b->man)
            {
                co=a->coe;
                ma=a->man;
                a=a->next;
            }
            else
            {
                co=b->coe;
                ma=b->man;
                b=b->next;
            }
        }

        if(r.st==NULL)
        {
            r.st=c=createNode(co,ma);
        }
        else
        {
           c=createNode(co,ma);
           d->next=c; 
        }

        d=c;

    }

    while(a != NULL)
    {
        co=a->coe;
        ma=a->man;

        c=createNode(co,ma);

        d->next=c;

        d=c;

        a=a->next;
    }

    while(b != NULL)
    {
        co=b->coe;
        ma=b->man;

        c=createNode(co,ma);

        d->next=c;

        d=c;

        b=b->next;
    }

    return r;
}

//Substraction
POLY sub(POLY *p,POLY *q)
{
    int co,ma;

    POLY r;

    NODE *a=p->st,*b=q->st;

    NODE *c,*d;

    init(&r);

    while(a && b)
    {
        if(a->man == b->man)
        {
            ma=a->man;

            co=a->coe - b->coe;

            a=a->next;
            b=b->next;
        }
        else
        {
            if(a->man > b->man)
            {
                co=a->coe;
                ma=a->man;
                a=a->next;
            }
            else
            {
                co= - b->coe;
                ma=b->man;
                b=b->next;
            }
        }

        if(r.st==NULL)
        {
            r.st=c=createNode(co,ma);
        }
        else
        {
           c=createNode(co,ma);
           d->next=c; 
        }

        d=c;

    }

    while(a != NULL)
    {
        co=a->coe;
        ma=a->man;

        c=createNode(co,ma);

        d->next=c;

        d=c;

        a=a->next;
    }

    while(b != NULL)
    {
        co= - b->coe;
        ma=b->man;

        c=createNode(co,ma);

        d->next=c;

        d=c;

        b=b->next;
    }

    return r;
}

//Multiplication
POLY mul(POLY *p,POLY *q)
{
    POLY r;

    NODE *a=p->st, *b=q->st,*c,*d,*e,*f;

    int co,ma;

    init(&r);

    while(b!=NULL)
    {
        a=p->st;

        while(a!=NULL)
        {
            co=a->coe * b->coe;
            ma=a->man + b->man;
            
            if(r.st==NULL)
            {
                r.st=c=d=createNode(co,ma);
            }
            else
            {
                e=f=r.st;

                while(e!=NULL)
                {
                    if(e->man==ma)
                    {
                        e->coe += co;
                        break;
                    }

                    if(e->man < ma)
                    {
                        c=createNode(co,ma);

                        f->next=c;

                        c->next=e;

                        break;
                    }

                    f=e;
                    e=e->next;
                }

                if(e==NULL)
                {
                    c=createNode(co,ma);

                    f->next=c;

                    d=c;
                }
            }

            a=a->next;
        }

        b=b->next;
    }

    return r;
}


int main()
{
    POLY p,q,r;

    int opt;

    init(&p);
    init(&q);
    init(&r);

    while(1)
    {
        printf("\nPoly List\n1.Create List 1\n2.Create List 2\n3.Display Poly 1\n4.Display Poly 2\n5.Display Poly 3\n6.Add\n7.Sub\n8.Mul\n9.Exit\nOption: ");
        scanf("%d",&opt);

        if(opt>8)
        {
            break;
        }

        switch(opt)
        {
            case 1:
                createPoly(&p);
                break;

            case 2:
                createPoly(&q);
                break;

            case 3:
                display(&p);
                break;

            case 4:
                display(&q);
                break;
            
            case 5:
                display(&r);
                break;

            case 6:
                r=add(&p,&q);
                break;

            case 7:
                r=sub(&p,&q);
                break;

            case 8:
                r=mul(&p,&q);
                break;           
               
        }
    }
    
    return 0;
}