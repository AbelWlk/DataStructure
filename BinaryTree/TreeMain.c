// Created by wlk on 2019/7/20 22:11.
#include "BinaryTree.h"
#include "LinearList/LinkList.h"
#include <stdlib.h>

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

//06 先序中序遍历存于数组，建立二叉链表
BiTree PreInCreat(const int a[], int b[], int l1, int h1, int l2, int h2) {
    int i = 0;
    BiTNode *root = malloc(sizeof(BiTNode));
    root->Data = a[l1];
    for (i = l2; b[i] != root->Data; i++);
    int llen = i - l2;
    int rlen = h2 - i;
    if (llen) {
        root->Lchild = PreInCreat(a, b, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    } else {
        root->Lchild = NULL;
    }
    if (rlen)
        root->Rchild = PreInCreat(a, b, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    else
        root->Rchild = NULL;
    return root;
}

//07 判定是否完全二叉树  层次遍历
bool IsComplete(BiTree tree) {
    SeqQueue queue;
    Init(&queue);
    BiTNode *p;
    if (!tree)
        return tree;
    EnQueue(queue, tree);
    while (!isEmpty(queue)) {
        p = DeQueue(queue);
        if (p) {
            EnQueue(queue, p->Lchild);
            EnQueue(queue, p->Rchild);
        } else {
            while (!isEmpty(queue)) {
                p = DeQueue(queue);
                if (p)
                    return false;
            }
        }
    }
    return true;
}

//08.判断双分支节点
int DsonNodes(BiTree tree) {
    if (tree == NULL)
        return 0;
    else if (tree->Lchild != NULL && tree->Rchild != NULL)
        return DsonNodes(tree->Lchild) + DsonNodes(tree->Rchild) + 1;
    else
        return DsonNodes(tree->Lchild) + DsonNodes(tree->Rchild);
}

//09.所有节点子树交换
void swap(BiTree tree) {
    if (tree) {
        swap(tree->Lchild);
        swap(tree->Rchild);
        BiTNode *temp = tree->Lchild;
        tree->Lchild = tree->Rchild;
        tree->Rchild = temp;
    }
}

//10.求先序遍历中第K个节点的值
int i = 1;

int PreNode(BiTree tree, int k) {
    if (tree == NULL)
        return '#';
    if (i == k)
        return tree->Data;
    i++;
    int ch = PreNode(tree->Lchild, k);
    if (ch != '#')
        return ch;
    ch = PreNode(tree->Rchild, k);
    return ch;
}

//11.删除对应值子树
void DeleteXTree(BiTree tree) {
    if (tree) {
        DeleteXTree(tree->Lchild);
        DeleteXTree(tree->Rchild);
        free(tree);
    }
}

void search(BiTree tree, int x) {
    SeqQueue q;

    if (tree) {
        if (tree->Data == x) {
            DeleteXTree(tree);
            exit(0);
        }
        Init(&q);
        EnQueue(q, tree);
        while (!isEmpty(q)) {
            BiTNode *p = DeQueue(q);
            if (p->Lchild) {
                if (p->Lchild->Data == x) {
                    DeleteXTree(p->Lchild);
                    p->Lchild = NULL;
                } else {
                    EnQueue(q, p->Lchild);
                }
            }
            if (p->Rchild) {
                if (p->Rchild->Data == x) {
                    DeleteXTree(p->Rchild);
                    p->Rchild = NULL;
                } else {
                    EnQueue(q, p->Rchild);
                }
            }
        }
    }
}

//12.根据值查找节点 打印节点的所有祖先
SeqStack stack;

bool Ancestors(BiTree tree, int x) {
    InitStack(&stack);
    if (!tree) return false;
    if (tree->Data == x) return true;
    if (Ancestors(tree->Lchild, x) || Ancestors(tree->Rchild, x)) {
        Push(stack, tree->Data);
        return true;
    }
    return false;
}

//13.找公共祖先节点
typedef struct {
    BiTree t;
    int tag;
} stacks;
stacks s[], s1[];

BiTree Ancestor(BiTree root, BiTNode *p, BiTNode *q) {
    int top = 0;
    int top1;
    BiTNode *bt = root;
    while (bt != NULL || top > 0) {
        while (bt != NULL && bt != p && bt != q) {
            while (bt != NULL) {
                s[++top].t = bt;
                s[top].tag = 0;
                bt = bt->Lchild;
            }
        }
        while (top != 0 && s[top].tag == 1) {
            if (s[top].t == p) {
                for (int i = 1; i <= top; ++i) {
                    s1[i] = s[i];
                    top1 = top;
                }
            }
            if (s[top].t == q) {
                for (int i = top; i > 0; i--) {
                    for (int j = top1; j > 0; j--) {
                        if (s1[j].t == s[i].t)
                            return s[i].t;
                    }
                }
            }
            top--;
        }
        if (top != 0) {
            s[top].tag = 1;
            bt = s[top].t->Rchild;
        }
    }
    return NULL;
}

//14.求二叉树宽度
typedef struct {
    BiTree data[MaxSize];
    int level[MaxSize];
    int front, rear;
} Qu;

int BTWidth(BiTree b) {
    Qu qu;
    BiTree p;
    int k, max, i, n;
    qu.front = qu.rear = -1;
    qu.rear++;
    qu.data[qu.rear] = b;
    qu.level[qu.rear] = 1;
    while (qu.front != qu.rear) {
        qu.front++;
        p = qu.data[qu.front];
        k = qu.level[qu.front];
        if (p->Lchild != NULL) {
            qu.rear++;
            qu.data[qu.rear] = p->Lchild;
            qu.level[qu.rear] = k + 1;
        }
        if (p->Rchild != NULL) {
            qu.rear++;
            qu.data[qu.rear] = p->Rchild;
            qu.level[qu.rear] = k + 1;
        }
    }
    max = 0;
    i = 0;
    k = 1;
    while (i < qu.rear) {
        n = 0;
        while (i < qu.rear && qu.level[i] == k) {
            n++;
            i++;
        }
        k = qu.level[i];
        if (n > max) max = n;
    }
    return max;
}


//15.满二叉树先序求后序
void PreToPost(char *pre, int l1, int h1, char *post, int l2, int h2) {
    int half;
    if (h1 >= l1) {
        post[h2] = pre[l1];
        half = (h1 - l1) / 2;
        PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        PreToPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
    }
}

//16.二叉树叶节点练成单链表
BiTNode *head = NULL, *pre = NULL;

BiTNode *InOrder3(BiTree bt) {
    if (bt) {
        InOrder3(bt->Lchild);
        if (bt->Lchild == NULL && bt->Rchild == NULL) {
            if (pre == NULL) {
                head = bt;
            } else {
                pre->Rchild = bt;
                pre = bt;
            }
        }
        InOrder3(bt->Lchild);
        pre->Lchild = NULL;
    }
    return head;
}

//17.判断两棵二叉树是否相似
int similar(BiTree t1, BiTree t2) {
    int lefts, rights;
    if (t1 == NULL && t2 == NULL)
        return 1;
    else if (t1 == NULL || t2 == NULL)
        return 0;
    else {
        lefts = similar(t1->Lchild, t2->Lchild);
        rights = similar(t1->Rchild, t2->Rchild);
        return lefts && rights;
    }
}


//18.中序线索二叉树里指定节点在在后序的前驱节点的算法
BiThrTree InPostPre(BiThrTree t, BiThrTree p) {
    BiThrTree q;
    if (p->rtag == 0)
        q = p->Rchild;
    else if (p->ltag == 0)
        q = p->Lchild;
    else if (p->Lchild == NULL)
        q = NULL;
    else {
        while (p->ltag == 1 && p->Lchild != NULL)
            p = p->Lchild;
        if (p->ltag == 0)
            q = p->Lchild;
        else
            q = NULL;
    }
    return q;
}

//19.
int wpl_PreOrder(BiTree root, int deep) {
    static int wpl = 0;
    if (root->Lchild == NULL && root->Rchild == NULL)
        wpl += deep * root->Data;
    if (root->Lchild != NULL)
        wpl_PreOrder(root->Lchild, deep + 1);
    if (root->Rchild != NULL)
        wpl_PreOrder(root->Rchild, deep + 1);
    return wpl;
}

int WPL(BiTree root) {
    return wpl_PreOrder(root, 0);
}


//20.
void BtreeToExp(BiTree root, int deep) {
    if (root == NULL) return;
    else if (root->Lchild == NULL && root->Rchild == NULL)
        printf("%d\n", root->Data);
    else {
        if (deep > 1) printf("(");
        BtreeToExp(root->Lchild, deep + 1);
        printf("%d\n", root->Data);
        BtreeToExp(root->Rchild, deep + 1);
        if (deep > 1) printf(")");
    }
}

void Btree(BiTree root) {
    BtreeToExp(root, 1);
}

int main() {


    return 0;
}