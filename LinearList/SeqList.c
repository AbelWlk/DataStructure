// Created by wlk on 2019/7/2 18:50.

#include "SeqList.h"

/*初始化顺序表*/
void InitList(SeqList *seqList) {
    seqList->Data = malloc(sizeof(void *) * InitSize);
    seqList->MaxSize = InitSize;
    seqList->Size = 0;
}
/*判断是否为空*/
bool IsEmpty(SeqList seqList) {
    if (seqList.Size == 0)
        return true;
    return false;
}

/*获取顺序表当前长度*/
int Length(SeqList seqList) {
    return seqList.Size;
}

/*获取指定元素位置*/
int LocateElem(SeqList seqList, void *data,bool(*myCompara)(void *,void *)) {
    for (int i = 0; i < seqList.Size; i++) {
        if (myCompara(data,seqList.Data[i])) {
            return i + 1;
            break;
        }
    }
    return -1;
}

/*根据位置查找指定元素*/
void *GetElem(SeqList seqList, int position) {

    if (position < 1 || position > seqList.Size) {
        return NULL;
    }
    return seqList.Data[position - 1];
}
/*在之地个位置插入元素*/
bool ListInsert(SeqList *seqList, int position, void *data) {
    if (position < 1 || position > seqList->Size + 1)
        return false;
    if (seqList->Size >= seqList->MaxSize)
        return false;
    for (int i = seqList->Size; i >= position; i--) {
        seqList->Data[i] = seqList->Data[i - 1];
    }
    seqList->Data[position - 1] = data;
    seqList->Size++;
    return true;

}

/*删除指定位置元素*/
void *ListDelete(SeqList *seqList, int position) {
    if (position < 1 || position > seqList->Size)
        return false;
    void *data = seqList->Data[position - 1];
    for (int i = position; i < seqList->Size; i++) {
        seqList->Data[i - 1] = seqList->Data[i];
    }
    seqList->Size--;
    return data;
}

/*遍历打印顺序表*/
void PrintLsit(SeqList seqList, void(*myPrint)(void *)) {

    for (int i = 0; i < seqList.Size; i++) {
        myPrint(seqList.Data[i]);
    }

}

/*销毁顺序表*/
void Destory(SeqList *seqList) {
    if (seqList->Data != NULL) {
        free(seqList->Data);
        seqList->Data = NULL;
    }
    free(seqList);
    seqList = NULL;
}