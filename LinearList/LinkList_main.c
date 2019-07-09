// Created by wlk on 2019/7/9 21:05.
#include "LinkList.h"

//01.删除不带头节点的单链表L中所有值为x的节点
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

//带头节点删除所有x节点
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

//反向输出每个节点值
void Re_Print(PtrNode p){
    if (p->Next!=NULL)
        Re_Print(p->Next);
    printf("%d\n",p->Data);
}

//删除最小节点
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

//带头节点单链表 逆置
//摘下头节点，剩下的按顺序头插法到L后面
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

//摘下头节点，将剩下的依次反转，最后头节点指向反转后的链表
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