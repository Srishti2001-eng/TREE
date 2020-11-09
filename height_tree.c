#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *lptr;
   struct  node *rptr;
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

int height_BST(struct node *root)
{
    int leftheight,rightheight;
    if(root==NULL)
    return 0;
    else
    {
        leftheight=height_BST(root->lptr);
        rightheight=height_BST(root->rptr);
        if(leftheight>rightheight)
        return (leftheight+1);
        else 
        return (rightheight+1);
    }
    
}

struct node *search_elements_parent(struct node*root,int data)
{
    struct node *temp=root;
    if(root==NULL)
    return NULL;
    while(root)
    {
        if(data==root->data)
        return temp;
        else if(data>root->data){
            temp=root;
            root=root->rptr;
        }
        else{
            temp=root;
            root=root->lptr;
        }
    }
    return NULL;
}

struct node *search_elements(struct node*root,int data)
{
    if(root==NULL)
    return NULL;
    while(root)
    {
        if(data==root->data)
        return root;
        else if(data>root->data)
        root=root->rptr;
        else 
        root=root->lptr;
    }
    return NULL;
    
    
}

int main(){
    struct node *root=NULL;
    struct node *ptr;
    int choice;
    int x;
    printf("1. Insert element to BST \n");
    printf("2. Display all elements of BST in PREORDER \n");
    printf("3. calculate height in bst tree \n");
    printf("4.search elements in BST \n");
    printf("5. Quit \n");
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
            printf("height in bst tree is %d\n",height_BST(root));
            printf("\n");
        }
        else if (choice==4)
        {
            printf("Enter the data for which parent is required\n");
            scanf("%d",&x);
            struct node *t=search_elements_parent(root,x);
            if(t!=NULL)
                printf("The parent node data of %d is: %d\n",x,t->data);
            else
            {
                    printf("Not Found\n");
            }
            
        }
        else if (choice==8)
        {
            printf("Enter the data of the node for which height is to be found\n");
            scanf("%d",&x);
            struct node *t=search_elements(root,x);
            if(t!=NULL)
            {
                int h=height_BST(t);
                printf("Height of node is:%d\n",h);

            }
                
            else
            {
                printf("Not Found\n");
            }
        }
         else {
            exit(0);
        }
    }
}
