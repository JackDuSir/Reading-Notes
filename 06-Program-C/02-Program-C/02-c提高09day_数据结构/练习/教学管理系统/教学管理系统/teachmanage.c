#include "teachmanage.h"


//�������ĵ�ַ����ֱ���޸�����ָ��
void init_data(void **teacher)//��ʼ������
{
	//�����ڴ�
	struct teacher * myteacher = malloc(sizeof(struct teacher));

	if (NULL == myteacher)
	{
		return;
	}

	myteacher->head.next = NULL;
	myteacher->size = 0;

	*teacher = myteacher;
}

//��������
void insert_data(void *linklins, unsigned int pos, void *data)//��������
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
		printf("��ѡ���λ�ò��ԣ�");
		return;
	}
	//��linklinsת��
	struct teacher *mylinklist = (struct teacher *)linklins;
	//��dataת��Ϊstruct��Ŀ������ֻ��������ǰ�ĸ��ֽڣ�
	//�û���������֪����ʲô���ͣ�ͨ��ת���������ǰ�ĸ��ֽڣ������ַ
	//��ΪҪ����ǰ�ĸ��ֽ�����Ҫ������
	struct site *mydata = (struct site *)data;
	
	if (pos > mylinklist->size)
	{
		pos = mylinklist->size;
	}		
	//����һ������ָ����������ͷ���
	struct site * pCurre = &(mylinklist->head);
	
	//��Ϊ�����ǰ�λ�ò��ң���������ѭ���ҵ����ĵ�ַ
	//�ҵ���ַ������ֵ
	for (unsigned int i = 0; i < pos; ++i)
	{
		pCurre = pCurre->next;
	}

	mydata->next = pCurre->next;
	pCurre->next = mydata;

	//���Ҫ�����Ӽ�
	mylinklist->size++;
}

void findall_data(void *linklins,void(*print)(void *))//����
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
	//���û����ݵ�����ǿת
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
	//ɾ��pru����ڵ�
	struct site * pru = pCurre->next;

	pCurre->next = pru->next;
}

void find_data(void *linklins, unsigned int pos, void(*print)(void *))//���ҽڵ�
{
	if (NULL == linklins)
	{
		return;
	}
	
	struct teacher *mylinklist = (struct teacher *)linklins;
	if (pos<0 || pos>mylinklist->size)
	{
		printf("�������λ�ò���");
		return;
	}
	struct site * pCurre = &(mylinklist->head);

	for (unsigned int i = 0; i < pos; ++i)
	{
		pCurre = pCurre->next;
	}

	print(pCurre);

}

void alter_data(void *linklins, unsigned int pos, void *data)//�޸�����
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
		printf("�������λ�ò���\n");
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
			printf("��Ҫ�ҵ�������");
			prin(pCuure);
			return;
		}

		pCuure = pCuure->next;
	}

	printf("δ�ҵ�����\n");
}

