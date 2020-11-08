#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
}node;

node *create()
{
    int x;
    node *newnode;
    newnode =(node*)malloc(sizeof(node));
    printf("Enter data:\n");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    newnode->data=x;
    printf("Enter left child of %d ",x);
    newnode->lptr=create();
    printf("Enter right child of %d ",x);
    newnode->rptr=create();
    return newnode;
}
void preorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d",root->data);
    preorder(root->lptr);
    preorder(root->rptr);
}

void inorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->lptr);
    printf("%d",root->data);
    inorder(root->rptr);
}

void postorder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->rptr);
    postorder(root->lptr);
    printf("%d",root->data);
    
}

void main()
{
    node *root;
    root = NULL;
    root=create();
    printf("Preorder is:");
    preorder(root);
    printf("Inorder is");
    inorder(root);
    printf("Postorder is");
    postorder(root);
}