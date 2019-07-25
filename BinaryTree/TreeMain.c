// Created by wlk on 2019/7/20 22:11.
#include "BinaryTree.h"

int Comm_Ancestor(int T[], int i, int j) {
    if (T[i] != '#' && T[j] != '#') {
        while (i != j) {
            if (i > j) {
                i = i / 2;
            } else {
                j = j / 2;
            }
        }
        return T[i];
    }
}

//05 非递归求树高度
int Btdepth(BiTree T) {
    if (!T)
        return 0;
    int front = -1, rear = -1;
    int last = 0, level = 0;
    BiTree Q[MaxSize];
    Q[++rear] = T;
    BiTree p;
    while (front < rear) {
        p = Q[++front];
        if (p->Lchild)
            Q[++rear] = p->Lchild;
        if (p->Rchild)
            Q[++rear] = p->Rchild;
        if (front == last) {
            level++;
            last = rear;
        }
    }
    return level;
}

int main() {


    return 0;
}