#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	��������-��ҵ���汾
	01.��� ֻά��ָ���򣬲�ά��������
	02.�û�������ҪԤ��4���ֽڿռ䣬���ײ�������next��ַ��
	03.������LinkedList�ṩ����ӿ�LinkList
	������	����	����	ɾ��	����
*/

//�ڵ�
struct LinkNode
{
	//ֻά��ָ����
	struct LinkNode *next;
};

//����
struct LinkedList
{
	struct LinkNode pHeader;//ͷ�ڵ�
	int L_Size;//������
};

typedef void *LinkList;

//��ʼ������
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

//��������
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

	//���û������� ǰ4���ֽ�תΪLinkNode����
	struct LinkNode *myNode = data;

	//�ҵ��������ݵ�ǰ���ڵ�
	struct LinkNode *pCurrent = &(myList->pHeader);
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//����ָ��ָ��
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	myList->L_Size++;
}

//��������
void foreach_LinkList(LinkList list,void(*printPerson)(void *))
{
	if (list == NULL)
	{
		return NULL;
	}

	struct LinkedList *myList = list;

	//ָ���һ���ڵ㣨��ͷ�ڵ㣩
	struct LinkNode *node = myList->pHeader.next;

	for (int i = 0; i < myList->L_Size; i++)
	{
		printPerson(node);
		node = node->next;
	}
}

//ɾ������ ��λ��
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

	//�ҵ�ɾ��λ��ǰ���ڵ�
	struct LinkNode *pCurrent = &(myList->pHeader);

	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//��¼��ɾ���ڵ�
	struct LinkNode *pDel = pCurrent->next;

	//����ָ��ķ���
	pCurrent->next = pDel->next;

	//free(pDel);//������������ά����ȫ�������û�
	
	//���³���
	myList->L_Size--;

}
//��������
void destory_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return NULL;
	}
	free(list);
	list = NULL;
}



//����
struct Person
{
	struct LinkNode node;//Լ���õ�ǰ�ĸ��ֽڣ��൱��ռ��λ
	char name[64];
	int age;
};

//��ӡ
void printPerson(void *data)
{
	struct Person *p = data;
	printf("������%s ���䣺%d\n", p->name, p->age);
}

void test()
{
	//��ʼ��
	LinkList myList = init_LinkList();

	//׼������
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

	//����˳�� cc-dd-bb-aa-ee
	//����
	foreach_LinkList(myList, printPerson);

	//ɾ��
	removeByPos_LinkList(myList, 2);
	printf("ɾ��һ����\n");
	foreach_LinkList(myList, printPerson);

	destory_LinkList(myList);
	printf("���ٺ�\n");
	foreach_LinkList(myList, printPerson);
}



int main()
{
	test();
	system("pause");
	return 0;
}