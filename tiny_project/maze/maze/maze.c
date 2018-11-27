/*************************************************************************
 > File Name: maze.c
 > Author: Kermit
 > Email: wk19951231@163.com
 > Created Time: 2015年05月03日 星期日 12时48分51秒
 ************************************************************************/

#include <stdio.h>
#include "stack.h"
#include "maze_draw.h"
#define true 1
#define false 0

typedef int bool;


void foot_print(sElemType e);
void foot_delete(sElemType e);
void foot_mark(sElemType e);
bool pass(sElemType e);
status walk_maze(sElemType *e, Stack s);
int explore(sElemType *e);

int main()
{
	Stack s;
	init_stack(&s);
	int i = 0;
	sElemType start = {
		0,
		{
			1,
			1,
		}
	};
	sElemType curpos = start;
	welcome();
	printf("\n\n");
	print_map();
	printf("\n\nI'm going...........................\n\n");
	i = walk_maze(&curpos, s);
	printf("(@_@)\n\n");
	print_map();
	if(i == 1)
		printf("\n\nDone!\n\n");
	else
		printf("\n\nI'm missing!\n\n");

	return 0;
}

bool pass(sElemType e)
{
	if(matrix.map[e.seat.x][e.seat.y] == '#' || matrix.map[e.seat.x][e.seat.y] == 'O' || matrix.map[e.seat.x][e.seat.y] == 'X')
		return false;
	return true;
}

void foot_print(sElemType e)
{
	matrix.map[e.seat.x][e.seat.y] = 'O';
}

void foot_delete(sElemType e)
{
	matrix.map[e.seat.x][e.seat.y] = 'X';
}

void foot_mark(sElemType e)
{
	matrix.map[e.seat.x][e.seat.y] = '*';
}

status walk_maze(sElemType *curpos, Stack s)
{
	int di;
	sElemType e;
	sElemType d;
	do
	{
		if(pass(*curpos))
		{
			e = *curpos;
			foot_print(*curpos);
			++(*curpos).ord;
			push(&s, *curpos);
			if((*curpos).seat.x == 8 && (*curpos).seat.y == 7)
				return 1;
			di = explore(curpos);
		}
		else
		{
			if(!stack_is_empty(s))
			{
				pop(&s, &d);
				*curpos = d;
				foot_delete(*curpos);
			}
			while(di == 0 && !stack_is_empty(s))
			{
				di = explore(curpos);
				pop(&s, &d);
				*curpos = d;
			}
		}
	}while(!stack_is_empty(s));

	return 0;
}

int explore(sElemType *e)
{
	if(matrix.map[(*e).seat.x][(*e).seat.y+1] == ' ')
	{
		(*e).seat.y = (*e).seat.y+1;
		printf("(%d, %d)->", (*e).seat.y, (*e).seat.x);
		/* printf("right!\t\t"); */
		return 1;
	}
	if(matrix.map[(*e).seat.x+1][(*e).seat.y] == ' ')
	{
		(*e).seat.x = (*e).seat.x+1;
		printf("(%d, %d)->", (*e).seat.y, (*e).seat.x);
		/* printf("down!\t\t"); */
		return 2;
	}
	if(matrix.map[(*e).seat.x][(*e).seat.y-1] == ' ')
	{
		(*e).seat.y = (*e).seat.y-1;
		printf("(%d, %d)->", (*e).seat.y, (*e).seat.x);
		/* printf("left!\t\t"); */
		return 3;
	}
	if(matrix.map[(*e).seat.x-1][(*e).seat.y] == ' ')
	{
		(*e).seat.x = (*e).seat.x-1;
		printf("(%d, %d)->", (*e).seat.y, (*e).seat.x);
		/* printf("up!\t\t"); */
		return 4;
	}
	return 0;
}
