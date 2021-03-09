#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
	int data;
	struct _node *nextNode;
} node;

void Insert(node **head, int data);
void PrintAll(node *head);

int main(void)
{
	int A[10] = { 3,9,8,2,5,10,7,1,4,6 };
	node *head = NULL;
	int i;

	for(i = 0;i < 10; ++i)
		Insert(&head,A[i]);
	
	PrintAll(head);

	return 0;
}
void Insert(node **head, int data)
{
	node *newNode = malloc(sizeof(node));

	newNode->data = data;
	newNode->nextNode = NULL;
	if(*head == NULL)
	{
		*head = newNode;
		return;
	}

	newNode->nextNode = *head;
	*head = newNode;

	return;
}
void PrintAll(node *head)
{
	node *curNode;

	while(curNode != NULL)
	{
		printf("%d ",curNode->data);
		curNode = curNode->nextNode;
	}

	puts("");
	return;
}
