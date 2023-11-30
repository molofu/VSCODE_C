#include "stack.h"

bool cmp_op(char op1, char op2)
{
    if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
    {
        return false;
    }
    return true;
}

bool is_op(char x)
{
    if (x != '+' && x != '-' && x != '*' && x != '/')
    {
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char inStr[] = "5+3-2*4/2";
    char op;
    sqStack temp; // 放操作数
    int len = strlen(inStr);

    sqStack suf; // 放运算符
    InitStack(&suf);
    InitStack(&temp);
    for (int i = 0; i < len; i++)
    {
        if (!is_op(inStr[i]))
        {
            push_stack(&temp, inStr[i]);
        }
        else if (suf.top == -1)
        {
            push_stack(&suf, inStr[i]);
        }
        else if (cmp_op(suf.data[suf.top], inStr[i]))
        {
            pop_stack(&suf, &op);
            push_stack(&temp, op);
            push_stack(&suf, inStr[i]);
        }
        else
        {
            push_stack(&suf, inStr[i]);
        }
    }
    while (!stack_is_empty(&suf))
    {
        pop_stack(&suf, &op);
        push_stack(&temp, op);
    }

    char str[20];
    for (int i = 0; i < temp.top + 1; i++)
    {
        str[i] = temp.data[i];
    }
    for (int i = 0; i < 20; i++)
    {
        printf("%c", str[i]);
    }

    return 0;
}
