//
// Created by 78204 on 2019/8/6.
//

#ifndef DATASTRUCTURE_ALGRAPH_H
#define DATASTRUCTURE_ALGRAPH_H
#define MaxVertexNum 100

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//邻接表定义
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
    //InfoType info;//权值
}ArcNode;

typedef struct VNode{
    int data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;


//十字链表
typedef struct ArcNodee{
    int tailvex,headvex;
    struct ArcNode *hlink,*tlink;
}ArcNodee;
typedef struct VNode{
    int data;
    ArcNode *firstin,*firstout;
}VNode;
typedef struct {
    VNode xlist[MaxVertexNum];
    int vexnum,arcnum;
}GLGraph;

void Convert(ALGraph *G, int arcs[M][N]);

#endif //DATASTRUCTURE_ALGRAPH_H
