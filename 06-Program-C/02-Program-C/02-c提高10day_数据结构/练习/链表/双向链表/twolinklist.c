#include"twolinklist.h"

void *init()
{
	struct linklist *mylink = malloc(sizeof(struct linklist));
	mylink->headnod.back = NULL;
	mylink->headnod.head = NULL;
	mylink->headnod.data = NULL;
	mylink->size = 0;
	return mylink;
}


void inser(void *linklist, int pos, void *data)
{
	if (NULL == linklist)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct linklist *mylink = (struct linklist*)linklist;
	struct node *pCurrent = &(mylink->headnod);

	if (pos < 0 || pos>mylink->size)
	{
		pos = mylink->size;
	}

	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = (struct node *)data;
	newnode->head = NULL;
	newnode->back = NULL;

	if (mylink->size == 0)
	{
		newnode->back = pCurrent->back;
		newnode->head = pCurrent;
		pCurrent->back = newnode;
		mylink->size++;
		return;
	}
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->back;
	}
	if (pos == mylink->size)
	{
		newnode->back = pCurrent->back;
		newnode->head = pCurrent;
		pCurrent->back = newnode;
		mylink->size++;
		return;
	}

	newnode->back = pCurrent->back;
	newnode->head = pCurrent;
	pCurrent->back->head = newnode;
	pCurrent->back = newnode;
	
	mylink->size++;
}

void  show(void *linklist,void(*print)(void *))
{
	if (NULL==linklist)
	{
		return;
	}

	struct linklist *mylink = (struct linklist*)linklist;
	struct node *pCurrent = mylink->headnod.back;

	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->back;
	}
}

void deletenode(void *linklist, int pos)
{
	if (NULL == linklist)
	{
		return;
	}

	struct linklist *mylink = (struct linklist*)linklist;

	struct node *pCurrent =&(mylink->headnod);

	if (pos < 0 || pos >= mylink->size)
	{
		return;
	}

	if (mylink->size == 0)
	{
		return;
	}
	if (mylink->size == 1)
	{
		free(pCurrent->back);
		mylink->headnod.head = NULL;
		mylink->size--;
	}

	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->back;
	}

	if (pos == mylink->size - 1)
	{
		free(pCurrent->back);
		pCurrent->back = NULL;
		mylink->size--;
		return;
	}

	struct node *pre = pCurrent->back;
	pre->back->head = pCurrent;
	pCurrent->back = pre->back;
	free(pre);
	mylink->size--;	
}

void reverseshow(void *linklist,void(*print)(void *))
{
	if (NULL == linklist)
	{
		return;
	}

	struct linklist *mylink = (struct linklist*)linklist;
	struct node *pCurrent = &(mylink->headnod);

	while (pCurrent->back != NULL)
	{
		pCurrent = pCurrent->back;
	}
	//for (int i = 0; i < mylink->size; ++i)
	//{
	//	pCurrent = pCurrent->back;
	//}

	while (pCurrent != &(mylink->headnod))
	{
		print(pCurrent->data);
		pCurrent = pCurrent->head;
	}

}


void destroy(void *linklist)
{
	if (NULL == linklist)
	{
		return;
	}
	struct linklist *mylink = (struct linklist*)linklist;
	struct node *pCurrent = mylink->headnod.back;
	struct node *pre = NULL;

	while ( pCurrent != NULL)
	{
		pre = pCurrent->back;
		free(pCurrent);
		pCurrent = NULL;
		pCurrent = pre;
	}

	free(mylink);
	mylink = NULL;
}