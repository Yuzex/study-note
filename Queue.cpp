#include <stdio.h>
#include <malloc.h>

typedef struct quenode
{
	int data;
	struct quenode *next;
}QUE_NODE;

typedef struct
{
	QUE_NODE *front, *rear;
}QUE;

QUE *linkQueueIn(QUE *queue, int data);
QUE *linkQueueOut(QUE *queue);
void printList(QUE_NODE *head);

int main()
{
	QUE *queue;
	queue->front = NULL;
	queue->rear = NULL;
	int data = 0;
	do
	{
		printf("Enter data > ");
		scanf("%d",&data);
		queue = linkQueueIn(queue, data);	
	}while(0 != data);
	while(NULL != queue->front)
	{
		if(NULL == (queue = linkQueueOut(queue)))
			printf("queue has not any data.\n");
		else
			printf("out success.\n");
	}
		
	printList(queue->front);
	return 0;
}

QUE *linkQueueIn(QUE *queue, int data)
{
	QUE_NODE *temp;
	temp = (QUE_NODE *)malloc(sizeof(QUE_NODE));
	temp->data = data;
	temp->next = NULL;
	if( NULL == queue->rear && NULL == queue->front)
	{
		queue->front = temp;
		queue->front->next = queue->rear;
		queue->rear = queue->front;
	}
	else
	{
		queue->rear->next = temp;
		queue->rear = temp;	
	}
	return queue;
}

QUE *linkQueueOut(QUE *queue)
{
	if( NULL == queue->front && queue->rear == queue->front)
		return NULL;
	else
	{
		QUE_NODE *temp;
		temp = queue->front;
		queue->front = temp->next;
		free(temp);
	}
	return queue;
}

void printList(QUE_NODE *head)
{
	QUE_NODE *point;
	point = head;
	while(NULL != point)
	{
		printf("%d\n",point->data);
		point = point->next;
	}
}
