#include"Maze.h"

int main()
{

	Maze m;
	int a[N][N] = {
		{ 0,0,0,0,0,0 },
		{ 0,0,1,1,1,1 },
		{ 0,0,1,0,0,0 },
		{ 0,0,1,0,0,0 },
		{ 0,0,1,1,1,1 },
		{ 0,0,1,0,0,0 }
	};
    MazaInit(&m,a);
	MazePrint(&m);
	MazeGetPath(&m);
	MazePrint(&m);
	system("pause");
	return 0;
}
int CheckIsAccess(Maze *m, Pos next)
{
	if (next.col >= 0 && next.col < N
		&&next.row >= 0 && next.row < N
		&& m->maz[next.row][next.col] == 1)
		return 1;
	else
		return 0;
}
//走迷宫
void MazeGetPath(Maze *m)
{
	Pos cur, next;
	Stack st;
	StackInit(&st);
	StackPush(&st,m->entry);//将入口入栈
	m->maz[m->entry.row][m->entry.col] = 2;
	while (StackEmpty(&st))//栈不为空
	{
		cur = StackTop(&st);//将cur设为栈顶元素
		if (cur.col == N - 1)
		{
			printf("找到通路\n");
			return;
		}
		//cur三种可能
		//1.入口
		//2.下一个可以走的位置
		//3.回溯的上一个位置

		//上
		next = cur;
		next.row -= 1;
		if (CheckIsAccess(m, next) == 1)
		{
			StackPush(&st, next);
			m->maz[next.row][next.col] = 2;//将走过的设置为2，如果没有设置，将会在此位置一直循环
			continue;
		}
		//下
		next = cur;//因为在“上”时next值已经改变 
		next.row += 1;
		if (CheckIsAccess(m, next) == 1)
		{
			StackPush(&st, next);
			m->maz[next.row][next.col] = 2;
			continue;
		}
		//左
		next = cur;
		next.col -= 1;
		if (CheckIsAccess(m, next) == 1)
		{
			StackPush(&st, next);
			m->maz[next.row][next.col] = 2;
			continue;
		}
		//右
		next = cur;
		next.col += 1;
		if (CheckIsAccess(m, next) == 1)
		{
			StackPush(&st, next);
			m->maz[next.row][next.col] = 2;
			continue;
		}
		//说明上下左右均没有出路，需要回溯
		m->maz[cur.row][cur.col] = 3;//将回溯的设置为3
		StackPop(&st);
	}	
}

void MazePrint(Maze *m)//打印迷宫
{
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d  ", m->maz[i][j]);
		printf("\n");
	}
}
void MazaInit(Maze *m,int maz[][N])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		  m->maz[i][j] = maz[i][j];
	}
	//设置入口
	m->entry.col = 2;//列
	m->entry.row = 5;//行
}

void StackPop(Stack *st)//出栈
{
	if (st->top < st->end)
		return;
	else
	
		st->top--;
		
}
Datatype StackTop(Stack *st)//出栈顶元素
{
	return st->array[st->top - 1];
}
void StackPush(Stack *st, Datatype x)//入栈
{
	if ((st->top) == st->capcity)
	{
		//扩容
		st->array = (Datatype *)realloc(st->array, sizeof(Datatype) *st->capcity * 2);
		st->capcity = st->capcity * 2;
	}
	st->array[st->top] = x;
	st->top++;
}
int StackEmpty(Stack *st)//栈是否为空，不为空返回1，否则返回0
{
	if (st->top == st->end)
		return 0;
	else
		return 1;
}
void StackInit(Stack *st)//初始化栈
{
	st->array = (Datatype *)malloc(sizeof(Datatype) * 3);
	st->end = 0;
	st->top = 0;
	st->capcity = 3;
}