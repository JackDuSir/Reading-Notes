/*************************************************************************
	> File Name: MyArray.h
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月28日 星期四 11时39分44秒
 ************************************************************************/
#pragma once
#ifndef __MYARRAY_H__
#define __MYARRAY_H__
#include<iostream>

template<class T>
class MyArray {
public:
	explicit MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		// 如果T是对象，那么这个对象必须提供默认的构造函数
		pAddress = new T[this->m_Capacity];
	}

	// 拷贝构造
	MyArray(const MyArray &arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		int i = 0;
		for (i; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	// 重载 [] 操作符 arr[0]
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	// 尾插法
	void Push_back(const T& val)
	{
		if (this->m_Capacity == this->m_Size)
			return;

		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	void Pop_back()
	{
		if (this->m_Size == 0)
			return;
		this->m_Size--;
	}

	int getSize()
	{
		return this->m_Size;
	}

	// 析构
	~MyArray()
	{
		if (this->pAddress)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
private:
	T *pAddress;	// 指向一个堆空间，这个空间存储真正的数据
	int m_Capacity;	// 容量
	int m_Size;		// 大小
};

#endif
