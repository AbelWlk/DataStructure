// Created by wlk on 2019/7/12 21:22.

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H
#define MaxSize 50

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack{
    int Data[MaxSize];
    int top;
} *SeqStack;

void InitStack(SeqStack *seqStack);

bool StackEmpty(SeqStack seqStack);

bool Push(SeqStack seqStack, int data);

int Pop(SeqStack seqStack);

int GetTop(SeqStack seqStack);

void ClearStack(SeqStack seqStack);

#endif //DATASTRUCTURE_STACK_H
