#include"linklist.h"




void test01()
{
	int i = 0;
	node *phead1 = NULL;
	node *phead2 = NULL;
//	phead2 = addback(phead2, 1);
//	phead2 = addback(phead2, 3);
//	phead2 = addback(phead2, 5);
//	phead2 = addback(phead2, 7);
	phead1 = addback(phead1, 2);
	phead1 = addback(phead1, 4);
	phead1 = addback(phead1, 6);
	phead1 = addback(phead1, 8);
	showlinklist(phead1);
//	mergelinklist(phead1, phead2);

	
	node *pp3 = middlenode(phead1);
	printf("%d %p %p\n", pp3->data, pp3, pp3->next);
	//i = guiallnode(phead1);

	//printf("i=%d\n", i);

}




int main()
{
//node *phead1 = NULL;
//phead1 = addback(phead1, 11);
//phead1 = addback(phead1, 12);
//phead1 = addback(phead1, 13);
//phead1 = addback(phead1, 14);
//phead1 = addback(phead1, 15);
//printf("-------------------\n");
//showlinklist(phead1);
//phead1 = alter(phead1, 17, 666);//在outdat后插入数据
//printf("-------------------\n");
//showlinklist(phead1);
//phead1 = delete(phead1, 666);
//printf("-------------------\n");
//showlinklist(phead1);
//phead1 = rev(phead1);
//printf("-------------------\n");
//showlinklist(phead1);
	test01();
	system("pause");
}