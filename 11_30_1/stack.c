#include "stack.h"

void InitStack(sqStack *s)
{
    s->top = -1;
}

bool stack_is_empty(sqStack *s)
{
    if (-1 == s->top)
    {
        return true;
    }
    return false;
}

bool push_stack(sqStack *s, ELEMENT x)
{
    if (s->top == MAXSIZE - 1)
        return false;
    s->top++;
    s->data[s->top] = x;
    return true;
}

bool pop_stack(sqStack *s, ELEMENT *x)
{
    if (-1 == s->top)
        return false;
    *x = s->data[s->top];
    s->top--;
    return true;
}