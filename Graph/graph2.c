
// 

#include<stdio.h>
#include "adjlist1.h"

int visited[M];  // visited array

void dfs(int v)
{
    struct list *p;

    visited[v] = 1;

    p = k[v];

    printf("%c",p->ch);
    
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



