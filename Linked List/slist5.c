// Create a new header file slist.h and define data type and approprite function definitions to manupulate the list

#include <stdio.h>
#include <stdlib.h>
#include"slist.h"

int main()
{
    int opt, d, res, sv, rv, pos,n,i;
    int *ptr;
    SLIST p,q;

    init(&p);
    init(&q);

    while (1)
    {
        printf("\nSingle Linked List\n1.Add End\n2.Add Beg\n3.Display\n4.Odd display\n5.Even display\n6.Odd Nodes\n7.Even Nodes\n8.Data Sum\n9.Delete First Node\n10.Delete Last Node\n11.Delete All Nodes\n12.Delete ith Node\n13.Search\n14.Find & Replace\n15.Reverse List\n16.Reverse Display\n17.Find Maximum\n18.Find Minimum\n19.InsertA2\n20.InsertB2\n21.Copy List\n22.Append List\n23.IsOrdered\n24.Sort\n25.Array to List\n26.List to Array\n27.List to file\n28.File to List\n29.Insert Before Node Position\n30.Insert After Node Position\n31.Reverse Copy and display\n32.Exit\nOption: ");
        scanf("%d", &opt);

        if (opt > 31)
        {
            break;
        }

        switch (opt)
        {
        case 1:
            printf("\nData at End: ");
            scanf("%d", &d);
            addEnd(&p, d);
            break;

        case 2:
            printf("\nData at Begin: ");
            scanf("%d", &d);
            addBeg(&p, d);
            break;

        case 3:
            display(&p);
            break;

        case 4:
            odisplay(&p);
            break;

        case 5:
            edisplay(&p);
            break;

        case 6:
            printf("\nOdd Nodes: %d", ocount(&p));
            break;

        case 7:
            printf("\nEven Nodes: %d", ecount(&p));
            break;

        case 8:
            printf("\nSum: %d", sum(&p));
            break;

        case 9:
            if (p.st == NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                delFirst(&p);
            }
            break;

        case 10:
            if (p.st == NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                delLast(&p);
            }
            break;

        case 11:
            delAll(&p);
            break;

        case 12:
            if (p.st == NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                printf("\nEnter Node Position: ");
                scanf("%d", &pos);

                if ((pos < 1) || (pos > p.cnt))
                {
                    printf("\nInvalid NODE Position");
                }
                else
                {
                    deliNode(&p, pos);
                }
            }
            break;

        case 13:
            if (p.st == NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                printf("\nEnter Search Value: ");
                scanf("%d", &sv);

                res = search(&p, sv);

                if (res == 1)
                {
                    printf("\nFound");
                }
                else
                {
                    printf("\nNot Found");
                }
            }
            break;

        case 14:
            if (p.st == NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                printf("\nEnter Search Value: ");
                scanf("%d", &sv);

                printf("\nEnter Replace Value: ");
                scanf("%d", &rv);

                if (findRepl(&p, sv, rv) == 0)
                {
                    printf("\nNo find repl");
                }
                else
                {
                    printf("\nFind & Repl Success");
                }
            }
            break;

        case 15:
            if (p.st == NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                reverse(&p);
            }
            break;

        case 16:
            if (p.st == NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                rdisplay(p.st);
            }
            break;

        case 17:
            if (p.st == NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                printf("\nMax Data: %d", findMax(&p));
            }
            break;

        case 18:
            if (p.st == NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                printf("\nMin Data: %d", findMin(&p));
            }
            break;

        case 19:
            if(p.st==NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                insertA2(&p);
            }
            break;

        case 20:
            if(p.st==NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                insertB2(&p);
            }
            break;

        case 21:
            if(p.st==NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                delAll(&q);
                copyList(&q,&p);
                display(&q);
            }
            break;

        case 22:
            appendList(&q,&p);
            display(&q);
            delAll(&q);
            break;

        case 23:
            if(p.st==NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                if(isOrdered(&p)==0)
                {
                    printf("\nNot ");
                }

                printf("Ordered");
            }
            break;

        case 24:
            if(p.st==NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                sort(&p);
            }
            break;

        case 25:
            printf("\nEnter information count: ");
            scanf("%d",&n);

            ptr=(int *)malloc(n*sizeof(int)); 

            printf("\nArray Data\n");
            for(i=0;i<n;i++)
            {
                scanf("%d",(ptr+i));
            }

            arrayToList(&p,ptr,n);
            break;

        case 26:
            if(p.st==NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                ptr=listToArray(&p);
                
                printf("\nData:\n");
                for(i=0;i<p.cnt;i++)
                {
                    printf("%4d",ptr[i]);
                }

                free(ptr);
            }
            break;

        case 27:
            if(p.st==NULL)
            {
                printf("\nEmpty List");
            }
            else
            {
                listToFile(&p);
            }
            break;

        case 28:
            fileToList(&p);
            break;

        case 29:
            printf("\nEnter Before Node Position: ");
            scanf("%d",&pos);

            printf("\nData: ");
            scanf("%d",&d);
            
            if(pos<1||pos>p.cnt)
            {
                printf("\nInvalid");
            }
            else
            {
                insertB(&p,pos,d);
            }
            break;

        case 30:
            printf("\nEnter After Node Position: ");
            scanf("%d",&pos);

            printf("\nData: ");
            scanf("%d",&d);
            
            if(pos<1||pos>p.cnt)
            {
                printf("\nInvalid");
            }
            else
            {
                insertA(&p,pos,d);
            }
            break;

        case 31:
            if(p.st==NULL)
            {
                printf("\nEmpty");
            }
            else
            {
                if(q.st!=NULL)
                {
                    delAll(&q);
                }
                
                q=revCopy(&p);
                display(&q);
            
            }
            break;

        }

    }

    return 0;
}
