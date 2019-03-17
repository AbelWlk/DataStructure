#include "DynamicArray.h"

//初始化数组
struct dynamicArray * init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	struct dynamicArray *array = malloc(sizeof(struct dynamicArray));

	//判断内存是否申请成功
	if (NULL == array)
	{
		return NULL;
	}

	//设置容量
	array->m_capacity = capacity;
	//设置大小
	array->m_size = 0;
	//维护在堆区数组的指针
	array->pAddr = malloc(sizeof(void*)*array->m_capacity);

	return array;
}

//插入功能
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
		//无效的位置，尾插
		pos = array->m_size;
	}
	//判断是否已满，满了就动态开辟
	if (array->m_size >= array->m_capacity)
	{
		//申请一个更大的内存空间
		int newCapacity = array->m_capacity * 2;

		//创建新空间
		void **newSpace = malloc(sizeof(void *)*newCapacity);

		//原有数据拷贝
		memcpy(newSpace, array->pAddr, sizeof(void *)*array->m_capacity);

		//释放原有空间
		free(array->pAddr);

		//更改指针指向
		array->pAddr = newSpace;
		array->m_capacity = newCapacity;
	}

	//插入新数据元素
	//从最后一个数据开始，依次后移
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->pAddr[i + 1] = array->pAddr[i];
	}

	//将新元素插入到指定位置
	array->pAddr[pos] = data;

	//更新大小
	array->m_size++;

}

//遍历数组
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

//删除数组元素 按照位置
void removeByPos_DynamicArray(struct dynamicArray *arr, int pos)
{
	if (arr == NULL)
	{
		return NULL;
	}
	if (pos<0 || pos>arr->m_size - 1)
	{
		//位置无效
		return NULL;
	}

	//从pos开始，到数组为尾，数据进行迁移
	for (int i = pos; i < arr->m_size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}
	arr->m_size--;

}

//删除数组元素 按照值
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

//销毁数组
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


