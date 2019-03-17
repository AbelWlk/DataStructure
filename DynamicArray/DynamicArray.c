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


//测试struct
struct Person
{
	char name[64];
	int age;
};

//打印函数
void myPrintPerson(void *data)
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

//测试
void test01()
{
	//创建动态数组
	struct dynamicArray *arr = init_DynamicArray(5);

	printf("插入前容量：%d\n", arr->m_capacity);

	//准备5个元素
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

	//理论顺序 cc-ff-bb-dd-aa-ee

	//遍历动态数组
	foreach_dynamicArray(arr, myPrintPerson);
	printf("插入后容量：%d\n", arr->m_capacity);

	//删除测试
	removeByPos_DynamicArray(arr, 1);
	printf("删除后遍历:\n");
	foreach_dynamicArray(arr, myPrintPerson);
	printf("删除后后大小：%d\n", arr->m_size);

	struct Person p = { "aa",10 };
	removeByValue_DynamicArray(arr, &p, myCompara);
	printf("删除后遍历:\n");
	foreach_dynamicArray(arr, myPrintPerson);

	//销毁
	destory_DynamicArray(arr);
	arr = NULL;
}

int main()
{
	test01();
	return 0;
}