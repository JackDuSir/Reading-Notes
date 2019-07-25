/*************************************************************************
	> File Name: my_struct.cpp
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2018年03月12日 星期一 14时33分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include<cstring>

void printBook(struct Books *book);

// 声明一个结构体类型 Books
struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int  book_id;
};

int main()
{
	Books Book1;		// 定义结构体类型 Books 的变量 Book1
	Books Book2;

	// Book1 详述
	strcpy(Book1.title, "C++ 教程");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "编程语言");
	Book1.book_id = 12345;

	// Book2 详述
	strcpy(Book2.title, "CSS 教程");
	strcpy(Book2.author, "Runoob");
	strcpy(Book2.subject, "前段技术");
	Book2.book_id = 12346;

	printBook(&Book1);
	
	printBook(&Book2);

	return 0;
}

void printBook(struct Books *book)
{
	cout << "书标题：" << book->title << endl;
	cout << "书作者：" << book->author << endl;
	cout << "书类别：" << book->subject << endl;
	cout << "书 ID：" << book->book_id << endl;
}

