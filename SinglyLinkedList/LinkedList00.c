#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表节点
struct LinkNode
{
	void *data;//数据域
	struct LinkNode *next;//指针域
};

//链表结构体
struct LinkedList
{
	struct LinkNode pHeader;//头节点
	int L_size;//链表长度
};

//用于操作链表，避免直接使用链表结构体随意修改数据
typedef void *LinkList;

//初始化链表
LinkList init_LinkList()
{
	struct LinkedList *myList = malloc(sizeof(struct LinkedList));
	
	if (myList == NULL)
	{
		return NULL;
	}

	//初始化链表结构体
	myList->pHeader.data = NULL;
	myList->pHeader.next = NULL;
	myList->L_size = 0;

	return myList;
}

//插入节点
void insert_LinkList(LinkList list, int pos, void *data)
{
	if (list == NULL)
	{
		return NULL;
	}
	if (data == NULL)
	{
		return NULL;
	}

	//将LinkList类型恢复为LinkedList类型
	struct LinkedList *myList = list;

	if (pos<0 || pos>myList->L_size)
	{
		//无效位置 进行尾插
		pos = myList->L_size;  
	}

	//创建临时节点
	struct LinkNode *pCurrent = &(myList->pHeader);
	
	//通过循环找到插入位置的直接前驱节点
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//创建新节点
	struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;

	//新节点插入
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	myList->L_size++;

}

//遍历链表
void foreach_LinkList(LinkList list,void(*myPrint)(void *))
{
	if (list==NULL)
	{
		return NULL;
	}

	//将LinkList类型恢复为LinkedList类型
	struct LinkedList *myList = list;

	//创建临时节点 指向链表第一个节点（非头节点）
	struct LinkNode *pCurrent = myList->pHeader.next;
	
	for (int i = 0; i < myList->L_size; i++)
	{
		myPrint(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//删除节点
void rmoveByPos_LinkList(LinkList list, int pos)
{
	if (list==NULL)
	{
		return NULL;
	}
	
	//将LinkList类型恢复为LinkedList类型
	struct LinkedList *myList = list;

	if (pos<0 || pos>myList->L_size)
	{
		//不在链表范围
		return NULL;
	}

	
	//创建临时节点指向头节点
	struct LinkNode *pCurrent = &(myList->pHeader);

	//通过循环找到要删除的直接前驱节点
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//缓存中 待删除的节点
	struct LinkNode *pDel = pCurrent->next;

	//建立关系
	pCurrent->next = pDel->next;

	//释放待删除节点
	free(pDel);
	pDel = NULL;

	//变更长度
	myList->L_size--;
}
//按值删除节点
void rmoveByValue_LinkList(LinkList list, void *data,int(*myCompara)(void *,void *))
{
	if (list==NULL)
	{
		return NULL;
	}
	if (data== NULL)
	{
		return NULL;
	}

	//将LinkList类型恢复为LinkedList类型
	struct LinkedList *myList = list;

	//创建两个辅助指针变量
	struct LinkNode *pPrev = &(myList->pHeader);
	struct LinkNode *pCurrent = pPrev->next;

	for (int i = 0; i < myList->L_size; i++)
	{
		//if:pCurrent->data == data
		if (myCompara(pCurrent->data, data))
		{
			//更改指针指向
			pPrev->next = pCurrent->next;
			
			//释放要删除节点
			free(pCurrent);
			pCurrent = NULL;

			myList->L_size--;
			
			break;
		}

		//未找到 指针向后移 继续找
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

}

//清空链表
void clear_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return NULL;
	}
	struct LinkedList *myList = list;
	struct LinkNode *pCurrent = myList->pHeader.next;

	for (int i = 0; i < myList->L_size; i++)
	{
		//先记住待删除节点的直接后继
		struct LinkNode *pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	myList->pHeader.next = NULL;
	myList->L_size = 0;
}

//返回长度
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}
	struct LinkedList *myList = list;
	return myList->L_size;
}

//销毁链表
void destory_LinkList(LinkList list)
{
	if (list==NULL)
	{
		return NULL;
	}
	clear_LinkList(list);
	free(list);
	list = NULL;
}






//测试struct
struct Person
{
	char name[64];
	int age;
};

//打印函数
void myPrint(void *data)
{
	struct Person *p = data;
	printf("姓名：%s 年龄：%d\n", p->name, p->age);
}

//比较函数
int myCompara(void *data1, void *data2)
{
struct Person *p1 = data1;
struct Person *p2 = data2;

return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test()
{
	//初始化链表
	LinkList list = init_LinkList();

	//插入数据
	//准备6个元素
	struct Person p1 = { "aa",10 };
	struct Person p2 = { "bb",10 };
	struct Person p3 = { "cc",10 };
	struct Person p4 = { "dd",10 };
	struct Person p5 = { "ee",10 };
	struct Person p6 = { "ff",10 };

	insert_LinkList(list,0,&p1);
	insert_LinkList(list, 0, &p2);
	insert_LinkList(list, 1, &p3);
	insert_LinkList(list, 0, &p4);
	insert_LinkList(list, 1, &p5);
	insert_LinkList(list, 10, &p6);

	//理论顺序 dd-ee-bb-cc-aa-ff
	foreach_LinkList(list, myPrint);
	printf("链表长度：%d\n", size_LinkList(list));
	

	//删除节点
	rmoveByPos_LinkList(list, 4);
	printf("删除后：\n");
	foreach_LinkList(list, myPrint);

	struct Person p = {"bb",10};
	rmoveByValue_LinkList(list, &p, myCompara);
	printf("删除后：\n");
	foreach_LinkList(list, myPrint);

	//清空链表
	clear_LinkList(list);
	printf("清空后：\n");
	foreach_LinkList(list, myPrint);

	destory_LinkList(list);
}


int main()
{
	test();
	system("pause");
	return 0;
}