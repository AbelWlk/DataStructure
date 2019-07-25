// Created by wlk on 2019/7/20 22:09.

#include "BinaryTree.h"

void PreOrder(BiTree T) {
    if (T != NULL) {
        printf("%d\n", T->Data);
        PreOrder(T->Lchild);
        PreOrder(T->Rchild);
    }
}

void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->Lchild);
        printf("%d\n", T->Data);
        InOrder(T->Rchild);
    }
}

void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->Lchild);
        printf("%d\n", T->Data);
        PostOrder(T->Rchild);
    }
}

void LevelOrder(BiTree T) {
    SeqQueue queue;
    Init(&queue);
    BiTNode *p;
    EnQueue(queue, T);
    while (!isEmpty(queue)) {
        p = DeQueue(queue);
        printf("%d\n", p->Data);
        if (p->Lchild != NULL)
            EnQueue(queue, p->Lchild);
        if (p->Rchild != NULL)
            EnQueue(queue, p->Rchild);
    }
}

void InOrder2(BiTree T) {
    SeqStack stack;
    InitStack(&stack);
    BiTNode *p = T;
    while (p || !StackEmpty(stack)) {
        if (p) {
            Push(stack, p);
            p = p->Lchild;
        } else {
            p = Pop(stack);
            printf("%d\n", p->Data);
            p = p->Rchild;
        }
    }
}

void PostOrder2(BiTree T) {
    SeqStack s;
    InitStack(&s);
    BiTNode *p = T;
    BiTNode *r = NULL;
    while (p || !StackEmpty(s)) {
        if (p) {
            Push(s, p);
            p = p->Lchild;
        } else {
            p = GetTop(s);
            if (p->Rchild && p->Rchild != r) {
                p = p->Rchild;
                Push(s, p);
                p = p->Lchild;
            } else {
                p = Pop(s);
                printf("%d\n", p->Data);
                r = p;
                p = NULL;
            }
        }
    }
}

void LevelOrder2(BiTree T) {
    SeqQueue queue;
    Init(&queue);
    SeqStack s;
    InitStack(&s);

    BiTNode *p;
    EnQueue(queue, T);
    while (!isEmpty(queue)) {
        p = DeQueue(queue);
        Push(s, p);
        if (p->Lchild != NULL)
            EnQueue(queue, p->Lchild);
        if (p->Rchild != NULL)
            EnQueue(queue, p->Rchild);
    }
    while (!StackEmpty(s)) {
        p = Pop(s);
        printf("%d\n", p->Data);
    }
}