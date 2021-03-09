#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
	int id;
	char name[31];
	struct _node *nextNode;
} node;

node *head = NULL;

void createNode(int id, char *name);

int main(void)
{
	FILE *ifp = fopen("input[13].txt","r");

	int st_id;
	char st_name[31];

	int i;
	int number;

	node *curNode;

	fscanf(ifp,"%d",&number);
	for(i = 0;i < number; ++i)
	{
		fscanf(ifp,"%d / %[^\n]",&st_id,st_name);
		createNode(st_id,st_name);
	}
	
	curNode = head;
	puts("------Student list--------");
	while(curNode != NULL)
	{
		printf("%d / %s\n",curNode->id,curNode->name);
		curNode = curNode->nextNode;
	}

	return 0;
}

void createNode(int id, char *name)
{
	node *newNode = malloc(sizeof(node));
	node *curNode = head;

	newNode->id = id;
	strcpy(newNode->name,name);
	newNode->nextNode = NULL;

	if(head == NULL)
	{
		head = newNode;
		return;
	}
	else
	{
		while(curNode->nextNode != NULL)
			curNode = curNode->nextNode;

		curNode->nextNode = newNode;
	}

	return;
}
