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

//在有序顺序表中
bool DelByRange(SeqList *seqList, int s, int t) {
    int i, j;
    if (s > t || seqList->Size == 0)
        return false;
    for (i = 0; i < seqList->Size && *((int *) seqList->Data[i]) < s; ++i);//寻找大于等于s的第一个元素

    if (i >= seqList->Size)
        return false;

    for (j = i; j < seqList->Size && *((int *) seqList->Data[i]) <= t; j++);//寻找值大于t的第一个元素

    for (; j < seqList->Size; i++, j++) {
        seqList->Data[i] = seqList->Data[j];//依次迁移
    }

    seqList->Size = i;
    return true;
}

//在顺序表中
bool DelByRange02(SeqList *seqList, int s, int t) {

    int i, k = 0;
    if (seqList->Size == 0 || s >= t)
        return false;
    for (i = 0; i < seqList->Size; i++) {
        if (*((int *) seqList->Data[i]) >= s && *((int *) seqList->Data[i]) <= t) {
            k++;
        } else {
            seqList->Data[i - k] = seqList->Data[i];//当前元素向前移动k个位置
        }
    }
    seqList->Size -= k;
    return true;
}

//从有序顺序表中删除所有重复的元素，最终留下的元素各不相同
bool DelSame(SeqList *seqList) {
    if (seqList->Size == 0)
        return false;
    int i, j;//i存储第一个不相同的元素
    for (i = 0, j = 1; j < seqList->Size; j++) {
        if (*((int *) seqList->Data[i]) != *((int *) seqList->Data[j]))//查找下一个值不相同的元素
        {
            seqList->Data[++i] = seqList->Data[j];//找到后元素后裔
        }
    }
    seqList->Size = i + 1;
    return true;
}

//两个有序顺序表合并
bool Merge(SeqList A, SeqList B, SeqList *C) {
    if (A.Size + B.Size > C->MaxSize)
        return false;
    int i = 0, j = 0, k = 0;
    while (i < A.Size && j < B.Size) {
        if (*((int *) A.Data[i]) <= *((int *) B.Data[j])) {
            C->Data[k++] = A.Data[i++];
        } else {
            C->Data[k++] = B.Data[j++];
        }
    }
    while (i < A.Size) {
        C->Data[k++] = A.Data[i++];
    }
    while (j < B.Size) {
        C->Data[k++] = B.Data[j++];
    }
    C->Size = k;
    return true;
}

//将后n个元素移动到最前面，元素顺序不变
void Reverse02(SeqList *seqList, int left, int right) {
    if (left > right || right > seqList->Size)
        return;
    int mid = (left + right) / 2;
    for (int i = 0; i <= mid - left; ++i) {
        void *tmp = seqList->Data[left + i];
        seqList->Data[left + i] = seqList->Data[right - i];
        seqList->Data[right - i] = tmp;
    }
}

void ExChange(SeqList *seqList, int m, int n) {
    Reverse02(seqList, 0, m + n - 1);
    Reverse02(seqList, 0, n - 1);
    Reverse02(seqList, n, m + n - 1);
}

//有序顺序表中查找x,找到则将其与后续交换；找不到则插入，并保持有序
void SearchExChangeInsert(SeqList *seqList, int x) {
    int low = 0, high = seqList->Size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (*((int *) seqList->Data[mid]) < x) {
            break;//找到x退出虚幻
        } else if (*((int *) seqList->Data[mid]) < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        if (*((int *) seqList->Data[mid]) == x && mid != seqList->Size - 1) {
            //找到x且x不是最后一个元素 执行交换
            void *tmp = seqList->Data[mid];
            seqList->Data[mid] = seqList->Data[mid + 1];
            seqList->Data[mid + 1] = tmp;
        }
        if (low > high)//没找到，按顺序插入
        {
            for (int i = seqList->Size - 1; i > high; i--) {
                seqList->Data[i + 1] = seqList->Data[i];
            }
            *((int *) seqList->Data[high + 1]) = x;
        }
    }
}

//一维数组循环左移p个位置
void Reverse03(int R[], int from, int to) {
    int i, temp;
    for (i = 0; i < (to - from + 1) / 2; i++) {
        temp = R[from + i];
        R[from + i] = R[to - i];
        R[to - i] = R[from + i];
    }
}

void Converse(int R[], int n, int p) {
    Reverse03(R, 0, p - 1);
    Reverse03(R, p, n - 1);
    Reverse03(R, 0, n - 1);
}

//求两个顺序序列的中位数
int MidNum(const int a[], const int b[], int n) {
    int i = 0, j = 0;
    for (int k = 0; k < n - 1; k++) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            i++;
            j++;
            k++;
        }
    }
    if ((i + j) > n - 1) {
        i--;//return a[i--];
        j--;//or return b[j--];
    }
    return a[i] > b[j] ? b[j] : a[i];
}

int MidNum02(const int a[], const int b[], int n) {
    int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;//分别表示ab的头尾及中位数
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (a[m1] == b[m2])
            return a[m1];//两个中位数相等,直接返回其中任意一个
        if (a[m1] < b[m2]) {
            if ((s1 + d1) % 2 == 0)//若元素个数为基数
            {
                s1 = m1;
                d2 = m2;
            } else {
                s1 = m1 + 1;
                d2 = m2;
            }
        } else {
            if ((s2 + d2) % 2 == 0) {
                d1 = m1;
                s2 = m2;
            } else {
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return a[s1] < b[s2] ? a[s1] : b[s2];
}

//找出主元素 1.先找出出现次数可能最多的一个数 2.判断该数出现的次数是否超过一半
int MajorityNum(const int a[], int n) {
    int i, c, count = 1;
    c = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] == c)
            count++;
        else {
            if (count > 0)
                count--;
            else {
                c = a[i];
                count = 1;
            }
        }
    }
    if (count > 0) {
        for (i = count = 0; i < n; i++) {
            if (a[i] == c)
                count++;
        }
    }
    if (count > n / 2)
        return c;
    else
        return -1;
}

//未出现的最小正整数
int FindMissMin(int a[], int n) {
    int i, *b;
    b = malloc(sizeof(int) * n);
    memset(b, 0, sizeof(int) * n);
    for (i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] <= n) {
            b[a[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (b[i] == 0) break;
    }
    return i + 1;
}

int main() {
//    SeqList seqList;
////    InitList(&seqList);
////    int a = 10, b = 5, c = 6, d = 7, e = 9;
////    ListInsert(&seqList, 1, &a);
////    ListInsert(&seqList, 2, &b);
////    ListInsert(&seqList, 3, &c);
////    ListInsert(&seqList, 4, &d);
////    ListInsert(&seqList, 5, &e);
////    PrintLsit(seqList, print);
////
////    DeleteByValue(&seqList, 7);
////
////    PrintLsit(seqList, print);

    int a[] = {1, 2, 3, 4, 5};
    int b[] = {4, 5, 7, 8, 9};
    printf("%d", MidNum(a, b, 5));

    return 0;
}