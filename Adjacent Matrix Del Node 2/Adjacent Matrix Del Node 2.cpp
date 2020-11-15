﻿#include<iostream>
using namespace std;
#define OK 0
#define ERROR -1
#define MAX 100
typedef struct AMGragh
{
	int vexnum;
	int arcnum;
	int vexs[MAX][MAX];
}AMGragh;
int CreateUDN(AMGragh &G, int vexnum, int arcnum)
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
int DeleteVex(AMGragh &G)
{
	int i, j, x;
	cin >> x;
	for (i = 0; i <= G.vexnum; i++)
		for (j = x; j < G.vexnum; j++)//把删除的点移出去，但只适用于删除最后的点
			G.vexs[i][j] = G.vexs[i][j + 1];
	for (j = 0; j <= G.vexnum; j++)
		for (i = x; i < G.vexnum; i++)
			G.vexs[i][j] = G.vexs[i + 1][j];
	G.vexnum--;
	return OK;
}
int OutputUDN(AMGragh G)
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
		AMGragh G;
		CreateUDN(G, n, m);
		DeleteVex(G);
		OutputUDN(G);
	}
	return 0;
}