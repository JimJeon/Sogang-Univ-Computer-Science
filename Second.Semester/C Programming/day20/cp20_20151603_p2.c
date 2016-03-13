#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
	char data;
	struct _node *nextNode;
} node;

node *head = NULL;

void InsertNodeAtFront(char a);
void InsertNodeAtBack(char b);
void PrintList(void);

int main(void)
{
	InsertNodeAtFront('p');
	InsertNodeAtFront('p');
	InsertNodeAtFront('a');
	InsertNodeAtBack('l');
	InsertNodeAtBack('e');

	PrintList();

	return 0;
}

void InsertNodeAtFront(char c)
{
	node *newNode = malloc(sizeof(node));

	newNode->data = c;
	newNode->nextNode = NULL;

	if(head == NULL)
	{
		head = newNode;
		return;
	}

	newNode->nextNode = head;
	head = newNode;
	return;
}
	
void InsertNodeAtBack(char c)
{
	node *newNode = malloc(sizeof(node));
	node *curNode = head;

	newNode->data = c;
	newNode->nextNode = NULL;

	if(head == NULL)
	{
		head = newNode;
		return;
	}

	while(curNode->nextNode != NULL)
		curNode = curNode->nextNode;

	curNode->nextNode = newNode;
	
	return;
}
void PrintList(void)
{
	node *curNode = head;

	while(curNode != NULL)
	{
		printf("%c",curNode->data);
		curNode = curNode->nextNode;
	}
	puts("");
	return;
}
