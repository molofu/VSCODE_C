#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAXSIZE 10
#define ELEMENT char
typedef struct 
{
    ELEMENT data[MAXSIZE];
    int top;
} sqStack;

void InitStack(sqStack *s);

bool stack_is_empty(sqStack *s);

bool push_stack(sqStack *s,ELEMENT x);

bool pop_stack(sqStack *s, ELEMENT *x);
