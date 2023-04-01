
//

#include<stdio.h>
#include "adjlist.h"

int visited[M];  // visited array

void dfs(int v)
{
    struct list *p;

    visited[v] = 1;

    p = k[v];

    printf("%4d",p->data);
    while(p!=NULL)
    {
        if(visited[p->data]==0)
        {
            dfs(p->data);
        }
        else
        {
            p = p->next;
        }
    }

    return;
}


int main()
{
    createList();
    
    dfs(1);

    return 0;
}




