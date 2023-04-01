// Create a new header file slist.h and define data type and approprite function definitions to manupulate the list

#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

int main()
{
       int opt, d, res;
       SLIST p;

       init(&p);

       while (1)
       {
              printf("\nSingle Linked List\n1.Add End\n2.Add Beg\n3.Display\n4.Odd display\n5.Even display\n6.Odd Nodes\n7.Even Nodes\n8.Data Sum\n9.Exit\nOption: ");
              scanf("%d", &opt);

              if (opt > 8)
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
              }
       }

       return 0;
}