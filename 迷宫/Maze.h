#pragma once
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

#define N 6
typedef struct Pos
{
	int row;//行
	int col;//列
}Pos;
typedef struct Maze
{
	int maz[N][N];//迷宫的数组
	Pos entry;//入口
}Maze;
typedef struct Pos Datatype;
typedef struct stack
{
	Datatype *array;
	int top;//栈顶
	int end;
	int capcity;
}Stack;

void StackInit(Stack *st);//初始化栈
void StackPush(Stack *st, Datatype x);//入栈
Datatype StackTop(Stack *st);//出栈顶元素
void StackPop(Stack *st);//出栈
int StackEmpty(Stack *st);//栈是否为空，不为空返回1，否则返回0

void MazaInit(Maze *m,int maz[][N]);//对迷宫的初始化
void MazeGetPath(Maze *m);
void MazePrint(Maze *m);//打印迷宫