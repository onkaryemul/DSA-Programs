// Create a new header file slist.h and define data type and approprite function definitions to manupulate the list

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

int main()
{
    int opt, d, res, sv, rv, pos;
    SLIST p;

    init(&p);

    while (1)
    {
        printf("\nSingle Linked List\n1.Add End\n2.Add Beg\n3.Display\n4.Odd display\n5.Even display\n6.Odd Nodes\n7.Even Nodes\n8.Data Sum\n9.Delete First Node\n10.Delete Last Node\n11.Delete All Nodes\n12.Delete ith Node\n13.Search\n14.Find & Replace\n15.Reverse List\n16.Reverse Display\n17.Exit\nOption: ");
        scanf("%d", &opt);

        if (opt > 16)
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
        }
    }

    return 0;
}
