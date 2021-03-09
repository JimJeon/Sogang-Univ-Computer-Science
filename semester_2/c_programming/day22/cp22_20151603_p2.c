#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	char data;
	struct _node *nextNode;
} STACK_NODE;

typedef struct
{
	int level;
	struct _node *head;
} STACK;

void stack_push(STACK *stack, char ch);
char stack_pop (STACK *stack);

int main(void)
{
	STACK parentheses_stack;

	char expression_ch;
	char balance_flag = 1;
	char parentheses1_flag = 0;
	char parentheses2_flag = 0;
	char parentheses3_flag = 0;

	parentheses_stack.level = 0;
	parentheses_stack.head	= NULL;

	int a = 0;

	do
	{
		expression_ch = getchar();

		switch(expression_ch)
		{
			case '(':
				parentheses1_flag += 1;
				break;
			case '{':
				parentheses2_flag += 1;
				break;
			case '[':
				parentheses3_flag += 1;
				break;
			case ')':
				if(parentheses1_flag == 0)
				{
					balance_flag = 0;
					break;
				}
				parentheses1_flag -= 1;
				while(expression_ch != '('&&expression_ch != 0)
					expression_ch = stack_pop(&parentheses_stack);
				break;
			case '}':
				if(parentheses2_flag == 0)
				{
					balance_flag = 0;
					break;
				}
				parentheses2_flag -= 1;
				while(expression_ch != '{'&&expression_ch != 0)
					expression_ch = stack_pop(&parentheses_stack);
				break;
			case ']':
				if(parentheses3_flag == 0)
				{
					balance_flag = 0;
					break;
				}
				parentheses3_flag -= 1;
				while(expression_ch != '['&&expression_ch != 0)
					expression_ch = stack_pop(&parentheses_stack);
				break;
			default:
				break;
		}
		
		if(parentheses1_flag||parentheses2_flag||parentheses3_flag)
			stack_push(&parentheses_stack,expression_ch);

		if(balance_flag == 0) break;

	}while(expression_ch != '\n');

	if(!parentheses_stack.head) balance_flag = 1;
	else balance_flag = 0;

	if(balance_flag) puts("Matched Parentheses!");
	else puts("Unmatched Parentheses!");

	return 0;
}
void stack_push(STACK *stack, char ch)
{
	STACK_NODE *newNode = malloc(sizeof(STACK_NODE));
	STACK_NODE *curNode = stack->head;

	newNode->data = ch;
	newNode->nextNode = NULL;

	stack->level += 1;

	if(stack->head == NULL)
	{
		stack->head = newNode;
		return;
	}

	while(curNode->nextNode != NULL)
		curNode = curNode->nextNode;

	curNode->nextNode = newNode;

	return;
}
char stack_pop(STACK *stack)
{
	STACK_NODE *curNode = stack->head;
	STACK_NODE *target	= stack->head;

	char return_value;

	if(stack->level == 0) 
	{
		puts("Error!");
		return 0;
	}
	else if(stack->level == 1)
	{
		return_value = curNode->data;
		free(curNode);

		stack->head = NULL;
		stack->level -= 1;
		
		return return_value;
	}
	else
	{
		while(curNode->nextNode->nextNode != NULL)
			curNode = curNode->nextNode;

		target = curNode->nextNode;
		return_value = target->data;

		free(target);

		curNode->nextNode = NULL;
		stack->level -= 1;
		
		return return_value;
	}
}
