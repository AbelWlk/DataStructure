// Created by wlk on 2019/7/3 21:57.
#include "LinearList/SeqList.h"
#include <string.h>

typedef struct Per {
    int age;
    char name[10];
} P;

//自定义打印函数
void myPrint(void *m) {
    P *p = (P *) m;
    printf("%d--%s\n", p->age, p->name);
}

void print(void *a) {
    printf("%d\n", *((int *) a));
}

//自定义比较函数
bool myCompare(void *a, void *b) {
    P *p1 = a;
    P *p2 = b;
    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

//功能测试
void test() {
    SeqList list;
    InitList(&list);

    P p0 = {10, "aa"};
    P p1 = {11, "bb"};
    P p2 = {12, "cc"};
    P p3 = {13, "dd"};


    ListInsert(&list, 1, &p0);
    ListInsert(&list, 2, &p1);
    ListInsert(&list, 3, &p2);
    ListInsert(&list, 4, &p3);

    printf("%d\n", Length(list));
    PrintLsit(list, myPrint);

    ListDelete(&list, 3);
    printf("%d\n", Length(list));
    PrintLsit(list, myPrint);

    printf("%d\n", LocateElem(list, &p3, myCompare));

    P *p = GetElem(list, 2);
    printf("%d--%s\n", p->age, p->name);

    if (IsEmpty(list) != true) {
        printf("not null");
    }
    Destroy(&list);
}

//删除最小值元素
bool Del_Min(SeqList *seqList, const int *value) {
    if (Length(*seqList) == 0)
        return false;

    value = seqList->Data[0];//假定0号最小
    int pos = 0;

    for (int i = 1; i < seqList->Size; i++) {
        if (*((int *) (seqList->Data[i])) < *value) {
            value = seqList->Data[i];
            pos = i;
        }
    }
    seqList->Data[pos] = seqList->Data[seqList->Size - 1];
    seqList->Size--;
    return true;
}

//逆置所有元素
void Reverse(SeqList *seqList) {

    void *tmp;
    for (int i = 0; i < seqList->Size / 2; ++i) {
        tmp = seqList->Data[i];
        seqList->Data[i] = seqList->Data[seqList->Size - i - 1];
        seqList->Data[seqList->Size - i - 1] = tmp;
    }
}

//删除所有值为为x元素
void DeleteByValue(SeqList *seqList, int x) {
    int k = 0;//k用于记录所有不等于x的值的元素
    for (int i = 0; i < seqList->Size; ++i) {
        if (*((int *) seqList->Data[i]) != x) {
            seqList->Data[k] = seqList->Data[i];
            k++;
        }
    }
    seqList->Size = k;
}


int main() {
    SeqList seqList;
    InitList(&seqList);
    int a = 10, b = 5, c = 6, d = 7, e = 9;
    ListInsert(&seqList, 1, &a);
    ListInsert(&seqList, 2, &b);
    ListInsert(&seqList, 3, &c);
    ListInsert(&seqList, 4, &d);
    ListInsert(&seqList, 5, &e);
    PrintLsit(seqList, print);

    DeleteByValue(&seqList,7);

    PrintLsit(seqList, print);

    return 0;
}