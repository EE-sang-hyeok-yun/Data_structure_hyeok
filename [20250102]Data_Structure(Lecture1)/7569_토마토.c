#include <stdio.h>
#include <stdlib.h>

typedef struct POINT
{
	int i;
	int j;
	int k;
} POINT;

typedef struct NODE
{
	POINT Data;
	NODE* NextP;
} NODE;

typedef struct QUEUE
{
	NODE* FrontP;
	NODE* RearP;
	int Cnt;
};

void InitQueue(QUEUE* Queue)
{
	Queue->FrontP = NULL;
	Queue->RearP = NULL;
	Queue->Cnt = 0;
	return;
}
int IsEmpty(QUEUE* Queue)
{
	if (Queue->Cnt == 0)
		return 1;
	else
		return 0;
}
void EnQueue(QUEUE* Queue, POINT Data)
{
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	NewNode->Data = Data;
	NewNode->NextP = NULL;

	if (IsEmpty(Queue))
	{
		Queue->FrontP = NewNode;
	}
	else
	{
		Queue->RearP->NextP = NewNode;
	}
	Queue->RearP = NewNode;
	Queue->Cnt++;

	return;
}

POINT DeQueue(QUEUE* Queue)
{
	POINT Data;
	NODE* tmp;
	if (IsEmpty(Queue))
	{
		return { 0, 0, 0 };
	}
	tmp = Queue->FrontP;
	Data = tmp->Data;
	Queue->FrontP = tmp->NextP;
	free(tmp);
	Queue->Cnt--;
	return Data;
}

int Matrix [101][101][101];
int N, M, H;

const int VectI[6] = { -1,1,0,0,0,0 };
const int VectJ[6] = { 0,0,-1,1,0,0 };
const int VectK[6] = { 0,0,0,0,-1,1 };

void BFS(QUEUE* Queue)
{
	while (IsEmpty(Queue) == 0)
	{
		POINT tmp = DeQueue(Queue);

		for (int i = 0; i < 6; i++)
		{
			int I = tmp.i + VectI[i];
			int J = tmp.j + VectJ[i];
			int K = tmp.k + VectK[i];

			if ((I >= 0) && (J >= 0) && (K >= 0) && (I < N) && (J < M) && (K < H) && (Matrix[I][J][K] == 0))
			{
				Matrix[I][J][K] = Matrix[tmp.i][tmp.j][tmp.k] + 1;
				EnQueue(Queue, { I, J, K });
			}
		}
	}
	return;
}

int main(void)
{
	scanf("%d %d %d", &H, &M, &N);

	QUEUE Queue;
	InitQueue(&Queue);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < H; k++)
			{
				scanf("%d", &Matrix[i][j][k]);

				if (Matrix[i][j][k] == 1)
				{
					EnQueue(&Queue, { i, j ,k });
				}
			}
		}
	}

	BFS(&Queue);

	int Result = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < H; k++)
			{
				if (Matrix[i][j][k] == 0)
				{
					printf("-1");
					return 0;
				}
				if (Result < Matrix[i][j][k])
				{
					Result = Matrix[i][j][k];
				}
			}
		}
	}

	printf("%d", Result - 1);

	return 0;
}