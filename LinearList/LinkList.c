// Created by wlk on 2019/7/8 21:12.

#include <stdio.h>
#include "LinkList.h"

void Init_LinkList(LinkList *linkList) {
    *linkList = malloc(sizeof(struct LinkNode));
    (*linkList)->Head = NULL;
    (*linkList)->Tail = NULL;
    (*linkList)->Length = 0;
}

void HeadInsert(LinkList linkList, int data) {
    LNode *s = malloc(sizeof(LNode));
    s->Data = data;
    s->Next = NULL;
    if (linkList->Length == 0) {
        linkList->Head = linkList->Tail = s;
    } else {
        s->Next = linkList->Head;
        linkList->Head = s;
    }
    linkList->Length++;
}

void TailInsert(LinkList linkList, int data) {
    LNode *s = malloc(sizeof(LNode));
    s->Data = data;
    s->Next = NULL;
    if (linkList->Length == 0) {
        linkList->Head = linkList->Tail = s;
    } else {
        linkList->Tail->Next=s;
        linkList->Tail=s;
    }
    linkList->Length++;
}

LNode *GetElem(LinkList linkList, int index) {
    int i = 1;
    LNode *p = linkList->Head;
    if (index == 0)
        return linkList->Head;
    if (index < 1)
        return NULL;
    while (p && i < index) {
        p = p->Next;
        i++;
    }
    return p;
}

LNode *LocateElem(LinkList linkList, int value) {
    LNode *p = linkList->Head;
    while (p && p->Data != value)
        p = p->Next;
    return p;
}

bool InsertByIndex(LinkList linkList, int index, int data) {
    if (index < 1 || index > linkList->Length + 1)
        return false;
    LNode *p = GetElem(linkList, index - 1);
    LNode *s = malloc(sizeof(LNode));
    s->Data = data;
    s->Next = p->Next;
    p->Next = s;
    linkList->Length++;
    return true;
}

bool DeleteByIndex(LinkList linkList, int index) {
    if (index < 1 || index > linkList->Length + 1)
        return false;
    LNode *p = GetElem(linkList, index - 1);
    LNode *q = p->Next;
    p->Next = q->Next;
    free(q);
    linkList->Length--;
    return true;
}

int Length(LinkList linkList){
    return linkList->Length;
}