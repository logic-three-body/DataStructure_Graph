#include<iostream>
using namespace std;
#define OK 0
#define ERROR -1
#define MAX 100
#define TRUE 1
#define FALSE 0
typedef struct LNode
{
	int vdata;
	struct LNode *next;
}LNode, *LinkList;
typedef struct
{
	int vexnum;
	int arcnum;
	LinkList V[MAX];
}ALGragh;
int CreateUDN(ALGragh &G, int vexnum, int arcnum)
{
	G.vexnum = vexnum;
	G.arcnum = arcnum;
	if (G.vexnum > MAX)
		return ERROR;
	for (int i = 1; i <= vexnum; i++)
	{
		G.V[i] = new LNode;
		G.V[i]->vdata = i;
		G.V[i]->next = NULL;
	}
	while (arcnum--)
	{
		int x, y;
		cin >> x >> y;
		LinkList p = new LNode;
		p->vdata = y;
		p->next = G.V[x]->next;
		G.V[x]->next = p;
		LinkList q = new LNode;
		q->vdata = x;
		q->next = G.V[y]->next;
		G.V[y]->next = q;
	}
	return OK;
}

int CreateUDN_Tail(ALGragh &G, int vexnum, int arcnum)
{
	G.vexnum = vexnum;
	G.arcnum = arcnum;
	if (G.vexnum > MAX)
		return ERROR;
	for (int i = 1; i <= vexnum; i++)
	{
		G.V[i] = new LNode;
		G.V[i]->vdata = i;
		G.V[i]->next = NULL;
	}
	while (arcnum--)
	{
		int x, y;
		cin >> x >> y;
		LinkList p = new LNode;
		LinkList t = G.V[x];
		p->vdata = y;
		while (t->next)
		{
			t = t->next;
		}
		p->next = t->next;
		t->next = p;

		LinkList q = new LNode;
		t = G.V[y];
		q->vdata = x;
		while (t->next)
		{
			t = t->next;
		}
		q->next = t->next;
		t->next = q;
	}
	return OK;
}

int DFS_AL(ALGragh G)
{
	int d, top = 0, visit[MAX], Stack[MAX];
	for (int i = 0; i < MAX; i++)
		visit[i] = 0;
	cin >> d;
	cout << d;
	Stack[top++] = d;
	visit[d] = 1;
	while (top > 0)
	{
		int t = -1;
		LinkList p = G.V[Stack[top - 1]];
		while (p)
		{
			if (!visit[p->vdata])
				t = p->vdata;
			p = p->next;
		}
		if (t == -1)
			top--;
		else
		{
			cout << " " << t;
			Stack[top++] = t;
			visit[t] = 1;
		}
	}
	cout << endl;
	return OK;
}

bool visited[MAX]; /* 访问标志的数组 */


/* 邻接表的深度优先递归算法 */
void DFS(ALGragh GL, int i)
{
	LinkList p=nullptr;
	visited[i] = TRUE;


	printf("%d ", GL.V[i]->vdata);/* 打印顶点,也可以其它操作 */

	  


	p = GL.V[i];
	while (p)
	{
		if (!visited[p->vdata])
			DFS(GL, p->vdata);/* 对为访问的邻接顶点递归调用 */
		p = p->next;
	}
}

/* 邻接表的深度遍历操作 */
void DFSTraverse(ALGragh GL)
{
	int start = 0;
	std::cin >> start;
	int i;
	for (i = 0; i < GL.vexnum; i++)
		visited[i]=FALSE;/* 初始所有顶点状态都是未访问过状态 */
	//printf("%d", GL.V[start]->vdata);
	//visited[GL.V[start]->vdata] = TRUE;
	DFS(GL, GL.V[start]->vdata);
}
int main()
{
	int n, m;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		ALGragh G;
		CreateUDN_Tail(G, n, m);
		//DFS_AL(G);
		DFSTraverse(G);
		std::cout << endl;
	}
	return 0;
}