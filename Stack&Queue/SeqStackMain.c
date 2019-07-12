#include "SeqStack.h"
#include "LinearList/LinkList.h"

//03.�жϳ���ջ�����Ƿ�Ϸ�
bool Judge(char a[]) {
    int i = 0, j = 0, k = 0;
    while (a[i] != '\0')//����δ����β
    {
        switch (a[i]) {
            case 'I':
                j++;
                break;
            case 'O':
                k++;
                if (k > j) {
                    printf("���зǷ���\n");
                    exit(0);
                }
        }
        i++;
    }
    if (j != k) {
        printf("���зǷ���\n");
        return false;
    } else {
        printf("���кϷ���\n");
        return true;
    }
}

//04.�ж��Ƿ����ĶԳ�
int dc(LinkList list, int n) {
    int i;
    char s[n / 2];
    PtrNode p = list->Head->Next;
    for (i = 0; i < n / 2; i++) {
        s[i] = p->Data;
        p = p->Next;
    }
    i--;
    if (n % 2 == 1)
        p = p->Next;
    while (p != NULL && s[i] == p->Data) {
        i--;
        p = p->Next;
    }
    if (i == -1)
        return 1;
    else
        return 0;
}

//05.����ջ
#define maxsize 100
typedef struct {
    int stack[maxsize];
    int top[2];
} stk;
stk s;

int push(int i, int x) {
    if (i < 0 || i > 1) {
        printf("ջ�Ų���");//0�������ջ 1�����ұ�ջ
        exit(0);
    }

    if (s.top[1] - s.top[0] == 1) {
        printf("ջ����\n");
        return 0;
    }

    switch (i) {
        case 0:
            s.stack[++s.top[0]] = x;
            return 1;
        case 1:
            s.stack[--s.top[1]] = x;
            return 1;
        default:;
    }
    return 0;
}

int pop(int i) {
    if (i < 0 || i > 1) {
        printf("ջ�Ų���");//0�������ջ 1�����ұ�ջ
        exit(0);
    }
    switch (i) {
        case 0:
            if (s.top[0] == -1) {
                printf("ջ�գ�\n");
                return -1;
            } else {
                return s.stack[s.top[0]--];
            }
        case 1:
            if (s.top[1] == maxsize) {
                printf("ջ�գ�\n");
                return -1;
            } else {
                return s.stack[s.top[1]++];
            }
        default:;
    }
    return -1;
}


int main() {

    SeqStack seqStack;
    InitStack(&seqStack);
    if (StackEmpty(seqStack)) {
        printf("empty");
    }

    Push(seqStack, 10);
    Push(seqStack, 11);
    Push(seqStack, 12);

    if (StackEmpty(seqStack)) {
        printf("empty");
    } else {
        printf("%d\n", seqStack->top);
    }

    printf("%d\n", GetTop(seqStack));

    printf("%d\n", Pop(seqStack));

    return 0;
}