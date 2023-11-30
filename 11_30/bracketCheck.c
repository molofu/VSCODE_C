#include "sq.h"

bool bracketCheck(char str[], int length)
{
    sqStack s;
    InitStack(&s);
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push_stack(&s, str[i]);
        }
        else
        {
            if (stack_is_empty(&s))
            {
                return false;
            }
            char top_elem;
            pop_stack(&s, &top_elem);
            if (str[i] == ')' && top_elem != '(')
            {
                return false;
            }
            if (str[i] == ']' && top_elem != '[')
            {
                return false;
            }
            if (str[i] == '}' && top_elem != '{')
            {
                return false;
            }
        }
    }
    return stack_is_empty(&s);
}

int main(int argc, char const *argv[])
{
    char str[] = "{[{[(()())[(){}]]}]}";
    int len = strlen(str);
    bool flag;
    flag = bracketCheck(str, len);
    if (flag)
    {
        printf("匹配成功\n");
    }
    else
    {
        printf("匹配失败\n");
    }

    return 0;
}
