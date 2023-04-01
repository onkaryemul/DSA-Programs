// Program to

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rno;
    char nm[15];
    char mno[11];
} STU;

typedef struct node
{
    STU data;
    struct node *next;
} NODE;

typedef struct stulist
{
    NODE *st;
    int cnt;
} STLIST;

void init(STLIST *t)
{
    t->st = NULL;
    t->cnt = 0;
}

//
NODE *searchNo(STLIST *t, int no)
{
    NODE *a = t->st;

    while (a != NULL)
    {
        if (a->data.rno == no)
        {
            break;
        }

        a = a->next;
    }

    return a;
}

// function to search Mobile Number
NODE *searchMN(STLIST *t, char *m)
{
    NODE *a = t->st;

    while (a != NULL)
    {
        if (strcmp(a->data.mno, m) == 0)
        {
            break;
        }

        a = a->next;
    }

    return a;
}

// function to add new NODE
void add(STLIST *t)
{
    NODE *a;

    int no;
    char mno[11];

    printf("\nRoll No: ");
    scanf("%d", &no);

    a = searchNo(t, no);

    if (a != NULL)
    {
        printf("\nRecord Exists");
        return;
    }

    a = (NODE *)malloc(sizeof(NODE));

    a->data.rno = no;

    printf("\nName: ");
    scanf("%s", a->data.nm);

    do
    {
        printf("\nMobile No.: ");
        scanf("%s", mno);

        if (searchMN(t, mno) == NULL)
        {
            break;
        }
        else
        {
            printf("\nMobile No. Exists");
        }
    } while (1);

    strcpy(a->data.mno, mno);

    a->next = t->st;

    t->st = a;

    t->cnt++;

    printf("\nInsertion Successful");
    return;
}

// function to modify existing Student record
void mod(STLIST *t)
{
    NODE *a;

    int no;
    char mno[11];

    printf("\nRoll No: ");
    scanf("%d", &no);

    a = searchNo(t, no);

    if (a == NULL)
    {
        printf("\nRecord Not Exists");
        return;
    }

    a->data.rno = no;

    printf("\nName: ");
    scanf("%s", a->data.nm);

    do
    {
        printf("\nMobile No.: ");
        scanf("%s", mno);

        if (searchMN(t, mno) == NULL)
        {
            break;
        }
        else
        {
            printf("\nMobile No. Exists");
        }
    } while (1);

    strcpy(a->data.mno, mno);

    printf("\nModification Successful");
    return;
}

// funnction to delete Student record
void del(STLIST *t)
{
    NODE *a, *b, *c;

    int no;
    char mno[11];

    printf("\nRoll No: ");
    scanf("%d", &no);

    a = searchNo(t, no);

    if (a == NULL)
    {
        printf("\nRecord Not Exists");
        return;
    }

    printf("\nRoll No.:%d\nName:%s\nMobile No:%s", a->data.rno, a->data.nm, a->data.mno);

    if (a == t->st)
    {
        t->st = a->next;
    }
    else
    {
        b = t->st;

        while (b->next != a)
        {
            b = b->next;
        }

        c = a->next;

        b->next = c;
    }

    free(a);

    t->cnt--;

    printf("Deletion Successful");
    return;
}

// function to display
void display(STLIST *t)
{
    NODE *a = t->st;

    if (t->st == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\nStudent Data:\n");

        while (a != NULL)
        {
            printf("\n%5d %-15s %-10s", a->data.rno, a->data.nm, a->data.mno);

            a = a->next;
        }
    }

    return;
}

//function to STU data to binary file STU2223.dat
void save(STLIST *t)
{
   NODE *a=t->st;
   FILE *f1;

   if(a==NULL)
   {
      return;
   }

   f1=fopen("STU2223.dat","wb");

   while(a!=NULL)
   {
      fwrite(&a->data,sizeof(STU),1,f1);

      a=a->next;
   }

   fclose(f1);
   return;
}

//function to build list from binary file STU2223.dat
void load(STLIST *t)
{
   NODE *a=t->st;
   FILE *f1;
   STU d;

   f1=fopen("STU2223.dat","rb");

   if(f1==NULL)
   {
      printf("\nFile Not Found");
      return;
   }

   while(t->st!=NULL)
   {
       t->st=a->next;

       free(a);

       a=t->st;
   }
   
   t->cnt=0;

   while(fread(&d,sizeof(STU),1,f1))
   {
       a=(NODE *)malloc(sizeof(NODE));

       a->data=d;

       a->next=t->st;

       t->st=a;

       t->cnt++;
   }

   fclose(f1);
   return;
}


int main()
{
    int opt, no;
    char mno[11];

    STLIST p;
    NODE *a;

    init(&p);

    while (1)
    {
        printf("\nMenu\n1.Add\n2.Mod\n3.Del\n4.Display All\n5.Search by No.\n6.Search by Mobile No.\n7.Save\n8.Load\n9.Exit\nOption: ");
        scanf("%d", &opt);

        if (opt > 8)
        {
            break;
        }

        switch (opt)
        {
        case 1:
            add(&p);
            break;

        case 2:
            mod(&p);
            break;

        case 3:
            del(&p);
            break;

        case 4:
            display(&p);
            break;

        case 5:
            printf("\nRoll No.To Search: ");
            scanf("%d", &no);

            a = searchNo(&p, no);

            if (a == NULL)
            {
                printf("\nRecord Not Found");
            }
            else
            {
                printf("\n%5d %-15s %-10s", a->data.rno, a->data.nm, a->data.mno);
            }
            break;

        case 6:
            printf("\nMobile No.To Search: ");
            scanf("%s", mno);

            a = searchMN(&p, mno);

            if (a == NULL)
            {
                printf("\nRecord Not Found");
            }
            else
            {
                printf("\n%5d %-15s %-10s", a->data.rno, a->data.nm, a->data.mno);
            }
            break;

        case 7:
            save(&p);
            break;

        case 8:
            load(&p);
            break;
            
        }
    }
    return 0;
}