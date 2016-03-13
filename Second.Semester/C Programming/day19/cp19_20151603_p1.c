#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node *nextNode;
} node;

void Insert(node **head, int data);
void PrintAll(node *head);

int main(void)
{
	node *head = NULL;
	int A[10] = {3,9,8,2,5,10,7,1,4,6};
	int i;

	node *curNode;
	node *tmpNode;

	for(i = 0;i < 10; ++i)
		Insert(&head,A[i]);

	PrintAll(head);
	
	curNode = head;
	while(curNode != NULL)
	{
		tmpNode = curNode->nextNode;
		free(curNode);
		curNode = tmpNode;
	}

	return 0;
}

void Insert(node **head, int data)
{
	node* newNode = malloc(sizeof(node));
	node* curNode = *head;

	newNode->data = data;
	newNode->nextNode = NULL;

	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
	while(curNode->nextNode != NULL)
		curNode = curNode->nextNode;
	curNode->nextNode = newNode;
	return;
}
void PrintAll(node* head)
{
	node* curNode = head;

	while(curNode != NULL)
	{
		printf("%d ",curNode->data);
		curNode = curNode->nextNode;
	}

	puts("");
	return;
}
