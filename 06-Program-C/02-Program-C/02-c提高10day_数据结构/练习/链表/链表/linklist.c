#include"linklist.h"

void *init()//³õÊ¼»¯
{
	struct linklistinf *linklist = malloc(sizeof(struct linklistinf));
	if (NULL == linklist)
	{
		return NULL;
	}
	linklist->head.next = NULL;
	linklist->head.data = NULL;
	linklist->size = 0;
	return linklist;
}

void inser(void *linkls, int pos, void *data)
{
	if (NULL == linkls)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct linklistinf *mylink = (struct linklistinf *)linkls;
	struct node *pCurret = &(mylink->head);
	if (pos<0 || pos>mylink->size)
	{
		pos = mylink->size;
	}
	for (int i = 0; i < pos; ++i)
	{
		pCurret = pCurret->next;
	}
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;

	newnode->next = pCurret->next;
	pCurret->next = newnode;


	mylink->size++;
}
void show(void *linkls, void(*print)(void *))
{
	if (NULL == linkls)
	{
		return;
	}
	struct linklistinf *mylink = (struct linklistinf *)linkls;
	struct node *pCurret = mylink->head.next;

	while (pCurret != NULL)
	{
		print(pCurret->data);
		pCurret = pCurret->next;
	}

}
void destroy(void *linklist)
{
	if(NULL == linklist)
	{
		return;
	}
	struct linklistinf *mylink = (struct linklistinf *)linklist;
	struct node *pre = mylink->head.next;
	struct node *pCurret =NULL;
	while (pre != NULL)
	{
		pCurret = pre->next;
		free(pre);
		pre = NULL;
		pre = pCurret;
	}
	free(mylink);
}
