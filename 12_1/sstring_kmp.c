#include <stdio.h>
#include <string.h>

#define MAXSIZE 255
typedef struct
{
    char str[MAXSIZE];
    int length;
} sstring;

void str_assign(sstring *s, char *t)
{
    int len = strlen(t);
    for (int i = 0; i < len; i++)
    {
        s->str[i] = *t++;
    }
    s->length = len;
}

void get_next(sstring *model_str, int *next_val)
{
    int len = model_str->length;
    next_val[0] = 0;
    next_val[1] = 0;
    int i = 1, k = 0;
    while (i < len)
    {
        if (k == 0 || model_str->str[i] == model_str->str[k])
        {
            i++;
            k++;
            next_val[i] = k;
        }
        else
        {
            k = next_val[k];
        }
    }
}

int str_kmp(sstring *main_str, sstring *model_str)
{
    int next[100];

    get_next(model_str, next);

    int i = 1, j = 1;
    while (i <= main_str->length && j <= model_str->length)
    {
        if (j == 0 || main_str->str[i - 1] == model_str->str[j - 1])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > model_str->length)
    {
        return i - model_str->length;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    sstring main_str;
    str_assign(&main_str, "abcadefabcaabcabg");
    sstring model_str;
    str_assign(&model_str, "abcab");

    int pos = str_kmp(&main_str, &model_str);
    // printf("%s\n", model_str.str);
    printf("%d\n", pos);
    return 0;
}
