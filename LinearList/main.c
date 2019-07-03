// Created by wlk on 2019/7/3 21:57.
#include "LinearList/SeqList.h"
#include <string.h>

typedef struct Per {
    int age;
    char name[10];
} P;

void myPrint(void *m) {
    P *p = (P *) m;
    printf("%d--%s\n", p->age, p->name);
}

bool myCompara(void *a,void *b)
{
    P *p1=a;
    P *p2=b;
    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}


int main() {

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

    ListDelete(&list,3);
    printf("%d\n", Length(list));
    PrintLsit(list, myPrint);

    printf("%d\n",LocateElem(list,&p3,myCompara));

    P *p=GetElem(list,2);
    printf("%d--%s\n", p->age, p->name);

    if (IsEmpty(list)!=true)
    {
        printf("not null");
    }
    Destory(&list);

    return 0;
}