// Created by wlk on 2019/7/9 21:05.
#include "LinkList.h"

//01.删除不带头节点的单链表L中所有值为x的节点
void Del_X(PtrNode L, int x) {
    PtrNode p;
    if (L == NULL)
        return;
    if (L->Data == x) {
        p = L;
        L = L->Next;
        free(p);
        Del_X(L, x);
    } else {
        Del_X(L->Next, x);
    }
}

//02.带头节点删除所有x节点
void Del_X_1(LinkList linkList, int x) {
    PtrNode pre = linkList->Head;
    PtrNode p = pre->Next;
    while (p != NULL) {
        if (p->Data == x) {
            PtrNode q = p;
            p = p->Next;
            pre->Next = p;
            free(q);
        } else {
            pre = p;
            p = p->Next;
        }
    }
}

//03.反向输出每个节点值
void Re_Print(PtrNode p) {
    if (p->Next != NULL)
        Re_Print(p->Next);
    printf("%d\n", p->Data);
}

//04.删除最小节点
void Del_Min(LinkList linkList) {
    PtrNode pre = linkList->Head, p = pre->Next;
    PtrNode minpre = pre, minp = p;
    while (p != NULL) {
        if (p->Data < minp->Data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->Next;
    }
    minpre->Next = minp->Next;
    free(minp);
}

//05.带头节点单链表 逆置
//摘下头节点，剩下的按顺序头插法到L后面
void Reverse1(LinkList linkList) {
    PtrNode p, r;
    p = linkList->Head->Next;
    linkList->Head->Next = NULL;
    while (p != NULL) {
        r = p->Next;
        p->Next = linkList->Head->Next;
        linkList->Head->Next = p;
        p = r;
    }
}

//摘下头节点，将剩下的依次反转，最后头节点指向反转后的链表
void Reverse2(LinkList linkList) {
    PtrNode pre, p = linkList->Head->Next, r = p->Next;
    p->Next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->Next;
        p->Next = pre;
    }
    linkList->Head->Next = p;
}

//06.带头节点单链表排序
void Sort(LinkList linkList) {
    PtrNode p = linkList->Head->Next, pre;
    PtrNode r = p->Next;
    p = r;
    while (p != NULL) {
        r = p->Next;
        pre = linkList->Head;
        while (pre->Next != NULL && pre->Next->Data < p->Data)
            pre = pre->Next;
        p->Next = pre->Next;
        pre->Next = p;
        p = r;
    }
}

//07.按区间值在带头节点单链表删除元素
void DeleteByRange(LinkList linkList, int min, int max) {
    PtrNode pre = linkList->Head, p = pre->Next;
    while (p != NULL) {
        if (p->Data > min && p->Data < max) {
            pre->Next = p->Next;
            free(p);
            p = pre->Next;
        } else {
            pre = p;
            p = pre->Next;
        }
    }
}

//08.两个单链表找出公共节点
PtrNode SearchCommon(LinkList list1, LinkList list2) {
    int len1 = Length(list1), len2 = Length(list2);
    int diff;
    PtrNode longL, shortL;
    if (len1 > len2) {
        longL = list1->Head->Next;
        shortL = list2->Head->Next;
        diff = len1 - len2;
    } else {
        longL = list2->Head->Next;
        shortL = list1->Head->Next;
        diff = len2 - len1;
    }
    while (diff--) {
        longL = longL->Next;
    }
    while (longL != NULL) {
        if (longL == shortL) {
            return longL;
        } else {
            longL = longL->Next;
            shortL = shortL->Next;
        }
    }
    return NULL;
}

//09.带头节点单链表按从小到大输出，不允许使用辅助空间
void Min_Delete(LinkList list) {
    PtrNode pre, p, min;
    while (list->Head->Next != NULL) {
        pre = list->Head->Next;
        min = pre;
        p = pre->Next;
        while (p != NULL) {
            if (p->Data < pre->Data) {
                min = p;
                pre = p;
            }
            p = p->Next;
        }
        printf("%d\n", min->Data);
        free(min);
    }
    free(list);
}

//10.拆分单链表，并且原单链表只保留奇数节点，新链表保存偶数节点
LinkList Split(LinkList list) {
    LinkList b = malloc(sizeof(struct LinkNode));
    PtrNode p, q;
    p = list->Head->Next;
    q = b->Head;
    while (p != NULL) {
        if (p->Next != NULL) {
            q->Next = p->Next;
            q = p->Next;
            p->Next = q->Next;
            p = q->Next;
        }
    }
    return b;
}

//11.与上题相同,但是新链表采用头插法，顺序与原本顺序相反
LinkList Split2(LinkList list) {
    LinkList b = malloc(sizeof(struct LinkNode));
    b->Head->Next = NULL;
    PtrNode p, q;
    p = list->Head->Next;
    while (p != NULL) {
        if (p->Next != NULL) {
            q = p->Next;
            p->Next = p->Next->Next;
            q->Next = b->Head->Next;
            b->Head->Next = q;
        }
    }
    return b;
}

//12。有序递增单链表 去重
void Del_Same(LinkList list) {
    PtrNode p = list->Head->Next, q;
    if (p == NULL)
        return;
    while (p->Next != NULL) {
        if (p->Data == p->Next->Data) {
            q = p->Next;
            p->Next = q->Next;
            free(q);
        } else {
            p = p->Next;
        }
    }
}

//13.两个递增有序单链表合并成递减有序单链表，不允许辅助空间
void MergeList(LinkList listA, LinkList listB) {
    PtrNode pa = listA->Head->Next, pb = listB->Head->Next, tmp, new;
    new = listA->Head;
    listA->Head->Next = NULL;//使用A作为新的链表
    while (pa && pb)//均不为空时
    {
        if (pa->Data <= pb->Data) {
            tmp = pa->Next;
            pa->Next = new->Next;
            new->Next = pa;
            pa = tmp;
        } else {
            tmp = pb->Next;
            pb->Next = new->Next;
            new->Next = pb;
            pb = tmp;
        }
    }

    if(pa)
        pb=pa;

    while (pb!=NULL)
    {
        tmp=pb->Next;
        pb->Next=new->Next;
        new->Next=pb;
        pb=tmp;
    }

    free(listB);
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