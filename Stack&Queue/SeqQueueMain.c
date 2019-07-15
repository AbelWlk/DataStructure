// Created by wlk on 2019/7/15 22:47.
#include "SeqQueue.h"
#include "SeqStack.h"

//01.
int EnQueue01(SeqQueue seqQueue, int data) {
    if (seqQueue->front == seqQueue->rear && seqQueue->tag == 1)
        return 0;
    seqQueue->Data[seqQueue->rear] = data;
    seqQueue->rear = (seqQueue->rear + 1) % MaxSize;
    seqQueue->tag = 1;
    return 1;
}

int DeQueue01(SeqQueue seqQueue) {
    if (seqQueue->front == seqQueue->rear && seqQueue->tag == 0)
        return 0;
    int data = seqQueue->Data[seqQueue->front];
    seqQueue->front = (seqQueue->front + 1) % MaxSize;
    seqQueue->tag = 0;
    return data;
}

//02.用一个队列和栈逆序队列
void Reverse(SeqQueue queue, SeqStack stack) {
    while (!isEmpty(queue)) {
        int data = DeQueue(queue);
        Push(stack, data);
    }
    while (!StackEmpty(stack)) {
        int data = Pop(stack);
        EnQueue(queue, data);
    }
}

//03.用两个栈模拟队列
int EnQueue02(SeqStack s1, SeqStack s2, int data) {
    if (!StackOverFlow(s1)) {
        Push(s1, data);
    }
    if (StackOverFlow(s1) && !StackEmpty(s2)) {
        printf("Queue is Full!\n");
        return 0;
    }
    if (StackOverFlow(s1) && StackEmpty(s2)) {
        while (!StackEmpty(s1)) {
            int d = Pop(s1);
            Push(s2, d);
        }
    }
    Push(s1, data);
    return 1;
}

int DeQueue02(SeqStack s1, SeqStack s2) {
    if (!StackEmpty(s2)) {
        return Pop(s2);
    } else if (StackEmpty(s1)) {
        printf("Queue is Empty!\n");
        return 0;
    } else {
        while (!StackEmpty(s1)) {
            int x = Pop(s1);
            Push(s2, x);
        }
        return Pop(s2);
    }
}

bool QueueEmpty(SeqStack s1, SeqStack s2) {
    if (StackEmpty(s1) && StackEmpty(s2))
        return true;
    else
        return false;
}

int main() {


    return 0;
}