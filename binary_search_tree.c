#include<stdio.h>
#include<malloc.h>

typedef struct node{
    struct node * left;
    int data;
    struct node * right;
}NODE;

NODE *root=NULL, *tptr=NULL, *parent=NULL, *newNode=NULL;

void insert(int n)  {
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = n;
    newNode->left = newNode->right = NULL;
    if(root == NULL)
        root = newNode;
    else    {
        for(tptr=root; tptr; parent=tptr, tptr = tptr->data>newNode->data?tptr->left:tptr->right);
        if(parent->data>newNode->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
}

void display(NODE *tptr)    {
    if(tptr)    {
        display(tptr->left);
        printf("%d ",tptr->data);
        display(tptr->right);
    }
}

int main()  {
    insert(30);
    insert(20);
    insert(40);
    insert(10);
    insert(15);
    insert(35);
    insert(50);

    display(root);
}
