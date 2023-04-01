
// Non-Recursive Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    int data,flg;
    struct node *right;
}NODE;

NODE *rt = NULL;

NODE *createNode(int d)
{
    NODE *a = (NODE *)malloc(sizeof(NODE));

    a->data = d;
    a->flg = 0;
    a->left = a->right = NULL;

    return a;
}

struct Stack
{
    int top;
    NODE *arr[10];
}s;

void init()
{
    s.top = -1;
}

void push(NODE *a)
{
    s.top++;
    s.arr[s.top] = a;
}

NODE *pop()
{
    return s.arr[s.top--];
}

int isEmpty()
{
    return (s.top == -1);
}

void createTree()
{
    NODE *a;

    int d;

    while(1)
    {
        printf("\nData : ");
        scanf("%d",&d);

        if(d == 0)
        {
            break;
        }

        if(rt == NULL)
        {
            rt = createNode(d);
        }
        else
        {
            a = rt;

            while(1)
            {
                if(d < a->data)
                {
                    if(a->left == NULL )
                    {
                        a->left = createNode(d);
                        break;
                    }
                    else
                    {
                        a = a->left;
                    }
                }
                else
                {
                    if(a->right == NULL)
                    {
                        a->right = createNode(d);
                        break;
                    }
                    else
                    {
                        a = a->right;
                    }
                }

            } // inner while loop

        }

    } // Outer while loop
    
    return;
}

void inOrder(NODE *a)
{
    init();
    
    do
    {
        while(a != NULL)
        {
            push(a);
            a = a->left;
        }

        if( !isEmpty() )
        {
            a = pop();
            printf("%4d",a->data);
            a = a->right;
        }

    } while( a!=NULL || !isEmpty() );
    
    return;
}

void preOrder(NODE *a)
{
    init();

    while( a!=NULL || !isEmpty() )
    {
        printf("%4d",a->data);

        if(a->right != NULL)
        {
            push(a->right);
        }

        a = a->left;

        if( a==NULL && !isEmpty() )
        {
            a = pop();
        }

    }

    return;
}

void postOrder(NODE *a)
{
    init();

    do
    {
        while( a!=NULL && a->flg==0 )
        {
            push(a);

            a = a->left;
        }

        a = pop();

        if( a->flg == 1 )
        {
            printf("%4d",a->data);
        }
        else
        {
            a->flg = 1;

            push(a);

            a = a->right;
        }

    } while ( !isEmpty() );
    
    return;
}



int main()
{
    int opt;

    while(1)
    {
        printf("\nBinary Search Tree Non-Recursive Traversal\nMenu\n1.Create Tree\n2.PreOrder\n3.InOrder\n4.PosOrder\n5.Exit\nOption : ");
        scanf("%d",&opt);

        if( opt > 4 )
        {
            break;
        }

        switch(opt)
        {
            case 1:
                createTree();
                break;

            case 2:
                printf("\nPreOrder : ");
                preOrder(rt);
                break;

            case 3:
                printf("\nInOrder : ");
                inOrder(rt);
                break;

            case 4:
                printf("\nPostOrder : ");
                postOrder(rt);
                break;

        } 

    }

    return 0;
}


