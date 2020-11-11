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

struct node *min_elements(struct node *root)
{
     if(root==NULL)
     return NULL;
     else if(root->lptr==NULL)
     return root;
     else
     {
         return min_elements(root->lptr);
     }
     
}

struct node *max_elements(struct node *root)
{
    if(root==NULL)
    return NULL;
    else if(root->rptr==NULL)
    return NULL;
    else
    {
        return max_elements(root->rptr);
    }
    
}

struct node *delete_elements(struct node *root,int data)
{
    struct node *temp;
    if(root==NULL)
    printf("Elements is not there in tree\n");
    else if(data < root->data)
    root->lptr=delete_elements(root->lptr,data);
    else if(data > root->data)
    root->rptr=delete_elements(root->rptr,data);
    else
    {
        //case-1: no child
        if(root->lptr==NULL && root->rptr==NULL)
        { 
            free(root);
            root=NULL;
            return root;
        }
        //case-2: One child
        else if (root->lptr==NULL)
        {
            struct node *temp=root;
            root=root->rptr;
            free (temp);
            return root;
        }

        else if (root->rptr==NULL)
        {
            struct node *temp=root;
            root=root->lptr;
            free(temp);
            return root;
        }
        else
        {
            struct node *temp=min_elements(root->rptr);
            root->data=temp->data;
            root->rptr=delete_elements(root->rptr,temp->data);
        }
        
    }

}
int main()
{
    struct node *root=NULL;
    struct node *ptr;
    int choice;
    int x;
    int k;
    printf("1. Insert element to BST \n");
    printf("2. Display all elements of BST in PREORDER \n");
    printf("3. min elements in bst tree \n");
    printf("4. max elements in bst tree\n");
    printf("5. delete node in BST tree\n");
    printf("6. Quit \n");
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
            ptr=min_elements(root);
            if(ptr!=NULL)
            printf("minimum elements in bst tree is %d\n",ptr->data);
            printf("\n");
        }
        else if(choice == 4) {
            ptr=max_elements(root);
            if(ptr!=NULL)
            printf("maximum elements in bst tree is %d \n",ptr->data);
            printf("\n");
        }
        else if (choice==5)
        {
            printf("Enter the number to be deleted\n");
            scanf("%d",&k);
            root=delete_elements(root,k);
        }
        
         else {
            exit(0);
        }
    }
}
