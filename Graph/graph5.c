
// BFS Matrix

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


int q[10],f=0,r=-1;

void bfs(int v)
{
    int k;

    visited[v] = 1;

    printf("%4d",v);

    q[++r] = v;  // insertion

    while(f<=r)
    {
        v = q[f++]; // remove

        for(k=1;k<=n;k++)
        {
            if( adj[v][k]==1 && visited[k]==0 )
            {
                q[++r] = k;

                visited[k] = 1;
                
                printf("%4d",k);
            }

        }
    }

    return;
}


int main()
{
    printf("\nVertices Count : ");
    scanf("%d",&n);

    createMatrix();

    bfs(1);

    return 0;
}




