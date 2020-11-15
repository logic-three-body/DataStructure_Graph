#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAX 100
typedef struct MGragh
{
	int vexnum;
	int arcnum;
	int vexs[MAX][MAX];
}MGragh;
int CreateMG(MGragh &G, int vexnum, int arcnum)
{
	G.vexnum = vexnum;
	G.arcnum = arcnum;
	if (G.vexnum > MAX)
		return ERROR;
	for (int i = 0; i <= G.vexnum; i++)
		G.vexs[0][i] = G.vexs[i][0] = i;
	for (int i = 1; i <= G.vexnum; i++)
		for (int j = 1; j <= G.vexnum; j++)
			G.vexs[i][j] = 0;
	int h, k;
	for (int i = 1; i <= G.arcnum; i++)
	{
		cin >> h >> k;
		G.vexs[h][k] = G.vexs[k][h] = 1;
	}
	return OK;
}
int InsertVex(MGragh &G)
{
	if (G.vexnum + 1 > MAX)
		return ERROR;
	++G.vexnum;//顶点增一
	int x;
	cin >> x;
	G.vexs[0][G.vexnum] = G.vexs[G.vexnum][0] = x;
	for (int i = 1; i <= G.vexnum; i++)
		G.vexs[G.vexnum][i] = G.vexs[i][G.vexnum] = 0;
	//G.vexnum++;
	return OK;
}
int OutputMG(MGragh G)
{
	for (int i = 0; i <= G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			cout << G.vexs[i][j] << " ";
		cout << G.vexs[i][G.vexnum] << endl;
	}
	return OK;
}
int main()
{
	int n, m;
	while (cin >> n >> m && m != 0 && n != 0)
	{
		MGragh G;
		CreateMG(G, n, m);
		InsertVex(G);
		OutputMG(G);
	}
	return 0;
}