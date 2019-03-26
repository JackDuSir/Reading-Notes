/*************************************************************************
	> File Name: MyArray.h
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月26日 星期二 15时44分59秒
 ************************************************************************/

#ifndef __MYARRAY_H__
#define __MYARRAY_H__

class MyArray{
public:
	// 无参构造函数，用户没有指定容量，则初始化为 100
	MyArray();
	// 有参构造函数，用户指定容量初始化
	explicit MyArray(int capacity);

	// 用户操作接口
	// 更具位置添加元素
	void SetData(int pos, int val);

	// 获得指定位置元素
	int GetData(int pos);

	//尾插法
	void PushBack(int val);

	// 获得长度
	int GetLength();

	// 析构函数，释放数组空间
	~MyArray();
private:
	int mCapacity;	// 数组一共可以容纳多少个元素
	int mSize;		// 当前有多少个元素
	int *pAdress;	// 指向存储数据的空间
};

#endif 
