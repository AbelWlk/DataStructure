// Created by wlk on 2019/7/9 21:05.
#include "LinkList.h"

//01.ɾ������ͷ�ڵ�ĵ�����L������ֵΪx�Ľڵ�
void Del_X(PtrNode L,int x) {
    PtrNode p;
    if(L==NULL)
        return;
    if(L->Data==x)
    {
        p=L;
        L=L->Next;
        free(p);
        Del_X(L,x);
    } else{
        Del_X(L->Next,x);
    }
}

//��ͷ�ڵ�ɾ������x�ڵ�
void Del_X_1(LinkList linkList,int x){
    PtrNode pre=linkList->Head;
    PtrNode p=pre->Next;
    while (p!=NULL)
    {
        if(p->Data==x)
        {
            PtrNode q=p;
            p=p->Next;
            pre->Next=p;
            free(q);
        } else{
            pre=p;
            p=p->Next;
        }
    }
}

//�������ÿ���ڵ�ֵ
void Re_Print(PtrNode p){
    if (p->Next!=NULL)
        Re_Print(p->Next);
    printf("%d\n",p->Data);
}

//ɾ����С�ڵ�
void Del_Min(LinkList linkList){
    PtrNode pre=linkList->Head,p=pre->Next;
    PtrNode minpre=pre,minp=p;
    while (p!=NULL)
    {
        if(p->Data<minp->Data)
        {
            minp=p;
            minpre=pre;
        }
        pre=p;
        p=p->Next;
    }
    minpre->Next=minp->Next;
    free(minp);
}

//��ͷ�ڵ㵥���� ����
//ժ��ͷ�ڵ㣬ʣ�µİ�˳��ͷ�巨��L����
void Reverse1(LinkList linkList){
    PtrNode p,r;
    p=linkList->Head->Next;
    linkList->Head->Next=NULL;
    while (p!=NULL)
    {
        r=p->Next;
        p->Next=linkList->Head->Next;
        linkList->Head->Next=p;
        p=r;
    }
}

//ժ��ͷ�ڵ㣬��ʣ�µ����η�ת�����ͷ�ڵ�ָ��ת�������
void Reverse2(LinkList linkList){
    PtrNode pre,p=linkList->Head->Next,r=p->Next;
    p->Next=NULL;
    while (r!=NULL){
        pre=p;
        p=r;
        r=r->Next;
        p->Next=pre;
    }
    linkList->Head->Next=p;
}

int main() {

    LinkList linkList;
    Init_LinkList(&linkList);
    HeadInsert(linkList, 10);
    HeadInsert(linkList, 11);
    TailInsert(linkList, 9);
    TailInsert(linkList, 11);
    TailInsert(linkList, 8);
    TailInsert(linkList, 11);

//    PtrNode p = GetElem(linkList, 1);
//    p = LocateElem(linkList, 9);
//
//    InsertByIndex(linkList, 2, 12);
//
//    DeleteByIndex(linkList, 2);

    Re_Print(linkList->Head);
    return 0;
}