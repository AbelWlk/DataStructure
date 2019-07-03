// Created by wlk on 2019/7/2 18:50.

#include "SeqList.h"

/*��ʼ��˳���*/
void InitList(SeqList *seqList) {
    seqList->Data = malloc(sizeof(void *) * InitSize);
    seqList->MaxSize = InitSize;
    seqList->Size = 0;
}
/*�ж��Ƿ�Ϊ��*/
bool IsEmpty(SeqList seqList) {
    if (seqList.Size == 0)
        return true;
    return false;
}

/*��ȡ˳���ǰ����*/
int Length(SeqList seqList) {
    return seqList.Size;
}

/*��ȡָ��Ԫ��λ��*/
int LocateElem(SeqList seqList, void *data,bool(*myCompara)(void *,void *)) {
    for (int i = 0; i < seqList.Size; i++) {
        if (myCompara(data,seqList.Data[i])) {
            return i + 1;
            break;
        }
    }
    return -1;
}

/*����λ�ò���ָ��Ԫ��*/
void *GetElem(SeqList seqList, int position) {

    if (position < 1 || position > seqList.Size) {
        return NULL;
    }
    return seqList.Data[position - 1];
}
/*��֮�ظ�λ�ò���Ԫ��*/
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

/*ɾ��ָ��λ��Ԫ��*/
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

/*������ӡ˳���*/
void PrintLsit(SeqList seqList, void(*myPrint)(void *)) {

    for (int i = 0; i < seqList.Size; i++) {
        myPrint(seqList.Data[i]);
    }

}

/*����˳���*/
void Destory(SeqList *seqList) {
    if (seqList->Data != NULL) {
        free(seqList->Data);
        seqList->Data = NULL;
    }
    free(seqList);
    seqList = NULL;
}