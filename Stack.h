#include <stdio.h>
#include <stdlib.h>
#define stacksize 100
#define true 1
#define false 0
struct stack
{
    int item[stacksize];
    int top;
} s;

void initialize(struct stack *s)
{
    s->top = -1;
}

int isempty(struct stack *s)
{
    return (s->top == -1);
}

int stacktop(struct stack *s)
{
    if (isempty(s))
    {
        printf("stack is empty");
        exit(1);
    }
    return s->item[s->top];
}

void push(struct stack *s, int x)
{
    if (s->top == (stacksize - 1))
    {
        printf("\nSTACK OVERFLOW");
        exit(1);
    }
    else
    {
        s->top++;
        s->item[s->top] = x;
    }
}

int pop(struct stack *s)
{
    if (isempty(s))
    {
        printf("\nSTACK UNDERFLOW");
        exit(1);
    }
    else
    {
        int x = s->item[s->top];
        s->top--;
        return x;
    }
}