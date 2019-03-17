#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//����ڵ�
struct LinkNode
{
	void *data;//������
	struct LinkNode *next;//ָ����
};

//����ṹ��
struct LinkedList
{
	struct LinkNode pHeader;//ͷ�ڵ�
	int L_size;//������
};

//���ڲ�����������ֱ��ʹ������ṹ�������޸�����
typedef void *LinkList;

//��ʼ������
LinkList init_LinkList()
{
	struct LinkedList *myList = malloc(sizeof(struct LinkedList));
	
	if (myList == NULL)
	{
		return NULL;
	}

	//��ʼ������ṹ��
	myList->pHeader.data = NULL;
	myList->pHeader.next = NULL;
	myList->L_size = 0;

	return myList;
}

//����ڵ�
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

	//��LinkList���ͻָ�ΪLinkedList����
	struct LinkedList *myList = list;

	if (pos<0 || pos>myList->L_size)
	{
		//��Чλ�� ����β��
		pos = myList->L_size;  
	}

	//������ʱ�ڵ�
	struct LinkNode *pCurrent = &(myList->pHeader);
	
	//ͨ��ѭ���ҵ�����λ�õ�ֱ��ǰ���ڵ�
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//�����½ڵ�
	struct LinkNode *newNode = malloc(sizeof(struct LinkNode));
	newNode->data = data;

	//�½ڵ����
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;

	myList->L_size++;

}

//��������
void foreach_LinkList(LinkList list,void(*myPrint)(void *))
{
	if (list==NULL)
	{
		return NULL;
	}

	//��LinkList���ͻָ�ΪLinkedList����
	struct LinkedList *myList = list;

	//������ʱ�ڵ� ָ�������һ���ڵ㣨��ͷ�ڵ㣩
	struct LinkNode *pCurrent = myList->pHeader.next;
	
	for (int i = 0; i < myList->L_size; i++)
	{
		myPrint(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//ɾ���ڵ�
void rmoveByPos_LinkList(LinkList list, int pos)
{
	if (list==NULL)
	{
		return NULL;
	}
	
	//��LinkList���ͻָ�ΪLinkedList����
	struct LinkedList *myList = list;

	if (pos<0 || pos>myList->L_size)
	{
		//��������Χ
		return NULL;
	}

	
	//������ʱ�ڵ�ָ��ͷ�ڵ�
	struct LinkNode *pCurrent = &(myList->pHeader);

	//ͨ��ѭ���ҵ�Ҫɾ����ֱ��ǰ���ڵ�
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	//������ ��ɾ���Ľڵ�
	struct LinkNode *pDel = pCurrent->next;

	//������ϵ
	pCurrent->next = pDel->next;

	//�ͷŴ�ɾ���ڵ�
	free(pDel);
	pDel = NULL;

	//�������
	myList->L_size--;
}
//��ֵɾ���ڵ�
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

	//��LinkList���ͻָ�ΪLinkedList����
	struct LinkedList *myList = list;

	//������������ָ�����
	struct LinkNode *pPrev = &(myList->pHeader);
	struct LinkNode *pCurrent = pPrev->next;

	for (int i = 0; i < myList->L_size; i++)
	{
		//if:pCurrent->data == data
		if (myCompara(pCurrent->data, data))
		{
			//����ָ��ָ��
			pPrev->next = pCurrent->next;
			
			//�ͷ�Ҫɾ���ڵ�
			free(pCurrent);
			pCurrent = NULL;

			myList->L_size--;
			
			break;
		}

		//δ�ҵ� ָ������� ������
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}

}

//�������
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
		//�ȼ�ס��ɾ���ڵ��ֱ�Ӻ��
		struct LinkNode *pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	myList->pHeader.next = NULL;
	myList->L_size = 0;
}

//���س���
int size_LinkList(LinkList list)
{
	if (list == NULL)
	{
		return -1;
	}
	struct LinkedList *myList = list;
	return myList->L_size;
}

//��������
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






//����struct
struct Person
{
	char name[64];
	int age;
};

//��ӡ����
void myPrint(void *data)
{
	struct Person *p = data;
	printf("������%s ���䣺%d\n", p->name, p->age);
}

//�ȽϺ���
int myCompara(void *data1, void *data2)
{
struct Person *p1 = data1;
struct Person *p2 = data2;

return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void test()
{
	//��ʼ������
	LinkList list = init_LinkList();

	//��������
	//׼��6��Ԫ��
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

	//����˳�� dd-ee-bb-cc-aa-ff
	foreach_LinkList(list, myPrint);
	printf("�����ȣ�%d\n", size_LinkList(list));
	

	//ɾ���ڵ�
	rmoveByPos_LinkList(list, 4);
	printf("ɾ����\n");
	foreach_LinkList(list, myPrint);

	struct Person p = {"bb",10};
	rmoveByValue_LinkList(list, &p, myCompara);
	printf("ɾ����\n");
	foreach_LinkList(list, myPrint);

	//�������
	clear_LinkList(list);
	printf("��պ�\n");
	foreach_LinkList(list, myPrint);

	destory_LinkList(list);
}


int main()
{
	test();
	system("pause");
	return 0;
}