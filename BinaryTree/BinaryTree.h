// Created by wlk on 2019/7/20 22:09.

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack&Queue/SeqStack.h"
#include "Stack&Queue/SeqQueue.h"

typedef struct BiTNode {
    int Data;
    struct BiTNode *Lchild, *Rchild;
} BiTNode, *BiTree;

void PreOrder(BiTree T);

void InOrder(BiTree T);

void PostOrder(BiTree T);

void LevelOrder(BiTree T);

void InOrder2(BiTree T);

void PostOrder2(BiTree T);

void LevelOrder2(BiTree T);

#endif //DATASTRUCTURE_BINARYTREE_H
