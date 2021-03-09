#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	char data;
	struct _node *nextNode;
} node;

node *head = NULL;

void InsertNodeAtFront(char a);
void InsertNodeAtBack(char b);
void DeleteNodeAtFront(void);
void DeleteNodeAtBack(void);
void PrintList(void);

int main(void)
{
	InsertNodeAtFront('n');
	InsertNodeAtFront('e');
	InsertNodeAtFront('p');
	InsertNodeAtBack('l');
	InsertNodeAtFront('o');
	InsertNodeAtBack('a');
	InsertNodeAtBack('b');
	puts("----Insertion Complete----");
	PrintList();
	DeleteNodeAtFront();
	DeleteNodeAtBack();
	DeleteNodeAtBack();
	DeleteNodeAtBack();
	puts("-----Delete Complete-----");
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
void DeleteNodeAtFront(void)
{
	node *target = head;
	
	head = target->nextNode;
	free(target);

	return;
}
void DeleteNodeAtBack(void)
{
	node *target = NULL;
	node *curNode = head;
	
	while(curNode->nextNode->nextNode != NULL)
		curNode = curNode->nextNode;
	
	target = curNode->nextNode;
	free(target);

	curNode->nextNode = NULL;

	return;
}
