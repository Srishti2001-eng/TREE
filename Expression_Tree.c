#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>
typedef struct node
{
    char data;
    struct node*lptr;
    struct node *rptr;
}*pos;

pos stack[30];
int top =-1;
pos newnode(char b)
{
    pos temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=b;
    temp->lptr=NULL;
    temp->rptr=NULL;
    return temp;
}
void push(pos temp)
{
    stack[++top]=temp;
}

pos pop()
{
  pos p;
  p=stack[top--];
  return(p);
}

void inorder(pos t)
{
   if(t!=NULL)
   {
       inorder(t->lptr);
       printf("%s",t->data);
       inorder(t->rptr);
    }
}
void preorder(pos t)
{
    if(t!=NULL)
    {
        printf("%s",t->data);
        preorder(t->lptr);
        inorder(t->rptr  );
    }
}
void postorder(pos t)
{
    if(t!=NULL)
   {
      postorder(t->lptr);
      postorder(t->rptr);
      printf("%s",t->data);
    }
}   

void main()
{
   char a[20];pos temp,t;int j,i;
    printf("\nEnter the postfix expression");
    gets(a);
    for(i=0;a[i]!=NULL;i++)
   {
       if(a[i]=='*' || a[i]=='/' || a[i]=='+' || a[i]=='-')
        {
          temp=newnode(a[i]);
          temp->rptr=pop();
          temp->lptr=pop();
          push(temp);
        }
       else
        {
           temp=newnode(a[i]);
           push(temp);
        }
    }
    inorder(temp);
    printf("\n");
    preorder(temp);
    printf("\n");
    postorder(temp);

}
