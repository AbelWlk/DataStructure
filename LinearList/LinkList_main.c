// Created by wlk on 2019/7/9 21:05.
#include "LinkList.h"

//01.ɾ������ͷ�ڵ�ĵ�����L������ֵΪx�Ľڵ�
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

//02.��ͷ�ڵ�ɾ������x�ڵ�
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

//03.�������ÿ���ڵ�ֵ
void Re_Print(PtrNode p) {
    if (p->Next != NULL)
        Re_Print(p->Next);
    printf("%d\n", p->Data);
}

//04.ɾ����С�ڵ�
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

//05.��ͷ�ڵ㵥���� ����
//ժ��ͷ�ڵ㣬ʣ�µİ�˳��ͷ�巨��L����
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

//ժ��ͷ�ڵ㣬��ʣ�µ����η�ת�����ͷ�ڵ�ָ��ת�������
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

//06.��ͷ�ڵ㵥��������
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

//07.������ֵ�ڴ�ͷ�ڵ㵥����ɾ��Ԫ��
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

//08.�����������ҳ������ڵ�
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

//09.��ͷ�ڵ㵥������С���������������ʹ�ø����ռ�
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

//10.��ֵ���������ԭ������ֻ���������ڵ㣬��������ż���ڵ�
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

//11.��������ͬ,�������������ͷ�巨��˳����ԭ��˳���෴
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

//12��������������� ȥ��
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

//13.����������������ϲ��ɵݼ������������������ռ�
void MergeList(LinkList listA, LinkList listB) {
    PtrNode pa = listA->Head->Next, pb = listB->Head->Next, tmp, new;
    new = listA->Head;
    listA->Head->Next = NULL;//ʹ��A��Ϊ�µ�����
    while (pa && pb)//����Ϊ��ʱ
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