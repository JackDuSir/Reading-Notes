#include "teachmanage.h"


//传入它的地址可以直接修改它的指向
void init_data(void **teacher)//初始化数据
{
	//开辟内存
	struct teacher * myteacher = malloc(sizeof(struct teacher));

	if (NULL == myteacher)
	{
		return;
	}

	myteacher->head.next = NULL;
	myteacher->size = 0;

	*teacher = myteacher;
}

//插入数据
void insert_data(void *linklins, unsigned int pos, void *data)//插入数据
{
	if (NULL == linklins)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	if (pos < 0)
	{
		printf("你选择的位置不对！");
		return;
	}
	//把linklins转换
	struct teacher *mylinklist = (struct teacher *)linklins;
	//把data转换为struct，目的在于只访问他的前四个字节，
	//用户传进来不知道是什么类型，通过转换获得他的前四个字节，储存地址
	//因为要访问前四个字节所以要空下来
	struct site *mydata = (struct site *)data;
	
	if (pos > mylinklist->size)
	{
		pos = mylinklist->size;
	}		
	//定义一个辅助指针让他等于头结点
	struct site * pCurre = &(mylinklist->head);
	
	//因为我们是按位置查找，所以我们循环找到他的地址
	//找到地址给他传值
	for (unsigned int i = 0; i < pos; ++i)
	{
		pCurre = pCurre->next;
	}

	mydata->next = pCurre->next;
	pCurre->next = mydata;

	//最后要让他加加
	mylinklist->size++;
}

void findall_data(void *linklins,void(*print)(void *))//遍历
{ 

	if (NULL == linklins)
	{
		return;
	}

	struct teacher *mylinklist = (struct teacher*)linklins;

	struct site * prr = mylinklist->head.next;

	while (prr != NULL)
	{

		print(prr);
		prr = prr->next;
	}

}

void delete_data(void *linklins,unsigned int pos)
{
	if (NULL == linklins)
	{
		return;
	}
	//把用户传递的数据强转
	struct teacher *mylinklist = (struct teacher *)linklins;

	if (pos < 0 || pos>mylinklist->size)
	{
		return;
	}
	struct site * pCurre = &(mylinklist->head);
	
	for (unsigned int i = 0; i < pos; ++i)
	{
		pCurre = pCurre->next;
	}
	//删除pru这个节点
	struct site * pru = pCurre->next;

	pCurre->next = pru->next;
}

void find_data(void *linklins, unsigned int pos, void(*print)(void *))//查找节点
{
	if (NULL == linklins)
	{
		return;
	}
	
	struct teacher *mylinklist = (struct teacher *)linklins;
	if (pos<0 || pos>mylinklist->size)
	{
		printf("你输入的位置不对");
		return;
	}
	struct site * pCurre = &(mylinklist->head);

	for (unsigned int i = 0; i < pos; ++i)
	{
		pCurre = pCurre->next;
	}

	print(pCurre);

}

void alter_data(void *linklins, unsigned int pos, void *data)//修改数据
{
	if (NULL == linklins)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct teacher *mylinklist = (struct teacher *)linklins;
	struct site * pCurre = &(mylinklist->head);
	struct site *pru = NULL;
	struct site * mydata = (struct site *)data;

	if (pos<0||pos>mylinklist->size)
	{
		printf("你输入的位置不对\n");
		return;
	}

	for (  unsigned int i = 0; i < pos; ++i)
	{
		
		pCurre = pCurre->next;
	}

	pru = pCurre->next;
	mydata->next = pru->next;
	pCurre->next = mydata;

}

void pricefine_data(void *linklins, void *data, int(*compare)(void *, void*), void(*prin)(void *))
{
	if (NULL == linklins)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}
	struct teacher *mylinklist = (struct teacher *)linklins;
	struct site *mydata = (struct site *)data;
	struct site *pCuure = &(mylinklist->head);
	for (unsigned int i = 0; i < mylinklist->size; ++i)
	{
		if (compare(pCuure,mydata))
		{
			printf("你要找的数据是");
			prin(pCuure);
			return;
		}

		pCuure = pCuure->next;
	}

	printf("未找到！！\n");
}

