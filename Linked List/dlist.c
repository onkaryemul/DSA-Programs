//Double linked List

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}NODE;

typedef struct doublelist
{
    NODE *st; //points to the first node
    NODE *ed; //points to the last node
}DLIST;

void init(DLIST *t)
{
    t->st=NULL;
    t->ed=NULL;
}

NODE *createNode(int d)
{
    NODE *a=(NODE *)malloc(sizeof(NODE));

    a->data=d;
    a->prev=a->next=NULL;

    return a;
}

void addEnd(DLIST *t,int d)
{
    NODE *a=createNode(d);
    NODE *b=t->ed;

    if(t->st==NULL)
    {
        t->st=a;
    }
    else
    {
        b->next=a;
        a->prev=b;
    }

    t->ed=a;

}

void addBeg(DLIST *t,int d)
{
    NODE *a=createNode(d);
    NODE *b=t->st;

    if(t->ed==NULL)
    {
        t->ed=a;
    }
    else
    {
        b->prev=a;
        a->next=b;
    }

    t->st=a;
}

//function to display DLIST begin to end
void displaySE(DLIST *t)
{
    NODE *a=t->st;

    if(t->st==NULL)
    {
        printf("Empty List");
    }
    else
    {
        printf("\nData\n");

        while(a!=NULL)
        {
            printf("%4d",a->data);

            a=a->next;
        }
    }
    
}

//function to display DLIST End to Start
void displayES(DLIST *t)
{
    NODE *a=t->ed;

    if(t->ed==NULL)
    {
        printf("Empty List");
    }
    else
    {
        printf("\nData\n");

        while(a!=NULL)
        {
            printf("%4d",a->data);

            a=a->prev;
        }
    }

}

//function to delete first node from the list
void delFirst(DLIST *t)
{
    NODE *a=t->st ,*b;

    if(t->st==NULL)
    {
        return;
    }

    if(t->st==t->ed)
    {
        t->st=t->ed=NULL;
    }
    else
    {
        b=a->next;
        b->prev=NULL;
        t->st=b;
    }

    free(a);
}

//function to delete last node from the list
void delLast(DLIST *t)
{
   NODE *a=t->ed , *b;

   if(t->st==NULL)
   {
       return;
   }

   if(t->st==t->ed)
   {
      t->st=t->ed=NULL;
   }
   else
   {
      b=a->prev;
      b->next=NULL;
      t->ed=b;
   }

   free(a);
}

//function to delete ith node from list
void deliNode(DLIST *t,int pos)
{
   NODE *a=t->st , *b ,*c;

   int i=1;

   if(t->st==NULL)
   {
      return;
   }

   if(pos<1)
   {
      return;
   }

   while(i<pos && a!=NULL)
   {
      b=a;
      a=a->next;
      i++;
   }

   if(a==NULL)
   {
      printf("\nInvalid Node Position!");
   }
   else
   {
      c=a->next;
      b->next=c;

      if(c!=NULL)
      {
         c->prev=b;
      }
      else
      {
         t->ed=b;
      }

      free(a);
   }

}

//function to insert new node before ith position
void insertB(DLIST *t,int pos,int d)
{
    NODE *a=t->st , *b , *c;

    int i=1;

    if(t->st==NULL)
    {
        return;
    }

    if(pos<1)
    {
        return;
    }

    if(pos==1)
    {
        addBeg(t,d);
    }
    else
    {
        while(i<pos && a!=NULL)
        {
            b=a;
            a=a->next;
            i++;
        }

        if(a==NULL)
        {
            printf("\nInvalid Position!");
        }
        else
        {
            c=createNode(d);

            b->next=c;

            c->prev=b;

            c->next=a;

            a->prev=c;
        }

    }

}

//function to insert new node after ith position
void insertA(DLIST *t,int pos,int d)
{
    NODE *a=t->st , *b , *c;

    int i=1;

    if(t->st==NULL) //Empty List
    {
        return;
    }

    if(pos<1)  
    {
        return;
    }
 
    while(i<=pos && a!=NULL)
    {
        b=a;
        a=a->next;
        i++;
    }

    if(i<=pos) //No such NODE
    {
        return;
    }
    else
    {   
        if(a==NULL)
        {
            addEnd(t,d);
        }
        else
        {
            c=createNode(d);

            b->next=c;

            c->prev=b;

            c->next=a;

            a->prev=c;
        }
    }

}


int main()
{
   DLIST p;

   init(&p);

   int data,opt,pos;

   while(1)
   {
      printf("\nDouble Linked List\n1.Add at End\n2.Add at Beg\n3.Display from Start to End\n4.Display from End to Start\n5.Delete First Node \n6.Delete Last Node\n7.Delete ith Node\n8.Insert Before ith Node Position\n9.Insert After ith Node Position\n10.Exit\nOption : ");
      scanf("%d",&opt);

      if(opt>9)
      {
         break;
      }

      switch(opt)
      {
         case 1:
             printf("\nEnter data to be inserted at end : ");
             scanf("%d",&data);
             addEnd(&p,data);
             break;

         case 2:
             printf("\nEnter data to be inserted at begin : ");
             scanf("%d",&data);
             addBeg(&p,data);
             break;

         case 3:
             displaySE(&p);
             break;

         case 4:
             displayES(&p);
             break;

         case 5:
             delFirst(&p);
             break;

         case 6:
             delLast(&p);
             break;

         case 7:
             printf("\nEnter position of the node to be deleted : ");
             scanf("%d",&pos);
             deliNode(&p,pos);
             break;

         case 8:
             printf("\nEnter position before which node is to be added : ");
             scanf("%d",&pos);
             printf("\nEnter data to be inserted : ");
             scanf("%d",&data);
             insertB(&p,pos,data);
             break;

         case 9:
             printf("\nEnter position after which node is to be added : ");
             scanf("%d",&pos);
             printf("\nEnter data to be inserted : ");
             scanf("%d",&data);
             insertA(&p,pos,data);
             break;
             
      }
   }

   return 0;
}



