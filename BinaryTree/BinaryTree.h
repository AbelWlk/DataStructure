// Created by wlk on 2019/7/20 22:09.

#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BiTNode {
    int Data;
    struct BiTNode *Lchild, *Rchild;
} BiTNode, *BiTree;

#endif //DATASTRUCTURE_BINARYTREE_H
