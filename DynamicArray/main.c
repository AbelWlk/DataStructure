#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DynamicArray.h"

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

	//准备6个元素
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
	system("pause");
	return 0;
}