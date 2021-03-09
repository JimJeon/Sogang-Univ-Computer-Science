#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct _node
{
	char command[10];
	struct _node *nextNode;
} QUEUE_NODE;

typedef struct
{
	QUEUE_NODE *front;
	QUEUE_NODE *rear;

	int count;
} QUEUE;

bool CheckCommand(char *command);
void EnqueueCommand(QUEUE *pQueue, char *dataIn);
bool DequeuePrint(QUEUE *pQueue, char *dataOut);

int main(void)
{
	char command[10];
	QUEUE *pQueue = malloc(sizeof(QUEUE));

	pQueue->front = NULL;
	pQueue->rear  = NULL;
	pQueue->count = 0;

	while(true)
	{
		printf(">>");
		scanf("%s",command);

		if(!CheckCommand(command))
		{
			puts("[Invalid]");
			continue;
		}
		
		if(!strcmp(command,"q")||!strcmp(command,"quit")) break;

		else if(!strcmp(command,"h")||!strcmp(command,"history"))
			while(DequeuePrint(pQueue,command)) puts(command);
		else
		{
			printf("[Valid] %s\n",command);

			EnqueueCommand(pQueue,command);
		}
	}

	return 0;
}

bool CheckCommand(char *command)
{
	if(!strcmp(command,"help")) return true;
	if(!strcmp(command,"dir")) return true;
	if(!strcmp(command,"mkdir")) return true;
	if(!strcmp(command,"cd")) return true;
	if(!strcmp(command,"h")) return true;
	if(!strcmp(command,"history")) return true;
	if(!strcmp(command,"quit")) return true;
	if(!strcmp(command,"q")) return true;

	return false;
}
void EnqueueCommand(QUEUE *pQueue, char *dataIn)
{
	QUEUE_NODE *newNode = malloc(sizeof(QUEUE_NODE));

	strcpy(newNode->command,dataIn);
	newNode->nextNode = NULL;
	
	if(pQueue->front == NULL)
	{
		pQueue->front = newNode;
		pQueue->rear  = newNode;
	}
	else
	{
		pQueue->rear->nextNode = newNode;
		pQueue->rear = newNode;
	}

	pQueue->count += 1;

	return;
}
bool DequeuePrint(QUEUE *pQueue, char *dataOut)
{
	QUEUE_NODE *curNode = pQueue->front;

	if(curNode == NULL)	return false;

	strcpy(dataOut,curNode->command);

	pQueue->front = pQueue->front->nextNode;
	pQueue->count -= 1;

	free(curNode);

	return true;
}
