//Infix to Postfix

#include<stdio.h>
#include<ctype.h> 
#include"CSTK.h"

int preced(char stktop,char opr)
{
    if(stktop !='(' && opr==')')
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


int main()
{   
    CSTK p;

    char istr[50],pstr[50],ch;

    int i=0,j=0;

    init(&p);

    printf("\nEnter Infix Expression : ");
    scanf("%s",istr);

    while(istr[i] != '\0')
    {
        if(isalpha(istr[i]))
        {
            pstr[j++]=istr[i];
        }
        else
        {
            while( !isEmpty(&p) && preced(p.arr[p.top],istr[i]))
            {
                ch=pop(&p);
                pstr[j++]=ch;
            }

            if(isEmpty(&p) || istr[i]!=')')
            {
                push(&p,istr[i]);
            }
            else
            {
                ch=pop(&p);
            }

        }

        i++;
    }

    while(!isEmpty(&p))
    {
        ch=pop(&p);

        pstr[j++]=ch;
    }

    pstr[j]='\0';

    puts(pstr);

    return 0;
}


