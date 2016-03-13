#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node* nextNode;
} QUEUE_NODE;

typedef struct
{
	struct _node *front;
	struct _node *rear;

	int count;
} QUEUE_HEAD;

void Exit(QUEUE_HEAD* queue);
void Enqueue(QUEUE_HEAD* queue);
void Dequeue(QUEUE_HEAD* queue);
void PrintAll(QUEUE_HEAD queue);

int main(void)
{
	QUEUE_HEAD queue;

	int flag = 1;
	int user_choice;

	queue.count = 0;
	queue.front = NULL;
	queue.rear	= NULL;

	puts("****** Menu ******");
	puts("* 0 : Exit\t *");
	puts("* 1 : Enqueue\t *");
	puts("* 2 : Dequeue\t *");
	puts("* 3 : Print All\t *");
	puts("******************");

	while(flag)
	{
		printf("Select > ");
		scanf("%d",&user_choice);

		switch(user_choice)
		{
			case 0:
				flag = 0;
				Exit(&queue);
				break;
			case 1:
				Enqueue(&queue);
				break;
			case 2:
				Dequeue(&queue);
				break;
			case 3:
				PrintAll(queue);
				break;
		}
	}

	return 0;
}
void Enqueue(QUEUE_HEAD* queue)
{
	int data;

	QUEUE_NODE *newNode = malloc(sizeof(QUEUE_NODE));

	printf("Input Data > ");
	scanf("%d",&data);

	newNode->data = data;
	newNode->nextNode = NULL;

	if(queue->front == NULL)
	{
		queue->front = newNode;
		queue->rear  = newNode;
	}
	else
	{
		queue->rear->nextNode = newNode;
		queue->rear = newNode;
	}

	queue->count += 1;

	return;
}
void Dequeue(QUEUE_HEAD *queue)
{
	QUEUE_NODE *curNode = queue->front;

	if(curNode == NULL)
	{
		puts("Queue is empty!");
		return;
	}

	printf("Dequeue %d\n",curNode->data);

	queue->front = queue->front->nextNode;
	queue->count -= 1;
	free(curNode);
	return;
}
void PrintAll(QUEUE_HEAD queue)
{
	QUEUE_NODE *curNode = queue.front;
	
	while(curNode != NULL)
	{
		printf("%d ",curNode->data);
		curNode = curNode->nextNode;
	}

	printf("\nQueue Level : %d\n",queue.count);

	return;
}
void Exit(QUEUE_HEAD *queue)
{
	QUEUE_NODE *head = queue->front;
	QUEUE_NODE *curNode;
	QUEUE_NODE *target;

	while(head != NULL)
	{
		curNode = head;
		if(curNode->nextNode == NULL)
		{
			free(head);
			queue->front = NULL;
			queue->rear  = NULL;
			return;
		}
		while(curNode->nextNode->nextNode != NULL)
			curNode = curNode->nextNode;
		target = curNode->nextNode;
		free(target);

		curNode->nextNode = NULL;
		
		queue->rear = curNode;
	}
	return;
}
