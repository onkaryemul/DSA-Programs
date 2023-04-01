
// DFS Using Adjacency Matrix

#include<stdio.h>
#include<stdlib.h>

int adj[10][10];
int visited[10];
int n,i,j;

// function to create adjacency matrix
void createMatrix()
{
    int r,c;

    while(1)
    {
        printf("\nRow : ");
        scanf("%d",&r);

        printf("\nCol : ");
        scanf("%d",&c);

        if(r==0 && c==0)
        {
            break;
        }

        if(r<1||c<1||r>n||c>n)
        {
            continue;
        }

        adj[r][c] = adj[c][r] = 1;

    }

    return;
}


void dfs(int v)
{ 
    int k;

    printf("%4d",v);
    
    visited[v] = 1;

    for(k=1;k<=n;k++)
    {
        if( visited[k]==0 && adj[v][k]==1 )
        {
            dfs(k);
        }
    }

    return;
}


int main()
{
    printf("\nVertices Count : ");
    scanf("%d",&n);

    createMatrix();

    dfs(1);

    return 0;
}


