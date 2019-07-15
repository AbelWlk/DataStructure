// Created by wlk on 2019/7/12 21:22.

#include <stdio.h>
#include "SeqStack.h"

void InitStack(SeqStack *seqStack) {
    *seqStack = malloc(sizeof(struct Stack));
    (*seqStack)->top = -1;
}

bool StackEmpty(SeqStack seqStack) {
    if (seqStack->top == -1)
        return true;
    else
        return false;
}

bool StackOverFlow(SeqStack seqStack) {
    if (seqStack->top == MaxSize - 1)
        return true;
    else
        return false;
}

bool Push(SeqStack seqStack, int data) {
    if (seqStack->top == MaxSize - 1)
        return false;
    seqStack->Data[++seqStack->top] = data;
    return true;
}

int Pop(SeqStack seqStack) {
    if (seqStack->top == -1)
        return -1;
    return seqStack->Data[seqStack->top--];
}

int GetTop(SeqStack seqStack) {
    if (seqStack->top == -1)
        return -1;
    return seqStack->Data[seqStack->top];
}

void ClearStack(SeqStack seqStack) {
    free(seqStack);
}