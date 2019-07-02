#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//动态数组结构体
struct dynamicArray
{
	void **pAddr;//维护在堆区真实数组指针
	int m_capacity;//数组容量
	int m_size;//数组大小
};

//初始化数组
struct dynamicArray * init_DynamicArray(int capacity);

//插入功能
void insert_dynamicArray(struct dynamicArray *array, int pos, void *data);

//遍历数组
void foreach_dynamicArray(struct dynamicArray *array, void(*myforeach)(void *));

//删除数组元素 按照位置
void removeByPos_DynamicArray(struct dynamicArray *arr, int pos);

//删除数组元素 按照值
void removeByValue_DynamicArray(struct dynamicArray *arr, void *data, int(*myCompara)(void *, void *));

//销毁数组
void destory_DynamicArray(struct dynamicArray *arr);