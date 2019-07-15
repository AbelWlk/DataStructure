// Created by wlk on 2019/7/15 22:35.

#include <stdio.h>
#include "SeqQueue.h"

void Init(SeqQueue *seqQueue) {
    *seqQueue = malloc(sizeof(struct Queue));
    (*seqQueue)->front = (*seqQueue)->rear = (*seqQueue)->tag=0;
}

bool isEmpty(SeqQueue seqQueue) {
    if (seqQueue->rear == seqQueue->front) return true;
    else return false;
}

bool EnQueue(SeqQueue seqQueue, int data) {
    if ((seqQueue->rear + 1) % MaxSize == seqQueue->front) return false;
    seqQueue->Data[seqQueue->front] = data;
    seqQueue->rear = (seqQueue->rear + 1) % MaxSize;
    return true;
}

int DeQueue(SeqQueue seqQueue) {
    if (seqQueue->rear == seqQueue->front) return false;
    int data = seqQueue->Data[seqQueue->front];
    seqQueue->front = (seqQueue->front + 1) % MaxSize;
    return true;
}