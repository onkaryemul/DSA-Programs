

/*
    Program to create , traverse , search , delete from Binary
    Search Tree
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;    
}NODE;

typedef struct btree
{
    NODE *rt; // Root NODE
    NODE *prnt; // Parent NODE
    NODE *curr; // Curr NODE
}BST;

int cnt = 0; 

void init(BST *t)
{
    t->rt = NULL;
    t->curr = t->prnt = NULL;
}

NODE *createNode(int d)
{
    NODE *a;

    a = (NODE *)malloc(sizeof(NODE));

    a->data = d;
    a->left = a->right = NULL;

    return a;
}

// Pre-Order
void preOrder(NODE *a)
{
    if(a != NULL)
    {
        printf("%4d",a->data);

        preOrder(a->left);

        preOrder(a->right);
    }
    else
    {
        return;
    }

}

// In-Order
void inOrder(NODE *a)
{
    if(a != NULL)
    {
        inOrder(a->left);

        printf("%4d",a->data);

        inOrder(a->right);
    }
    else
    {
        return;
    }

}

// Post-Order
void postOrder(NODE *a)
{
    if(a != NULL)
    {
        postOrder(a->left);

        postOrder(a->right);

        printf("%4d",a->data);
    }
    else
    {
        return;
    }

}

void createBST(BST *t)
{
    NODE *a,*b;

    int d;

    while(1)
    {
        printf("\nData : ");
        scanf("%d",&d);

        if( d == 0 )
        {
            break;
        }

        if( t->rt == NULL )
        {
            t->rt = createNode(d);
        }
        else
        {
            
            a = t->rt;

            while(1)
            {
                if( d < a->data)
                {
                    if( a->left == NULL)
                    {
                        b = createNode(d);

                        a->left = b;

                        break;
                    }
                    else
                    {
                        a = a->left;
                    }

                }
                else
                {
                    if( a->right == NULL)
                    {
                        b = createNode(d);

                        a->right = b;

                        break;
                    }
                    else
                    {
                        a = a->right;
                    }

                }

            }

        }

    }

}


// function to count leaf nodes
void countLNodes(NODE *a)
{
    if(a != NULL)
    {
        countLNodes(a->left);

        if(a->left==NULL && a->right==NULL)
        {
            cnt++;
        }

        countLNodes(a->right);
    }
    else
    {
        return;
    }

}

// function to display leaf nodes
void displayLNodes(NODE *a)
{
    if(a != NULL)
    {
        displayLNodes(a->left);

        if(a->left==NULL && a->right==NULL)
        {
            printf("%4d",a->data);
        }

        displayLNodes(a->right);
    }
    else
    {
        return;
    }

}


void countNodes(NODE *a)
{
    if(a!=NULL)
    {
        countNodes(a->left);

        cnt++;

        countNodes(a->right);
    }
    else
    {
        return;
    }

}

// function to count total Nodes
int count(NODE *a)
{
    int i;

    if(a==NULL)
    {
        return 0;
    }

    i = 1 + count(a->left) + count(a->right);

    return i;
}

// function to count Leaf Nodes
int countLN(NODE *a)
{
    int i;

    if(a==NULL)
    {
        return 0;
    }

    if(a->left==NULL && a->right==NULL)
    {
        return 1;
    }

    i = countLN(a->left) + countLN(a->right);

    return i;
}

// function to count nodes with outdegree 1
int countD1(NODE *a)
{
    int i;

    if(a == NULL)
    {
        return 0;
    }

    if( a->left==NULL && a->right==NULL )
    {
        return 0;
    }

    if((a->left==NULL || a->right==NULL) )
    {
        printf("%4d",a->data);
        
        i = 1 + countD1(a->left) + countD1(a->right);

        return i;
    }

    i = countD1(a->left) + countD1(a->right);

    return i;
}

// function to count nodes with outdegree 2
int countD2(NODE *a)
{
    int i;

    if(a==NULL)
    {
        return 0;
    }

    if(a->left==NULL && a->right==NULL)
    {
        return 0;
    }

    if(a->left==NULL || a->right==NULL)
    {
        i = countD2(a->left) + countD2(a->right);

        return i;
    }

    i = 1 + countD2(a->left) + countD2(a->right);

    return i;
}

// function to copy the tree
NODE *copyTree(NODE *a)
{
    NODE *p = NULL;

    if(a != NULL)
    {
        p = (NODE *)malloc(sizeof(NODE));
         
        p->data = a->data;

        p->left = copyTree(a->left);

        p->right = copyTree(a->right);
    }

    return p;
}

// function to mirror the tree
NODE *mirrorTree(NODE *a)
{
    NODE *p = NULL;

    if(a != NULL)
    {
        p = a->left;

        a->left = mirrorTree(a->right);

        a->right = mirrorTree(p);
    }

    return a;
}


int main()
{
    BST p,q;

    int opt,d,sv,res;

    init(&p);
    init(&q);

    while(1)
    {
        printf("\nMenu\n1.Create BST\n2.PreOrder\n3.InOrder\n4.PostOrder\n5.Count Leaf Nodes\n6.Count Nodes\n7.Display Leaf Nodes\n8.Total Nodes\n9.Total Leaf Nodes\n10.Count Nodes with Outdegee 1\n11.Count Nodes with Outdegree 2\n12.Copy Tree\n13.Mirror Tree\n14.Exit\nOption : ");
        scanf("%d", &opt);

        if(opt > 13)
        {
            break;
        }

        switch(opt)
        {
            case 1: 
                createBST(&p);
                break;

            case 2:
                printf("\nPre Order : \n");
                preOrder(p.rt);
                break;

            case 3:
                printf("\nIn Order : \n");
                inOrder(p.rt);
                break;

            case 4:
                printf("\nPost Order : \n");
                postOrder(p.rt);
                break;
            
            case 5:
               cnt = 0;
               countLNodes(p.rt);
               printf("\nLeaf Node Count : %d\n",cnt);
               break;

            case 6:
                cnt = 0;
                countNodes(p.rt);
                printf("\nNode Count : %d",cnt);
                break;

            case 7:
                displayLNodes(p.rt);
                break;
               
            case 8:
                printf("\nTotal Nodes : %d", count(p.rt) );
                break;

            case 9:
                printf("\nLeaf Nodes : %d\n", countLN(p.rt) );
                break;
            
            case 10:
                printf("\nCount Nodes with Outdegree 1 : %d\n",countD1(p.rt));
                break;
            
            case 11:
                printf("\nCount Nodes with Outdegree 2 : %d\n",countD2(p.rt));
                break;
            
            case 12:
                init(&q);
                q.rt = copyTree(p.rt);
                printf("\nInorder : ");
                inOrder(q.rt);
                break;

            case 13:
                init(&q);
                q.rt = copyTree(p.rt);
                q.rt = mirrorTree(q.rt);
                printf("\nInOrder : ");
                inOrder(q.rt);
                break;

        }

    }

    return 0;
}



