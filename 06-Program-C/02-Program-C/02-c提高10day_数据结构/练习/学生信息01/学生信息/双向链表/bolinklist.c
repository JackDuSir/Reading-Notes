#include"bolinklist.h"

struct Person
{
	int age;
};

//初始化链表
void *InitLink()
{
	Link *mylink =(Link *)malloc(sizeof(Link));
	if (mylink == NULL)
	{
		printf("memory allot err！");
		return NULL;
	}

	mylink->linkhead.data = NULL;
	mylink->linkhead.haed = NULL;
	mylink->linkhead.next = NULL;
	mylink->size = 0;
	
	return mylink;
}

//插入数据 按照位置
void InsertNode(void *linkhead, int pos, void *data)
{
	if (NULL == linkhead || NULL == data)
	{
		return;
	}

	Link *mylink = (Link *)linkhead;

	if (pos < 0 || pos > mylink->size)
	{
		pos = mylink->size;
	}

	Node* pre = &(mylink->linkhead);
	Node* pCurr = pre;
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->haed = NULL;

	if (mylink->size == 0)
	{	
		newNode->next = pre->next;
		pre->next = newNode;
		newNode->haed = pre;

		mylink->size++;
		return;
	}

	for (int i = 0; i < pos; ++i)
	{
		//pre = pCurr;
		pCurr = pCurr->next;	
	}

	if (pos == mylink->size)
	{
		newNode->next = pCurr->next;
		pCurr->next = newNode;
		newNode->haed = pCurr;
		mylink->size++;
		return;
	}

	pCurr->next->haed = newNode;
	newNode->next = pCurr->next;
	pCurr->next = newNode;
	newNode->haed = pCurr;
	mylink->size++;

	
}
void show(void *linkhead, void(*print)(void *))
{
	if (NULL == linkhead)
	{
		return;
	}
	if (NULL == print)
	{
		return;
	}
	Link *mylink = (Link *)linkhead;
	Node* mynode = mylink->linkhead.next;


	while (mynode != NULL)
	{
		print(mynode->data);
		mynode = mynode->next;
	}

}

//反向遍历
void revshow(void *linkhead, void(*print)(void *))
{
	if (NULL == linkhead || NULL == print)
	{
		return;
	}
	Link *mylink = (Link *)linkhead;
	Node* mynode = &(mylink->linkhead);
	Node*pCurr = mynode->next;
	while (pCurr->next != NULL)
	{
		pCurr = pCurr->next;
	}
	while (pCurr != &(mylink->linkhead))
	{
		print(pCurr->data);
		pCurr = pCurr->haed;
	}
}
//根据位置删除节点
void DeleteNode(void *linkhead, int pos)
{
	if (NULL == linkhead)
	{
		return;
	}

	Link *mylink = (Link *)linkhead;

	if ( pos<0 || pos>mylink->size)
	{
		return;
	}
	
	Node *pCurr = &(mylink->linkhead);
	Node *pre = NULL;

	for (int i = 0; i < pos; ++i)
	{
		pCurr = pCurr->next;
	}

	if (pos == mylink->size)
	{
		pre = pCurr->next;
		free(pre);
		pre = NULL;
		pCurr->next = NULL;
		mylink->size--;
	}

	pre = pCurr->next;
	pre->next->haed = pCurr;
	pCurr->next = pre->next;
	free(pre);
	pre = NULL;
	mylink->size--;
}
//销毁链表
void deslinklist(void *linkhead)
{
	if (NULL == linkhead)
	{
		return;
	}
	Link *mylink = (Link *)linkhead;
	Node *pCurr = &(mylink->linkhead);
	Node *pre = pCurr->next;

	while (pre != NULL)
	{
		pCurr=pre->next;
		if (pre != NULL)
		{
			free(pre);
			pre = NULL;
		}
		pre =pCurr;
	}
	free(mylink);
	mylink = NULL;
	printf("链表已销毁！！\n");
}

//打印节点个数
void NodeAmount(void *linkhead)
{
	Link *mylink = (Link *)linkhead;
	printf("链表节点个数为%d个！\n", mylink->size);
}



//根据内容查找节点
void PriceSeek(void *linkhead, void* data)
{
	if (NULL == linkhead)
	{
		printf("linklist err!\n");
		return;
	}

	if (NULL == data)
	{
		printf("data err!\n");
		return;
	}

	Link *mylink = (Link *)linkhead;
	Node *node = mylink->linkhead.next;
	struct Person *mynode = NULL;
	mynode = (struct Person *)node->data;
	struct Person *mydata = (struct Person *)data;
	int i = 0;
	while (node != NULL)
	{
		++i;
		if (mynode->age == mydata->age);
		{
			printf("你要找的是：-----");
			printf("%d 位置为%d\n", mynode->age,i);
			break;
		}
		
		node = node->next;
	}
}



