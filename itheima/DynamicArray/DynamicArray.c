#include "DynamicArray.h"

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
void insert_dynamicArray(struct dynamicArray *array, int pos, void *data)
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


