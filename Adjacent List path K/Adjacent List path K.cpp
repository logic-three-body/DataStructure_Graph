#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define MaxSize 100
using namespace std;
typedef struct ArcNode
{
	int adjvex;                 //该边所指向的结点的位置（也就是编号）
	struct ArcNode *nextarc;    //指向下一条边的指针
	int info;                   //
}ArcNode;

typedef struct
{
	char data;                  //顶点信息
	ArcNode *firstarc;          //指向第一条边的指针
}VNode;
typedef struct
{
	VNode adjlist[MaxSize];
	int n, e;                    //顶点数、边数
}AGraph;                        //图的邻接表类型
int visit[MaxSize];
int Locate(AGraph *AG, char c)
{
	for (int i = 0; i < AG->n; i++)
	{
		if (AG->adjlist[i].data == c)
			return i;
	}
}
int nodenum = 0;
bool DFS(AGraph *G, int v, int w, int k)
{
	ArcNode *p;
	visit[v] = ++nodenum;
	if (v == w && k == 0)//置标志位1代表已访问
		return true;
	else
		if (k > 0)
		{
			p = G->adjlist[v].firstarc;
			while (p)
			{
				if (visit[p->adjvex] == 0 && DFS(G, p->adjvex, w, k - 1))
				{
					return true;
				}
				visit[p->adjvex] = 0;
				nodenum--;
				p = p->nextarc;
			}

		}
	return false;
}
//创建无向图的邻接表
void createAGraph2(AGraph *&AG, int t, int p)
{
	int i, j, k;
	ArcNode *q;
	AG->n = t;
	AG->e = p;
	string b;
	cin >> b;
	for (i = 0; i < AG->n; i++)
	{
		AG->adjlist[i].data = b[i];
		AG->adjlist[i].firstarc = NULL;
	}
	string cc;
	for (k = 0; k < AG->e; ++k)
	{
		cin >> cc;
		//头插法
		i = Locate(AG, cc[0]);
		j = Locate(AG, cc[1]);
		q = new ArcNode;
		q->adjvex = j;
		q->nextarc = AG->adjlist[i].firstarc;
		AG->adjlist[i].firstarc = q;

		q = new ArcNode;
		q->adjvex = i;
		q->nextarc = AG->adjlist[j].firstarc;
		AG->adjlist[j].firstarc = q;

	}
}

AGraph *AG;
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k && k != 0 || n != 0 || m != 0)
	{
		AG = new AGraph;
		createAGraph2(AG, n, m);
		string a;
		cin >> a;//查询的两个顶点

		if (DFS(AG, Locate(AG, a[0]), Locate(AG, a[1]), k))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}