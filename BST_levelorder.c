#include<stdio.h>
#include<malloc.h>

struct bstnode	{
	struct bstnode * left;
	int data;
	struct bstnode * right;
};

typedef struct bstnode NODE;

NODE *root=NULL, *tptr=NULL, *parent=NULL, *newNode=NULL;

struct qnode{
	NODE *p;
	struct qnode* next;
};
typedef struct qnode QNODE;
QNODE *front=NULL, *rear=NULL, *newQNode, *temp;

void insert(int n)	{
	newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = n;
	newNode->left = newNode->right = NULL;
	if(root == NULL)
		root = newNode;
	else	{
		for(tptr=root; tptr; parent=tptr, tptr=tptr->data>newNode->data?tptr->left:tptr->right);
		if(parent->data>n)
			parent->left = newNode;
		else
			parent->right = newNode;
	}
}

void inorder(NODE *temp)	{
	if(temp){
		inorder(temp->left);
		printf("%d ",temp->data);
		inorder(temp->right);
	}
}

void enqueue(NODE *ptr){
	newQNode = (QNODE*)malloc(sizeof(QNODE));
	newQNode->p = &(*ptr);
	newQNode->next = NULL;
	if(front==NULL && rear==NULL)
		front = rear = newQNode;
	else	{
		rear->next = newQNode;
		rear = newQNode;
	}
}

void dequeue()  {
    while(front) {
        if(front==rear) {
            temp = front;
            front = rear = NULL;
            free(temp);
        }
        else{
            temp = front;
            front = front->next;
            free(temp);
        }
    }
}

void qdisplay()	{
	for(temp=front; temp; temp=temp->next){
		tptr = &(*temp->p);
		printf("%d ",tptr->data);
	}

}

void levelorder()	{
	enqueue(root);
	temp = front;
	while(temp)	{
		tptr = temp->p;
		if(tptr->left!=NULL)
			enqueue(tptr->left);
		if(tptr->right!=NULL)
			enqueue(tptr->right);
		temp = temp->next;
	}

	qdisplay();
	dequeue();
}

int main()	{



	insert(20);
	insert(10);
	insert(30);
	insert(40);
	insert(05);

	inorder(root);
	printf("\n");
	levelorder();
}
