#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node
{
	int data;
	struct _node *nextNode;
} STACK_NODE;

typedef struct
{
	int count;
	struct _node *link;
} STACK;

void Exit(STACK *stack);
void Push(STACK *stack);
void Pop(STACK *stack);
void PrintAll(STACK stack);

int main(void)
{
	STACK stack;

	int user_choice;
	int flag = 1;

	stack.count = 0;
	stack.link = NULL;

	puts("****** Menu ******");
	puts("* 0 : Exit\t *");
	puts("* 1 : Push\t *");
	puts("* 2 : Pop\t *");
	puts("* 3 : Print All\t *");
	puts("******************");

	while(flag)
	{
		
		printf("Select > ");
		scanf("%d",&user_choice);

		switch(user_choice)
		{
			case 0:
				Exit(&stack);
				flag = 0;
				break;
			case 1:
				Push(&stack);
				break;
			case 2:
				Pop(&stack);
				break;
			case 3:
				PrintAll(stack);
				break;
		}
	}
	return 0;
}
void Push(STACK *stack)
{
	STACK_NODE *newNode = malloc(sizeof(STACK_NODE));
	STACK_NODE *curNode = stack->link;

	int user_input;

	printf("Input Data > ");
	scanf("%d",&user_input);

	newNode->data = user_input;
	newNode->nextNode = NULL;

	if(stack->count == 0)
	{
		stack->link = newNode;
		stack->count += 1;
		return;
	}

	while(curNode->nextNode != NULL)
		curNode = curNode->nextNode;

	curNode->nextNode = newNode;
	stack->count += 1;

	return;
}
void Pop(STACK *stack)
{
	STACK_NODE *curNode = stack->link;
	STACK_NODE *target = NULL;

	if(stack->count == 0)
	{
		puts("Error!");
		return;
	}
	else if(stack->count == 1)
	{
		printf("Pop %d\n",curNode->data);
		free(curNode);

		stack->link = NULL;
		stack->count -= 1;
		return;
	}
	else
	{
		while(curNode->nextNode->nextNode != NULL)
			curNode = curNode->nextNode;

		target = curNode->nextNode;

		printf("Pop %d\n",target->data);
		free(target);

		curNode->nextNode = NULL;
		stack->count -= 1;
		return;
	}
}
void PrintAll(STACK stack)
{
	STACK_NODE *curNode = stack.link;
	
	while(curNode != NULL)
	{
		printf("%d ",curNode->data);
		curNode = curNode->nextNode;
	}

	printf("\nStack Level : %d\n",stack.count);

	return;
}
void Exit(STACK *stack)
{
	STACK_NODE *head = stack->link;
	STACK_NODE *curNode;
	STACK_NODE *target;

	while(head != NULL)
	{
		curNode = head;
		if(curNode->nextNode == NULL)
		{
			free(head);
			stack->link = NULL;
			return;
		}
		while(curNode->nextNode->nextNode != NULL)
			curNode = curNode->nextNode;
		target = curNode->nextNode;
		free(target);
		curNode->nextNode = NULL;
	}
	return;
}
