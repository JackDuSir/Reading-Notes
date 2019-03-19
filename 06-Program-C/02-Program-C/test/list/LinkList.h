/*************************************************************************
	> File Name: LinkList.h
	> Author: Maxwell
	> Mail: miaopei163@163.com 
	> Created Time: 2019年03月19日 星期二 11时20分14秒
 ************************************************************************/
// 指定在创建过程中该编译指示所在的文件仅仅被编译程序包含（打开）一次
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	// 定义节点数据类型
	struct LinkNode {
		int data;
		struct LinkNode *next;
	};

	// 初始化链表
	struct LinkNode *Init_LinkList();

	// 在值为oldval的后面插入一个新的数据newval
	void InsertByValue_LinkList(struct LinkNode *header, int oldval, int newval);

	// 删除值为val的节点
	void RemoveByValue_LinkList(struct LinkNode *header, int delValue);

	// 遍历
	void Foreach_LinkList(struct LinkNode *header);

	// 销毁
	void Destroy_LinkList(struct LinkNode *header);

	// 清空
	void Clear_LinkList(struct LinkNode *header);

#ifdef __cplusplus
}
#endif
