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

/*��ʼ��˳���*/
void InitList(SeqList *seqList);
/*�ж��Ƿ�Ϊ��*/
bool IsEmpty(SeqList seqList);

/*��ȡ˳���ǰ����*/
int Length(SeqList seqList);

/*��ȡָ��Ԫ��λ��*/
int LocateElem(SeqList seqList, void *data);

/*����λ�ò���ָ��Ԫ��*/
void *GetElem(SeqList seqList, int position);

/*��֮�ظ�λ�ò���Ԫ��*/
bool ListInsert(SeqList *seqList, int position, void *data);

/*ɾ��ָ��λ��Ԫ��*/
void *ListDelete(SeqList *seqList, int position);

/*������ӡ˳���*/
void PrintLsit(SeqList seqList, void(*myPrint)(void *));

/*����˳���*/
void Destory(SeqList *seqList);


#endif //DATASTRUCTURE_SEQLIST_H
