
// Expression Tree

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
    struct node *left;
    char ch;
    struct node *right;
}NODE;

typedef struct etree
{
    NODE *rt;
}ETREE;

void init(ETREE *t)
{
    t->rt = NULL;
}

NODE *createNode(char a)
{
    NODE *b = (NODE *)malloc(sizeof(NODE));

    b->left = b->right = NULL;

    b->ch = a;

    return b;
}

struct stack
{
    int top;
    NODE *arr[10];
}s;

void sinit()
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

// PreOrder
void preOrder(NODE *a)
{
    if( a != NULL )
    {
        printf("%c",a->ch);

        preOrder(a->left);

        preOrder(a->right);
    }
    else
    {
        return;
    }

}

// InOrder
void inOrder(NODE *a)
{
    if( a != NULL)
    {
        inOrder(a->left);

        printf("%c",a->ch);

        inOrder(a->right);
    }
    else
    {
        return;
    }

}

// PostOrder
void postOrder(NODE *a)
{
    if( a != NULL )
    {
        postOrder(a->left);

        postOrder(a->right);

        printf("%c",a->ch);
    }
    else
    {
        return;
    }

}


int main()
{
    char p[100];

    NODE *x , *y , *z;

    ETREE q;

    int i=0;
    
    init(&q);
    sinit();

    printf("\nEnter Postfix Expression : ");
    scanf("%s",p);

    while( p[i] != '\0' )
    {
        if( isalpha(p[i]) )
        {
            push( createNode(p[i]) );
        }
        else
        {
            z = pop();

            x = pop();

            y = createNode(p[i]);

            y->right = z;
            y->left = x;

            push(y);
        }

        i++;
    }

    q.rt = pop();

    printf("\nPreOrder : ");
    preOrder(q.rt);

    printf("\nInOrder : ");
    inOrder(q.rt);

    printf("\nPostOrder : ");
    postOrder(q.rt);

    return 0;
}