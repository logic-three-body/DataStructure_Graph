#include <iostream>
#include <cstring>
#define MVNum 100
using namespace std;

typedef struct
{
	char vexs[MVNum];//点集 
	int arcs[MVNum][MVNum];//边的邻接矩阵 
	int vexnum, arcnum;//点数&边数 
}MGraph;

int LocateVex(MGraph G, char u)
{//存在则返回u在顶点表中的下标;否则返回-1
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (u == G.vexs[i])
			return i;
	return -1;
}

void InitM(MGraph &G)
{//初始化图 
	memset(G.vexs, 0, sizeof(G.vexs));//初始化顶点集 
	memset(G.arcs, 0, sizeof(G.arcs));//初始化边的邻接矩阵 
	return;
}

void DelMG(MGraph &G)
{
	char vd;
	cin >> vd;
	//cout<<"待删除结点:"<<vd<<"位置："<<LocateVex(G,vd)<<endl;
	int position = LocateVex(G, vd);
	//先调整关系矩阵
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)    //将关系矩阵向内紧缩（顶点将要移动）
		{
			if (i > position && j > position)
				G.arcs[i - 1][j - 1] = G.arcs[i][j];
			else if (i > position)
				G.arcs[i - 1][j] = G.arcs[i][j];
			else if (j > position)
				G.arcs[i][j - 1] = G.arcs[i][j];
		}
	}
	for (int i = LocateVex(G, vd); i < G.vexnum; i++)
	{
		G.vexs[i] = G.vexs[i + 1];
	}
	G.vexnum--;
	//cout<<"点集："; 
//	for(int i=0;i<G.vexnum;i++)
//		cout<<G.vexs[i];
//	cout<<endl;	

	return;
}

int CreateMG(MGraph &G)
{
	int i, j, k;
	int vn = 0;//已录入顶点数 
	for (k = 0; k < G.arcnum; k++)//将边录入邻接矩阵，顺便将顶点录入 
	{
		char v1, v2;
		cin >> v1 >> v2;//边的端点
		int tag = 0;
		//先将顶点录入点集
		for (i = 0; i < G.vexnum; i++)//比较当前待录入顶点与点集中的点，不重复则录入 
		{
			if (v1 == G.vexs[i])tag = 1;
		}// 要遍历整个点集才知道有没有重复，设置一个标志位tag
		if (tag == 0)
		{
			G.vexs[vn] = v1;//不重复则录入 
		//	cout<<v1<<"已录入点集"<<endl;
			vn++;//已录入顶点数加1 
		}
		tag = 0;//标志位归零 
		for (i = 0; i < G.vexnum; i++)
		{
			if (v2 == G.vexs[i])tag = 1;
		}
		if (tag == 0)
		{
			G.vexs[vn] = v2;
			//cout<<v2<<"已录入点集"<<endl;
			vn++;
		}
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.arcs[i][j] = 1;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return 1;
}

void OutPut(MGraph &G)
{//输出矩阵 
	int i; int j;
	//输出表头 
	cout << 0 << " ";
	for (int i = 0, j; i < G.vexnum; i++)
	{
		cout << G.vexs[i];
		if (i != G.vexnum - 1)cout << " ";
	}
	cout << endl;
	for (i = 0; i < G.vexnum; i++)
	{
		//输出表头 
		cout << G.vexs[i];
		if (i != G.vexnum)cout << " ";
		//输出内容 
		for (j = 0; j < G.vexnum; j++)
		{
			cout << G.arcs[i][j];
			if (j != G.vexnum - 1)cout << " ";
		}
		cout << endl;
	}
}

int main()
{
	while (1)
	{
		MGraph G;
		InitM(G);
		cin >> G.vexnum >> G.arcnum;
		if (G.vexnum == 0 && G.arcnum == 0)break;
		CreateMG(G);
		//CA(G);
//		while(G.vexnum)
//		{
//			cout<<"-------"<<G.vexnum<<"-------"<<endl;
		DelMG(G);
		OutPut(G);
		//		 } 
	}

	return 0;
}
