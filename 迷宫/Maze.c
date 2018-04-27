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
//���Թ�
void MazeGetPath(Maze *m)
{
	Pos cur, next;
	Stack st;
	StackInit(&st);
	StackPush(&st,m->entry);//�������ջ
	m->maz[m->entry.row][m->entry.col] = 2;
	while (StackEmpty(&st))//ջ��Ϊ��
	{
		cur = StackTop(&st);//��cur��Ϊջ��Ԫ��
		if (cur.col == N - 1)
		{
			printf("�ҵ�ͨ·\n");
			return;
		}
		//cur���ֿ���
		//1.���
		//2.��һ�������ߵ�λ��
		//3.���ݵ���һ��λ��

		//��
		next = cur;
		next.row -= 1;
		if (CheckIsAccess(m, next) == 1)
		{
			StackPush(&st, next);
			m->maz[next.row][next.col] = 2;//���߹�������Ϊ2�����û�����ã������ڴ�λ��һֱѭ��
			continue;
		}
		//��
		next = cur;//��Ϊ�ڡ��ϡ�ʱnextֵ�Ѿ��ı� 
		next.row += 1;
		if (CheckIsAccess(m, next) == 1)
		{
			StackPush(&st, next);
			m->maz[next.row][next.col] = 2;
			continue;
		}
		//��
		next = cur;
		next.col -= 1;
		if (CheckIsAccess(m, next) == 1)
		{
			StackPush(&st, next);
			m->maz[next.row][next.col] = 2;
			continue;
		}
		//��
		next = cur;
		next.col += 1;
		if (CheckIsAccess(m, next) == 1)
		{
			StackPush(&st, next);
			m->maz[next.row][next.col] = 2;
			continue;
		}
		//˵���������Ҿ�û�г�·����Ҫ����
		m->maz[cur.row][cur.col] = 3;//�����ݵ�����Ϊ3
		StackPop(&st);
	}	
}

void MazePrint(Maze *m)//��ӡ�Թ�
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
	//�������
	m->entry.col = 2;//��
	m->entry.row = 5;//��
}

void StackPop(Stack *st)//��ջ
{
	if (st->top < st->end)
		return;
	else
	
		st->top--;
		
}
Datatype StackTop(Stack *st)//��ջ��Ԫ��
{
	return st->array[st->top - 1];
}
void StackPush(Stack *st, Datatype x)//��ջ
{
	if ((st->top) == st->capcity)
	{
		//����
		st->array = (Datatype *)realloc(st->array, sizeof(Datatype) *st->capcity * 2);
		st->capcity = st->capcity * 2;
	}
	st->array[st->top] = x;
	st->top++;
}
int StackEmpty(Stack *st)//ջ�Ƿ�Ϊ�գ���Ϊ�շ���1�����򷵻�0
{
	if (st->top == st->end)
		return 0;
	else
		return 1;
}
void StackInit(Stack *st)//��ʼ��ջ
{
	st->array = (Datatype *)malloc(sizeof(Datatype) * 3);
	st->end = 0;
	st->top = 0;
	st->capcity = 3;
}