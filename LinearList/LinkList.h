// Created by wlk on 2019/7/8 21:12.

#ifndef DATASTRUCTURE_LINKLIST_H
#define DATASTRUCTURE_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode{
    int Data;
    struct LNode *Next;
}LNode,*PtrNode;

struct LinkNode{
    PtrNode Head,Tail;
    int Length;
};
typedef struct LinkNode *LinkList;

void Init_LinkList(LinkList *linkList);

void HeadInsert(LinkList linkList,int data);

void TailInsert(LinkList linkList,int data);

LNode *GetElem(LinkList L, int index);

LNode *LocateElem(LinkList linkList,int value);

bool InsertByIndex(LinkList linkList,int index,int data);

bool DeleteByIndex(LinkList linkList,int index);

int Length(LinkList linkList);

#endif //DATASTRUCTURE_LINKLIST_H
