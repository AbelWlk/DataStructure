#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

//����struct
struct Person
{
	char name[64];
	int age;
};

//��ӡ����
void myPrintPerson(void *data)
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

//����
void test01()
{
	//������̬����
	struct dynamicArray *arr = init_DynamicArray(5);

	printf("����ǰ������%d\n", arr->m_capacity);

	//׼��6��Ԫ��
	struct Person p1 = { "aa",10 };
	struct Person p2 = { "bb",10 };
	struct Person p3 = { "cc",10 };
	struct Person p4 = { "dd",10 };
	struct Person p5 = { "ee",10 };
	struct Person p6 = { "ff",10 };

	insert_dynamicArray(arr, 0, &p1);
	insert_dynamicArray(arr, 0, &p2);
	insert_dynamicArray(arr, 0, &p3);
	insert_dynamicArray(arr, 2, &p4);
	insert_dynamicArray(arr, 10, &p5);
	insert_dynamicArray(arr, 1, &p6);

	//����˳�� cc-ff-bb-dd-aa-ee

	//������̬����
	foreach_dynamicArray(arr, myPrintPerson);
	printf("�����������%d\n", arr->m_capacity);

	//ɾ������
	removeByPos_DynamicArray(arr, 1);
	printf("ɾ�������:\n");
	foreach_dynamicArray(arr, myPrintPerson);
	printf("ɾ������С��%d\n", arr->m_size);

	struct Person p = { "aa",10 };
	removeByValue_DynamicArray(arr, &p, myCompara);
	printf("ɾ�������:\n");
	foreach_dynamicArray(arr, myPrintPerson);

	//����
	destory_DynamicArray(arr);
	arr = NULL;
}

int main()
{
	test01();
	system("pause");
	return 0;
}