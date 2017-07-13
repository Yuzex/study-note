#include <stdio.h>
#include <malloc.h>

typedef struct stack
{
	int data;
	struct stack *next;
}STACK;

STACK *pushStack(STACK *top, int data);
STACK *popStack(STACK *top);
void printList(STACK *head);

int main()
{
	STACK *top;
	STACK *temp;
	int data = 0;
	top = NULL;
	do
	{
		printf("Enter data > ");
		scanf("%d",&data);
		top = pushStack(top, data);
	}while(0 != data);
	
	if(NULL == (top = popStack(top)))
		printf("stack has not any data.\n");
	else
		printf("pop success.\n");
	printList(top);
	return 0;
}

STACK *pushStack(STACK *top, int data)
{
	STACK *temp;
	temp = (STACK *)malloc(sizeof(STACK));
	temp->data = data;
	temp->next = top;
	top = temp;
	return top;
}

STACK *popStack(STACK *top)
{
	if(NULL == top)
		return NULL;
	else
	{
		STACK *temp;
		temp = (STACK *)malloc(sizeof(STACK));
		temp = top;
		top = top->next;
		free(temp);
		return top;
	}
}

void printList(STACK *head)
{
	STACK *point;
	point = head;
	while(NULL != point)
	{
		printf("%d\n",point->data);
		point = point->next;
	}
}
