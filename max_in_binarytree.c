#include<stdio.h>
#define MIN-65535
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*lptr;
    struct node*rptr;
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

int find_max(node *root)
{
    int root_data,left,right;
    int max=MIN;
    if(root!=NULL)
    {
        root_data=root->data;
        left=find_max(root->lptr);
        right=find_max(root->rptr);
        if(left>right)
        max=left;
        else
        {
            max=right;
        }
        if(root_data>max)
        max=root_data;
    }

    
}

int main()
{
    node *root;
    root = NULL;
    root=create();
    printf("Maximum element is %d\n",find_max(root));
}


