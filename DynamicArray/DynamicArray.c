#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//��̬����ṹ��
struct dynamicArray
{
	void **pAddr;//ά���ڶ�����ʵ����ָ��
	int m_capacity;//��������
	int m_size;//�����С
};

//��ʼ������
struct dynamicArray * init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	struct dynamicArray *array = malloc(sizeof(struct dynamicArray));

	//�ж��ڴ��Ƿ�����ɹ�
	if (NULL == array)
	{
		return NULL;
	}

	//��������
	array->m_capacity = capacity;
	//���ô�С
	array->m_size = 0;
	//ά���ڶ��������ָ��
	array->pAddr = malloc(sizeof(void*)*array->m_capacity);

	return array;
}

//���빦��
insert_dynamicArray(struct dynamicArray *array, int pos, void *data)
{
	if (array == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return NULL;
	}
	if (pos<0 || pos>array->m_size)
	{
		//��Ч��λ�ã�β��
		pos = array->m_size;
	}
	//�ж��Ƿ����������˾Ͷ�̬����
	if (array->m_size >= array->m_capacity)
	{
		//����һ��������ڴ�ռ�
		int newCapacity = array->m_capacity * 2;

		//�����¿ռ�
		void **newSpace = malloc(sizeof(void *)*newCapacity);

		//ԭ�����ݿ���
		memcpy(newSpace, array->pAddr, sizeof(void *)*array->m_capacity);

		//�ͷ�ԭ�пռ�
		free(array->pAddr);

		//����ָ��ָ��
		array->pAddr = newSpace;
		array->m_capacity = newCapacity;
	}

	//����������Ԫ��
	//�����һ�����ݿ�ʼ�����κ���
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}

	//����Ԫ�ز��뵽ָ��λ��
	array->pAddr[pos] = data;

	//���´�С
	array->m_size++;

}

//��������
void foreach_dynamicArray(struct dynamicArray *array, void(*myforeach)(void *))
{
	if (array == NULL)
	{
		return;
	}
	if (myforeach == NULL)
	{
		return;
	}
	for (int i = 0; i < array->m_size; i++)
	{
		myforeach(array->pAddr[i]);
	}
}

//ɾ������Ԫ�� ����λ��
void removeByPos_DynamicArray(struct dynamicArray *arr, int pos)
{
	if (arr == NULL)
	{
		return NULL;
	}
	if (pos<0 || pos>arr->m_size - 1)
	{
		//λ����Ч
		return NULL;
	}

	//��pos��ʼ��������Ϊβ�����ݽ���Ǩ��
	for (int i = pos; i < arr->m_size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->m_size--;

}

//ɾ������Ԫ�� ����ֵ
void removeByValue_DynamicArray(struct dynamicArray *arr, void *data, int(*myCompara)(void *, void *))
{
	if (arr == NULL)
	{
		return NULL;
	}
	if (data == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < arr->m_size; i++)
	{
		if (myCompara(arr->pAddr[i], data))
		{
			removeByPos_DynamicArray(arr, i);
			break;
		}
	}
}

//��������
void destory_DynamicArray(struct dynamicArray *arr)
{
	if (arr == NULL)
	{
		return NULL;
	}
	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
		arr->pAddr = NULL;
	}
	free(arr);
	arr = NULL;
}


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

	//׼��5��Ԫ��
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
	return 0;
}