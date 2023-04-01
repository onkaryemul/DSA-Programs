// Mini-Project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct city
{
   int pinCode;
   char cityName[20];
}CT;

typedef struct node
{
   CT data;
   struct node *next;
}NODE;

typedef struct citylist
{
   NODE *ct;
   int cnt;
}CTLIST;

void init(CTLIST *t)
{
    t->ct=NULL;
    t->cnt=0;
}

//function to search by Pincode
NODE *searchByPin(CTLIST *t,int pincode)
{
    NODE *a=t->ct;

    while(a!=NULL)
    {
        if(a->data.pinCode==pincode)
        {
            break;
        }

        a=a->next;
    }

    return a;
}

//function to search by city name
NODE *searchByCityName(CTLIST *t,char *cityName)
{
    NODE *a=t->ct;

    while(a!=NULL)
    {
        if(strcmp(a->data.cityName,cityName)==0)
        {
            break;
        }

        a=a->next;
    }

    return a;
}

//function to add new NODE
void add(CTLIST *t)   //add at Begin operation
{
    NODE *a;

    int pinCode;
    char cityName[20];

    printf("\nPincode : ");
    scanf("%d",&pinCode);

    a=searchByPin(t,pinCode);

    if(a!=NULL)
    {
        printf("\nRecord Exists!");
        return;
    }

    a=(NODE *)malloc(sizeof(NODE));

    a->data.pinCode=pinCode;

    printf("\nCity Name : ");
    scanf("%s",a->data.cityName);

  /*
     do
     {
        printf("\nCity Name : ");
        scanf("%s",cityName);

        if(searchByCityName(t,cityName)==NULL)
        {
            break;
        }
        else
        {
            printf("\nCity Name already Exists");
        }

     }while(1);

     strcpy(a->data.cityName,cityName);
  */

  // Add at Begin Operation

    a->next=t->ct;

    t->ct=a;
    t->cnt++;

    printf("\nInserted Successfully");

    return;
}

//function to modify existing City Record
void mod(CTLIST *t)
{
    NODE *a;

    int pinCode;
    char cityName[20];

    printf("\nEnter City Pincode to modify : ");
    scanf("%d",&pinCode);

    a=searchByPin(t,pinCode);

    if(a==NULL)
    {
        printf("\nRecord Not Exists");
        return;
    }
    
    do
    {
        printf("\nEnter new Pincode for City : ");
        scanf("%d",&pinCode);

        if(searchByPin(t,pinCode)==NULL)
        {
            break;
        }
        else
        {
            printf("\nPincode Already Exists!\n");
        }
    } while (1);
    
    a->data.pinCode=pinCode;

    printf("\nEnter new name of City : ");
    scanf("%s",a->data.cityName);

  /*   
    do
    {
        printf("\nEnter new name Of City : ");
        scanf("%s",cityName);

        if(searchByCityName(t,cityName)==NULL)
        {
            break;
        }
        else
        {
            printf("\nCity Name Already Exists");
        }

    } while (1);

    strcpy(a->data.cityName,cityName);
  */
    
    printf("\nSuccessfully Modified\n");

    return;
}

//function to delete City Record
void del(CTLIST *t)
{
    NODE *a,*b,*c;

    int pinCode;
    char cityName[20];

    printf("\nEnter City Pincode to delete : ");
    scanf("%d",&pinCode);

    a=searchByPin(t,pinCode);

    if(a==NULL)
    {
        printf("\nRecord doesn't Exists!\n");
        return;
    }    

    printf("\nPincode : %d\nCity Name : %s\n",a->data.pinCode,a->data.cityName);

    if(a == t->ct)
    {
        t->ct=a->next;
    }
    else
    {
        b=t->ct;

        while(b->next != a)
        {
            b=b->next;
        }

        c=a->next;

        b->next=c;
    }

    free(a);

    t->cnt--;

    printf("\nSuccessfully Deleted\n");

    return;
}

//function to display
void display(CTLIST *t)
{
    NODE *a=t->ct;

    if(t->ct==NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nCity Data:\n");

        while(a!=NULL)
        {
            printf("\n%4d %-15s",a->data.pinCode,a->data.cityName);

            a=a->next;
        }
    }

    return;
}


int main()
{
    int opt;
    int pinCode;
    char cityName[20];

    CTLIST p;
    init(&p);

    NODE *a;
    
    while(1)
    {
       printf("\nMenu\n1.Add\n2.Modify\n3.Delete\n4.Display All\n5.Search by Pincode\n6.Search by City Name\n7.Exit\nOption : ");
       scanf("%d",&opt);

       if(opt>6)
       {
          break;
       }
       
       switch(opt)
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
               printf("\nEnter City Pincode to search : ");
               scanf("%d",&pinCode);

               a=searchByPin(&p,pinCode);

               if(a==NULL)
               {
                  printf("\nRecord doesn't Exists!\n");
               }
               else
               {
                  printf("\n%4d %-15s",a->data.pinCode,a->data.cityName);
               }
               break;

          case 6:
               printf("\nEnter City Name to search : ");
               scanf("%s",cityName);

               a=searchByCityName(&p,cityName);

               if(a==NULL)
               {
                   printf("\nRecord Not Found!\n");
               }
               else
               {
                   printf("\n%4d %-15s",a->data.pinCode,a->data.cityName);
               }
               break;                       
       }     
    }

    return 0;
}