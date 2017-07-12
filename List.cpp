#include <stdio.h>
#include <malloc.h>

/** 
 **		LIST	struct list		������		int
 											struct list *
 **		STACK	struct stack	ջ			int
 											struct stack *
 **		QUEUE	struct queue	���� 
 */ 
typedef struct list
{
	int data;
	struct list *next;
}LIST;

typedef struct stack
{
	int data;
	struct stack *next;
}STACK;

/**
 **		createNode		��������		LIST * head
 										int data
 
 **		insertHeadNode	ͷ����			LIST * head
 										int data
 										
 **		insertTailNode	β����			LIST *head
 										int data
 										
 **		insertBodyNode 	�������		LIST *head
 										int data
 										int item
 **		boolHeadNode	�ж�ͷ�Ƿ�Ϊ��  LIST *head
 
 **		deleteNode		ɾ�����		LIST *head
 										int data
 										
**		updataNode	 	���½������	LIST *head
										int data 
 */
LIST *createNode(LIST *head, int data);
LIST *insertHeadNode(LIST *head, int data);
LIST *insertTailNode(LIST *head, int data);
LIST *insertBodyNode(LIST *head, int data, int item);
int boolHeadNode(LIST *head);
LIST *localNode(LIST *head, int data);
LIST *deleteNode(LIST *head, int data);
LIST *updataNode(LIST * head, int data, int updata);

void printList(LIST *head);

/**
 **
 */
int main()
{
	int data;
	int updata;
	int item;
	LIST *temp = NULL;
/**
 **		����ͷ��� 
 */
	LIST *head;
	printf("Enter head node> ");
 	scanf("%d", &data);
	head = createNode(head, data);
		
/**
 **		������ 
 */
	printf("Insert node from head> ");
	scanf("%d", &data);
	head = insertHeadNode(head, data);
	
	printf("Insert node from tail> ");
	scanf("%d", &data);
	head = insertTailNode(head, data);
	
	printf("Insert node front item>item> ");
	scanf("%d",&item);
	printf("                      >node> ");
	scanf("%d",&data);
	head = insertBodyNode(head, data, item);

/**
 **		��λ���
 */
 	printf("Local number> ");
 	scanf("%d",&data);
	temp = localNode(head, data);
	if(data == temp->data)
		printf("true\n");
	else
		printf("false\n");

/**
 **		ɾ����� 
 */
 	printf("Delete number> ");
 	scanf("%d",&data);
 	head = deleteNode(head, data);
  
/**
 **		���½������ 
 */
	printf("Previously data> ");
	scanf("%d",&data);
	printf("Updata> ");
	scanf("%d",&updata);
	head = updataNode(head, data, updata);
 	
	printList(head);
	return 0;
}


/**		createNode		��������
 **		insertHeadNode	ͷ����
 **		insertTailNode	β����
 **		insertBodyNode 	�������
 **		boolHeadNode	�ж�ͷ�Ƿ�Ϊ�� 
 */
LIST *createNode(LIST *head, int data)
{
	head = (LIST *)malloc(sizeof(LIST));
	head->data = data;
	head->next = NULL;
	return head;
}

int boolHeadNode(LIST *head)
{
	if( NULL == head->next)
		return 1;
	else
		return 0;
}

LIST *insertHeadNode(LIST *head, int data)
{
	LIST *temp;
	temp = (LIST *)malloc(sizeof(LIST));
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}

LIST *insertTailNode(LIST *head, int data)
{
	LIST *temp, *tail;
	temp = (LIST *)malloc(sizeof(LIST));
	temp->data = data;
	temp->next = NULL;
	tail = head;
	while(NULL != tail->next)
		tail = tail->next;
	tail->next = temp;
	return head;
}

LIST *insertBodyNode(LIST *head, int data, int item)
{
	LIST *temp, *point;
	temp = (LIST *)malloc(sizeof(LIST));
	int k = 0;
	temp->data = data;
	point = head;
	while(NULL != point->next && k < item - 1)
	{
		point = point->next;
		k++;
	}
	if(NULL == point->next)
		return 0;
	else
	{
		temp->next = point->next;
		point->next = temp;
	}
	return head;
}

void printList(LIST *head)
{
	LIST *point;
	point = head;
	while(NULL != point)
	{
		printf("%d\n",point->data);
		point = point->next;
	}
}

LIST *localNode(LIST *head, int data)
{
	LIST *local;
	local = head->next;
	if(data == head->data)
		return head;
	while(data != local->data && NULL != local->next)
		local = local->next;
	return local;
}

LIST *deleteNode(LIST *head, int data)
{
	LIST *del, *delf;
		
	if(head->data == data)
	{	
		head = head->next;
		return head;
	}
	del = head->next;
	delf = head;

	while(data != del->data && NULL != del->next)
	{
		delf = del;
		del = del->next;
	}
	if(data == del->data)
		delf->next = del->next;
	return head;
}

LIST *updataNode(LIST * head, int data, int updata)
{
	LIST *temp;
	temp = (LIST *)malloc(sizeof(LIST));
	temp = localNode(head, data);
	if(data == temp->data)
		temp->data = updata;
	else
		printf("Not find %d data.\n",data);
	return head;
}
