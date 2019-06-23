#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	单向链表-企业级版本
	01.结点 只维护指针域，不维护数据域
	02.用户数据需要预留4个字节空间，给底层链表存放next地址用
	03.对链表LinkedList提供对外接口LinkList
	操作：	插入	遍历	删除	销毁
*/

//节点
struct LinkNode
{
	//只维护指针域
	struct LinkNode *next;
};

//链表
struct LinkedList
{
	struct LinkNode pHeader;//头节点
	int L_Size;//链表长度
};

typedef void *LinkList;

//初始化链表
LinkList init_LinkList()
{
	struct LinkedList *myList = malloc(sizeof(struct LinkedList));
	
	if (myList == NULL)
	{
		return NULL;
	}

	myList->pHeader.next = NULL;
	
	myList->L_Size = 0;
	
	return myList;
}

//插入链表
void insert_LinkList(LinkList list,int pos,void *data)
{
	if (list == NULL)
	{
		return NULL;
	}
	if (data == NULL)
	{
		return NULL;
	}

	struct LinkedList *myList = list;
	
	if (pos<0 || pos>myList->L_Size - 1)
	{
		pos = myList->L_Size;
	}

	//将用户的数据 前4个字节转为LinkNode类型
	struct LinkNode *myNode = data;

	//找到插入数据的前驱节点
	struct LinkNode *pCurrent = &(myList->pHeader);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//更改指针指向
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	myList->L_Size++;
}

//遍历链表
void foreach_LinkList(LinkList list,void(*printPerson)(void *))
{
	if (list == NULL)
	{
		return NULL;
	}

	struct LinkedList *myList = list;

	//指向第一个节点（非头节点）
	struct LinkNode *node = myList->pHeader.next;

	for (int i = 0; i < myList->L_Size; i++)
	{
		printPerson(node);
		node = node->next;
	}
}

//删除链表 按位置
void removeByPos_LinkList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return NULL;
	}
	
	struct LinkedList *myList = list;
	
	if (pos<0 || pos>myList->L_Size-1)
	{
		return 0;
	}

	//找到删除位置前驱节点
	struct LinkNode *pCurrent = &(myList->pHeader);

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//记录待删除节点
	struct LinkNode *pDel = pCurrent->next;

	//更改指针的方向
	pCurrent->next = pDel->next;

	//free(pDel);//数据域不由链表维护，全部交给用户
	
	//更新长度
	myList->L_Size--;

}
//销毁链表
void destory_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return NULL;
	}
	free(list);
	list = NULL;
}



//测试
struct Person
{
	struct LinkNode node;//约定好的前四个字节，相当于占个位
	char name[64];
	int age;
};

//打印
void printPerson(void *data)
{
	struct Person *p = data;
	printf("姓名：%s 年龄：%d\n", p->name, p->age);
}

void test()
{
	//初始化
	LinkList myList = init_LinkList();

	//准备数据
	struct Person p1 = {NULL,"aa",10};
	struct Person p2 = { NULL,"bb",10 };
	struct Person p3 = { NULL,"cc",10 };
	struct Person p4 = { NULL,"dd",10 };
	struct Person p5 = { NULL,"ee",10 };

	insert_LinkList(myList, 0,&p1);
	insert_LinkList(myList, 0, &p2);
	insert_LinkList(myList, 0, &p3);
	insert_LinkList(myList, 1, &p4);
	insert_LinkList(myList, 10, &p5);

	//理论顺序 cc-dd-bb-aa-ee
	//遍历
	foreach_LinkList(myList, printPerson);

	//删除
	removeByPos_LinkList(myList, 2);
	printf("删除一个后：\n");
	foreach_LinkList(myList, printPerson);

	destory_LinkList(myList);
	printf("销毁后：\n");
	foreach_LinkList(myList, printPerson);
}



int main()
{
	test();
	system("pause");
	return 0;
}