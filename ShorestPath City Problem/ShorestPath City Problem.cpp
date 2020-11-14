#include<iostream>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXEDGE 200
#define MAXVEX 200
#define INFINITY 65535

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char GElemType;

typedef struct
{
	GElemType vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];    /* 用于存储最短路径下标的数组 */
typedef int ShortPathTable[MAXVEX];/* 用于存储到各点最短路径的权值和 */

/* 构件图 */
void CreateMGraph(MGraph *G)
{
	int i=0, j=0;

	/* printf("请输入边数和城市个数（顶点数）:"); */

	///G->numEdges = 16;
	///G->numVertexes = 9;
	//TODO 输入城市个数和边数
	std::cin >> G->numVertexes;
	std::cin >> G->numEdges;

	if (!G->numEdges&&!G->numVertexes)
	{
		return;
	}
	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		///G->vexs[i] = i;
		//TODO 输入城市名字
		std::cin >> G->vexs[i];//输入城市名字
	}

	//TODO 输入城市间权值
	for (i = 0; i < G->numVertexes; i++)/* 初始化图 */
	{
		for (j = 0; j < G->numVertexes; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}

	}

	for (i = 0; i < G->numEdges; i++)
	{
		GElemType row = 0, col = 0;
		int Distance = 0;
		std::cin >> row >> col >> Distance;
		G->arc[row - 'A'][col - 'A'] = Distance;
		G->arc[col - 'A'][row - 'A'] = Distance;
	}

	//G->arc[0][1] = 1;
	//G->arc[0][2] = 5;
	//G->arc[1][2] = 3;
	//G->arc[1][3] = 7;
	//G->arc[1][4] = 5;

	//G->arc[2][4] = 1;
	//G->arc[2][5] = 7;
	//G->arc[3][4] = 2;
	//G->arc[3][6] = 3;
	//G->arc[4][5] = 3;

	//G->arc[4][6] = 6;
	//G->arc[4][7] = 9;
	//G->arc[5][7] = 5;
	//G->arc[6][7] = 2;
	//G->arc[6][8] = 7;

	//G->arc[7][8] = 4;


	//for (i = 0; i < G->numVertexes; i++)
	//{
	//	for (j = i; j < G->numVertexes; j++)
	//	{
	//		//G->arc[j][i] = G->arc[i][j];

	//	}
	//}

}

/*  Dijkstra算法，求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v] */
/*  P[v]的值为前驱顶点下标,D[v]表示v0到v的最短路径长度和 */
/**/
void ShortestPath_Dijkstra(MGraph G, int start, Patharc *P, ShortPathTable *D)
{
	int v, w, k, min;
	int final[MAXVEX];/* final[w]=1表示求得顶点v0至vw的最短路径 */
	for (v = 0; v < G.numVertexes; v++)    /* 初始化数据 */
	{
		final[v] = 0;			/* 全部顶点初始化为未知最短路径状态 */
		(*D)[v] = G.arc[start][v];/* 将与v0点有连线的顶点加上权值 */
		(*P)[v] = start;				/* 初始化路径数组P为  */
	}

	(*D)[start] = 0;  /* v0至v0路径为0 */
	final[start] = 1;    /* v0至v0不需要求路径 */
	/* 开始主循环，每次求得v0到某个v顶点的最短路径 */
	for (v = 1; v < G.numVertexes; v++)
	{
		min = INFINITY;    /* 当前所知离v0顶点的最近距离 */
		for (w = 0; w < G.numVertexes; w++) /* 寻找离v0最近的顶点 */
		{
			if (!final[w] && (*D)[w] < min)   //final判断是否到最后          
			{
				k = w;
				min = (*D)[w];    /* w顶点离v0顶点更近 */
			}
		}
		final[k] = 1;    /* 将目前找到的最近的顶点置为1 */
		for (w = 0; w < G.numVertexes; w++) /* 修正当前最短路径及距离 */
		{
			/* 如果经过v顶点的路径比现在这条路径的长度短的话 */
			if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
			{ /*  说明找到了更短的路径，修改D[w]和P[w] */
				(*D)[w] = min + G.arc[k][w];  /* 修改当前路径长度 */
				(*P)[w] = k;        //找出相应顶点编号
			}
		}
	}



}

void OutPut(MGraph G, Patharc &P, ShortPathTable &D, int start, int end)
{
	printf("%d\n", D[end]);


	int len = G.numVertexes;
	char *tmp = new char[len];

	int k = len - 1;
	while (end != start)
	{
		tmp[k--] = G.vexs[end];
		end = P[end];
	}
	tmp[k] = G.vexs[end];
	while (k < len)
	{
		if (k == len - 1)
		{
			printf("%c", tmp[k++]);
		}
		else
		{
			printf("%c ", tmp[k++]);
		}
	}
	printf("\n");
}

int main(void)
{

	MGraph G;
	Patharc P;
	ShortPathTable D; /* 求某点到其余各点的最短路径 */
	char start = 0, end = 0;

	while (true)
	{
		CreateMGraph(&G);
		
		if (!G.numEdges && !G.numVertexes)
		{
			return 0;
		}
		std::cin >> start >> end;
		ShortestPath_Dijkstra(G, start - 'A', &P, &D);
		//TODO 输出指定最短路径长度	
        //TODO 输出指定最短路径
		OutPut(G, P, D, start - 'A', end - 'A');
	}





	return 0;
}


// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
