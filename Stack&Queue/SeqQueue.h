// Created by wlk on 2019/7/15 22:35.

#ifndef DATASTRUCTURE_SEQQUEUE_H
#define DATASTRUCTURE_SEQQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 30

typedef struct Queue{
    int Data[MaxSize];
    int front,rear,tag;
}*SeqQueue;

void Init(SeqQueue *seqQueue);

bool isEmpty(SeqQueue seqQueue);

bool EnQueue(SeqQueue seqQueue,int data);

int DeQueue(SeqQueue seqQueue);

#endif //DATASTRUCTURE_SEQQUEUE_H
