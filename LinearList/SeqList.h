// Created by wlk on 2019/7/2 18:50.

#ifndef DATASTRUCTURE_SEQLIST_H
#define DATASTRUCTURE_SEQLIST_H
#define InitSize 100

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void **Data;
    int MaxSize, Size;
} SeqList;

/*初始化顺序表*/
void InitList(SeqList *seqList);
/*判断是否为空*/
bool IsEmpty(SeqList seqList);

/*获取顺序表当前长度*/
int Length(SeqList seqList);

/*获取指定元素位置*/
int LocateElem(SeqList seqList, void *data);

/*根据位置查找指定元素*/
void *GetElem(SeqList seqList, int position);

/*在之地个位置插入元素*/
bool ListInsert(SeqList *seqList, int position, void *data);

/*删除指定位置元素*/
void *ListDelete(SeqList *seqList, int position);

/*遍历打印顺序表*/
void PrintLsit(SeqList seqList, void(*myPrint)(void *));

/*销毁顺序表*/
void Destory(SeqList *seqList);


#endif //DATASTRUCTURE_SEQLIST_H
