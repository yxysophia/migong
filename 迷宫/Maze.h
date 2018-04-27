#pragma once
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

#define N 6
typedef struct Pos
{
	int row;//��
	int col;//��
}Pos;
typedef struct Maze
{
	int maz[N][N];//�Թ�������
	Pos entry;//���
}Maze;
typedef struct Pos Datatype;
typedef struct stack
{
	Datatype *array;
	int top;//ջ��
	int end;
	int capcity;
}Stack;

void StackInit(Stack *st);//��ʼ��ջ
void StackPush(Stack *st, Datatype x);//��ջ
Datatype StackTop(Stack *st);//��ջ��Ԫ��
void StackPop(Stack *st);//��ջ
int StackEmpty(Stack *st);//ջ�Ƿ�Ϊ�գ���Ϊ�շ���1�����򷵻�0

void MazaInit(Maze *m,int maz[][N]);//���Թ��ĳ�ʼ��
void MazeGetPath(Maze *m);
void MazePrint(Maze *m);//��ӡ�Թ�