// Created by wlk on 2019/7/17 22:18.
#include "SeqStack.h"
#include "SeqQueue.h"
#include <string.h>

//1.À¨ºÅÆ¥Åä
bool BracketCheck(char *str) {
    SeqStack stack;
    InitStack(&stack);
    int i = 0;
    while (str[i] != '\0') {
        switch (str[i]) {
            case '(':
                Push(stack, str[i]);
                break;
            case '{':
                Push(stack, str[i]);
                break;
            case '[':
                Push(stack, str[i]);
                break;
            case ')':
                if (Pop(stack) != '(') return false;
                break;
            case ']':
                if (Pop(stack) != '[') return false;
                break;
            case '}':
                if (Pop(stack) != '{') return false;
                break;
            default:
                break;
        }
        i++;
    }
    if (!StackEmpty(stack)) {
        return false;
    } else {
        return true;
    }
}

//02.·ÖÀà
void Train_Arrange(char *train) {
    char *p = train, *q = train;
    SeqStack s;
    InitStack(&s);
    while (*p) {
        if (*p == 'H')
            Push(s, *p);
        else
            *(q++) = *p;
        p++;
    }

    while (!StackEmpty(s)) {
        *(q++) = Pop(s);
    }
}

//03.·ÇµÝ¹é¼ÆËã
double P(int n, double x) {
//    if (n == 0)
//        return 1;
//    if (n == 1)
//        return x * 2;
//    if(n>1)
//    {
//        return x*2*P(n-1,x)-2*(n-1)*P(n-2,x);
//    }
    struct stack {
        int n;
        double val;
    } st[MaxSize];
    int top = -1, i;
    double fv1 = 1, fv2 = 2 * x;
    for (i = n; i >= 2; i--) {
        top++;
        st[top].n = i;
    }
    while (top >= 0) {
        st[top].val = 2 * x * fv2 - 2 * (st[top].n - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if (n == 0) {
        return fv1;
    }
    return fv2;
}

//04.
SeqQueue q, q1, q2;

void Manage() {
    int i = 0, j = 0;
    while (j < 10) {
        if (!isEmpty(q1) && i < 4) {
            EnQueue(q, DeQueue(q1));
            i++;
            j++;
        } else if (i == 4 && !isEmpty(q2)) {
            EnQueue(q, DeQueue(q2));
            j++;
            i = 0;
        } else {
            while (j < 10 && i < 4 && !isEmpty(q2)) {
                EnQueue(q, DeQueue(q2));
                i++;
                j++;
            }
            i = 0;
        }
        if (isEmpty(q1) && isEmpty(q2)) {
            j = 11;
        }
    }
}

int main() {

    printf("%c\n", 123);
    return 0;
}