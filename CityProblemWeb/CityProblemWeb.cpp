
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>

using namespace std;

const int Infinity = 6553333;

int Path[500][500];
int Distance[500];
int visited[500];
int VEX, EDGE;
int ShorestD[500];

struct Node
{
	int Number;
	char Name;
}node[10000];

void DIS(int x)
{
	int i;
	int j;
	int ans;
	int v;
	ans = Infinity;
	Distance[x] = 0;
	visited[x] = 1;
	for (i = 0; i < VEX; i++)
	{
		Distance[i] = Path[x][i];
	}
	for (j = 0; j < VEX + 7; j++)
	{
		for (i = 0; i < VEX; i++)
		{
			if (Distance[i] < ans && !visited[i])
			{
				ans = Distance[i];
				v = i;

			}

		}
		visited[v] = 1;
		ans = Infinity;
		for (i = 0; i < VEX; i++)
		{
			if (Distance[v] + Path[v][i] < Distance[i])
			{
				Distance[i] = Distance[v] + Path[v][i];
				ShorestD[i] = v;
			}
		}
	}
}

void print(int n)
{
	if (ShorestD[n] == n)
	{
		cout << node[n].Name;
		return;
	}
	print(ShorestD[n]);
	cout << " " << node[n].Name;
	return;
}

int main()
{
	char ch1, ch2;
	int i, j;
	int a, b;
	int x, y;
	while (cin >> VEX)
	{
		a = b = x = y = 0;
		memset(Distance, Infinity, sizeof(Distance));
		memset(visited, 0, sizeof(visited));
		for (i = 0; i < 250; i++)
			for (j = 0; j < 250; j++)
			{
				if (i != j)
					Path[i][j] = Infinity;
				else
					Path[i][j] = 0;
			}

		cin >> EDGE;
		if (VEX == 0 && EDGE == 0)
			break;
		for (i = 0; i < VEX; i++)
		{
			cin >> node[i].Name;
			node[i].Number = i;
		}
		for (i = 0; i < EDGE; i++)
		{

			cin >> ch1 >> ch2;
			for (j = 0; j < VEX; j++)
			{
				if (node[j].Name == ch1)
					a = node[j].Number;
				if (node[j].Name == ch2)
					b = node[j].Number;
			}
			cin >> Path[a][b];
			Path[b][a] = Path[a][b];
		}

		cin >> ch1 >> ch2;
		for (j = 0; j < VEX; j++)
		{
			if (node[j].Name == ch1)
				x = node[j].Number;
			if (node[j].Name == ch2)
				y = node[j].Number;
		}
		for (j = 0; j < VEX; j++)
		{
			ShorestD[j] = x;
		}
		DIS(x);
		if (Distance[y] < Infinity)
			cout << Distance[y] << endl;
		else
			cout << "-1\n";
		print(y);
		cout << endl;

	}


	return 0;
}
