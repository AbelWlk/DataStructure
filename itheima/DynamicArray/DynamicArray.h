#pragma once
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
struct dynamicArray * init_DynamicArray(int capacity);

//���빦��
void insert_dynamicArray(struct dynamicArray *array, int pos, void *data);

//��������
void foreach_dynamicArray(struct dynamicArray *array, void(*myforeach)(void *));

//ɾ������Ԫ�� ����λ��
void removeByPos_DynamicArray(struct dynamicArray *arr, int pos);

//ɾ������Ԫ�� ����ֵ
void removeByValue_DynamicArray(struct dynamicArray *arr, void *data, int(*myCompara)(void *, void *));

//��������
void destory_DynamicArray(struct dynamicArray *arr);