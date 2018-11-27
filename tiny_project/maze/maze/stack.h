/*************************************************************************
 > File Name: stack.c
 > Author: Kermit
 > Email: wk19951231@163.com
 > Created Time: 2015年05月02日 星期六 22时39分06秒
 ************************************************************************/


#include <stdio.h>
#include <malloc.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INCREMENT_SIZE 10
#define STACK_INIT_SIZE 100

typedef struct{
	int x;
	int y;
}pos;

typedef struct{
	int ord;
	pos seat;
}sElemType;

typedef int status;

typedef struct{
	sElemType *base;
	sElemType *top;
	int stacksize;
	int length;
}Stack;

status init_stack(Stack *s);
status stack_is_empty(Stack s);
status destroy_stack(Stack *s);
status get_top(Stack s);
int stack_length(Stack s);
status push(Stack *s, sElemType e);
status pop(Stack *s, sElemType *e);
status stack_traverse(Stack s);

status init_stack(Stack *s)
{
	s->base = (sElemType*)malloc(STACK_INIT_SIZE*sizeof(sElemType));
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	s->length = 0;
	return OK;
}

status stack_is_empty(Stack s)
{
	if(s.top == s.base)
		return 1;
	return 0;
}

status push(Stack *s, sElemType e)
{
	if(s->base - s->top == s->stacksize)
	{
		s->base = (sElemType*) realloc(s->base, (s->stacksize+INCREMENT_SIZE)*sizeof(sElemType));
		s->top = s->base + s->stacksize;
		s->stacksize += INCREMENT_SIZE;
	}
	*s->top = e;
	++s->top;
	++s->length;
	return OK;
}

status pop(Stack *s, sElemType *e)
{
	if(s->base == s->top)
		return ERROR;
	*e = *(s->top-1);
	--s->top;
	--s->length;
	return OK;
}

int stack_length(Stack s)
{
	return s.length;
}

status stack_traverse(Stack s)
{
	while(s.base != s.top)
	{
		printf("第%d步:(%d, %d)", (*(s.top-1)).ord, (*(s.top-1)).seat.x, (*(s.top-1)).seat.y);
		--s.top;
	}
	printf("\n");
}

status destroy_stack(Stack	*s)
{
	s->stacksize = 0;
	s->length = 0;
	s->top = s->base;
	free(s->base);
}

