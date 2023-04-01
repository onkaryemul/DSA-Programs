
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

// Program to implement searching in BST
// function to search value from the BST
int search(BST *t , int sv)
{
    NODE *a=t->rt;
    
    int flg = 0;

    while( a != NULL )
    {
        if( a->data == sv )
        {
            t->curr = a;

            flg = 1;

            break;
        }

        if( sv < a->data)
        {
            t->prnt = a;

            a = a->left;
        }
        else
        {
            t->prnt = a;

            a = a->right;
        }

    }
    
    return flg;
}

// function to delete a node from Binary Search Tree
void delNode(BST *t , int val)
{
    NODE *p , *q , *r , *s ;

    if( search(t,val) == 0 )
    {
        printf("\nNot Found\n");
        return;
    }

    p = t->prnt;

    q = t->curr;

    // leaf Node
    if( q->left==NULL && q->right==NULL )
    {
        if( p->left == q )
        {
            p->left = NULL;
        }
        else
        {
            p->right = NULL;
        }

        free(q);
         
        printf("\nLeaf Node deletion is successful\n");

        return;
    }

    // Delete a node with two child
    if( q->left!=NULL && q->right!=NULL )
    {
        if( p->right == q )
        {
            r = q->left;

            while( r!=NULL )
            {
                s = r;

                r = r->right;
            }

            s->right = q->right;

            p->right = q->left;
        }
        else
        {
            r = q->right;

            while( r!=NULL )
            {
                s = r;

                r = r->left;
            }

            s->left = q->left;

            p->left = q->right;
        }

        free(q);

        printf("\nDeletion of a node with two child is successful\n");

        return;
    }

    //
    if(p->right == q)
    {
        if(q->left == NULL)
        {
            p->right = q->right;
        }
        else
        {
            p->right = q->left;
        }

        free(q);

        return;
    }

    //
    if(p->left == q)
    {
        if(q->right == NULL)
        {
            p->left = q->left;
        }
        else
        {
            p->left = q->right;
        }

        free(q);

        return;
    }

} 



int main()
{
    BST p;

    int opt,d,sv,res;

    init(&p);

    while(1)
    {
        printf("\nMenu\n1.Create BST\n2.PreOrder\n3.InOrder\n4.PostOrder\n5.Search\n6.Delete Node\n7.Exit\nOption : ");
        scanf("%d", &opt);

        if(opt > 6)
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
                printf("\nEnter search value : ");
                scanf("%d",&sv);
                res = search(&p,sv);
                if( res == 1 )
                {
                    printf("\nFound\n");
                }
                else
                {
                    printf("\nNot Found\n");
                }
                break;

            case 6:
                printf("\nEnter data to delete : ");
                scanf("%d",&d);
                delNode(&p,d);
                break;
               
        }

    }

    return 0;
}



