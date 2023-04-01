
#include"mlist.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    SLIST p,q,r;

    int opt;

    init(&p);
    init(&q);
    init(&r);

    while(1)
    {
        printf("\nMenu\n1.Create List 1\n2.Create List 2\n3.Display List 1\n4.Display List 2\n5.Display List 3\n6.Del List 1\n7.Del List 2\n8.Del List 3\n9.Merge List\n10.Union List\n11.Inter List\n12.Exit\nOption: ");
        scanf("%d",&opt);

        if(opt>11)
        {
            break;
        }

        switch(opt)
        {
            case 1:
                 createList(&p);
                 break;

            case 2:
                 createList(&q);
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
                 delAll(&p);
                 break;

            case 7:
                 delAll(&q);
                 break;

            case 8:
                 delAll(&r);
                 break;

            case 9:
                 r=merge(&p,&q);
                 break;

            case 10:
                 r=unionList(&p,&q);
                 break;

            case 11:
                 r=interList(&p,&q);
                 break;
        }
    }
    return 0;
}