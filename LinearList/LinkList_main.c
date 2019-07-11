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

    if (pa)
        pb = pa;

    while (pb != NULL) {
        tmp = pb->Next;
        pb->Next = new->Next;
        new->Next = pb;
        pb = tmp;
    }

    free(listB);
}

//14.设计新链表指向两个递增有序单链表（带头节点）的公共节点，不破快原本节点
void Get_Common(LinkList listA, LinkList listB) {
    PtrNode pa = listA->Head->Next, pb = listB->Head->Next, pc, q;
    LinkList listC = malloc(sizeof(struct LinkNode));
    pc = listC->Head;
    while (pa && pb) {
        if (pa->Data < pb->Data) {
            pa = pa->Next;
        } else if (pa->Data > pb->Data) {
            pb = pb->Next;
        } else {
            q = malloc(sizeof(LNode));
            q->Data = pa->Data;
            pc->Next = q;
            pc = q;
            pa = pa->Next;
            pb = pb->Next;
        }
    }
    pc->Next = NULL;
}

//15.两个单链表求公共节点，存放于其中一个链表
LinkList Union(LinkList listA, LinkList listB) {
    PtrNode pa = listA->Head->Next, pb = listB->Head->Next, pc = listA->Head, tmp;
    while (pa && pb) {
        if (pa->Data == pb->Data) {
            pc->Next = pa;
            pc = pa;
            pa = pa->Next;
            tmp = pb;
            pb = pb->Next;
            free(tmp);
        } else if (pa->Data < pb->Data) {
            tmp = pa;
            pa = pa->Next;
            free(tmp);
        } else {
            tmp = pb;
            pb = pb->Next;
            free(tmp);
        }
    }

    while (pa) {
        tmp = pa;
        pa = pa->Next;
        free(pa);
    }
    while (pb) {
        tmp = pb;
        pb = pb->Next;
        free(pb);
    }
    pc->Next = NULL;
    free(listB);
    return listA;
}

//16.两个整数单链表，判断后者是否为前者的连续子序列
bool IsSubList(LinkList listA, LinkList listB) {
    PtrNode pa = listA->Head, pb = listB->Head, pre = pa;
    while (pa && pb) {
        if (pa->Data == pb->Data) {
            pa = pa->Next;
            pb = pb->Next;
        } else {
            pre = pre->Next;
            pa = pre;
            pb = listB->Head;
        }
    }
    if (pb == NULL)
        return true;//b比较结束，说明是a的子序列
    else {
        return false;
    }
}

//17.判断带头节点的双循环链表是个否对称{双循环链表懒得实现}
//18.两个循环单链表，b连接到a之后，保持循环
LinkList Link(LinkList listA, LinkList listB) {
    PtrNode pa = listA->Head, pb = listB->Head;
    while (pa->Next != listA->Head)//循环找到最后节点
        pa = pa->Next;
    while (pb->Next != listB->Head)//循环找到最后节点
        pb = pb->Next;
    pa->Next = listB->Head;
    pb->Next = listA->Head;
    return listA;
}

//19.循环单链表，按最小节点输出并删除 直到表空
void Del_Min02(LinkList list) {
    PtrNode p, pre, minp, minpre;
    while (list->Head->Next != list->Head) {
        p = list->Head->Next;
        pre = list->Head;
        minp = p;
        minpre = pre;
        while (p != list->Head) {
            if (p->Data < minp->Data) {
                minp = p;
                minpre = pre;
            }
            pre = p;
            p = p->Next;
        }
        printf("%d\n", minp->Data);
        minpre->Next = minp->Next;//断开/删除
        free(minp);
    }
    free(list);
}

//20.按照访问频度排序（双链表懒得实现）
//21.带头节点单链表按位置查找倒数第几个节点
int Search(LinkList list, int k) {
    PtrNode p = list->Head->Next, q = list->Head->Next;
    int count = 0;
    while (p != NULL) {
        if (count < k)
            count++;
        else
            q = q->Next;
        p = p->Next;
    }
    if (count < k)
        return 0;
    else {
        printf("%d\n", q->Data);
        return 1;
    }
}

//22.求两个单词共同后缀的起始地址（两个单链表，求共同节点起始节点）
PtrNode find_addr(LinkList listA, LinkList listB) {
    int m = Length(listA), n = Length(listB);
    PtrNode pa, pb;
    for (pa = listA->Head->Next; m > n; m--)//若m>n,则使a指向m-n+1个节点
        pa = pa->Next;
    for (pb = listB->Head->Next; m < n; n--)//同上理
        pb = pb->Next;
    while (pa->Next != NULL && pa->Next != pb->Next) {
        pa = pa->Next;
        pb = pb->Next;
    }
    return pa->Next;
}

//23.删除绝对值相同的点，乱序
void Del_Same02(LinkList list, int n) {
    PtrNode p = list->Head, r;
    int *q, m;
    q = malloc(sizeof(int) * n + 1);
    for(int i=0;i<n+1;i++){
        q[i]=0;
    }
    while (p->Next!=NULL)
    {
        m=p->Next->Data>0?p->Next->Data:-p->Next->Data;
        if(q[m]==0)
        {
            q[m]=1;
            p=p->Next;
        } else{
            r=p->Next;
            p->Next=r->Next;
            free(r);
        }
    }
    free(q);
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