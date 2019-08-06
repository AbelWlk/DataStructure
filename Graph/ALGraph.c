//
// Created by 78204 on 2019/8/6.
//
#define M 10
#define N 10
#include "ALGraph.h"

void Convert(ALGraph *G, int arcs[M][N]) {
    for (int i = 0; i < N; i++) {
        ArcNode *p = (G->vertices[i]).first;
        while (p != NULL) {
            arcs[i][p->adjvex] = 1;
            p = p->next;
        }
    }
}
