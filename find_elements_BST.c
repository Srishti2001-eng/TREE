#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
};

void BST_tree(struct node **st,int value)
{
    struct node *newnode,*parent,*ptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->lptr=NULL;
    newnode->rptr=NULL;

    if(*st==NULL)
    {
        *st=newnode;
    }
    else
    {
        ptr=*st;
        parent=NULL;
        while(ptr!=NULL)
        {
            parent=ptr;
            if(value<ptr->data)
            {
                ptr=ptr->lptr;
            }
            else
            {
                ptr=ptr->rptr;
            }
            
        }
        if(value<parent->data)
        {
            parent->lptr=newnode;
        }
        else
        {
            parent->rptr=newnode;
        }
        
    }
    
}

void preorder_display(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d--",root->data);
        preorder_display(root->lptr);
        preorder_display(root->rptr);
    }
}

struct node *search_elements(struct node*root,int data)
{
    if(root==NULL)
    return NULL;
    if(data<root->data)
    return search_elements(root->lptr,data);
    else if(data>root->data)
    return search_elements(root->rptr,data);
    return root;
}

int main(){
    struct node *root=NULL;
    int choice;
    int x;
    printf("1. Insert element to BST \n");
    printf("2. Display all elements of BST in PREORDER \n");
    printf("3. search elements \n");
    printf("4. Quit \n");
    while(1){
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter data : ");
            int data;
            scanf("%d", &data);
            BST_tree(&root,data);
        }
        else if(choice == 2) {
            preorder_display(root);
            printf("\n");
        }
        else if(choice == 3) {
            printf("Enter the elemnts to be searched \n");
            scanf("%d",&x);
            search_elements(root,x);
            if(x!=root)
            printf("Elements not found");
            else
            {
                printf("elemnts is  found\n");
            }
            
            printf("\n");
        }
         else {
            exit(0);
        }
    }
}

