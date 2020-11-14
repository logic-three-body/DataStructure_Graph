#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const int N = 1e5 + 7;
const int inf = 0x3f3f3f3f;
string s1;
int n, m;
int flag[N];
vector<int>ans[N];
struct {
	int u, v, w;
}e[N];
int head[N], cnt;
void add(int u, int v, int w) {
	e[cnt].u = head[u];
	e[cnt].v = v;
	e[cnt].w = w;
	head[u] = cnt++;//存u（顶点）-v边编号
}
int dis[N];
vector<int>p;
void dijstra(int s, int t) 
{
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < p.size(); i++)
	{
		dis[p[i]] = inf;
		ans[p[i]].push_back(s);
	}
	flag[s] = 1;
	for (int i = head[s]; i != -1; i = e[i].u)
	{
		int to = e[i].v;
		dis[to] = e[i].w;
	}
	for (int i = 1; i <= n; i++)
	{
		int minn = inf, u = -1;
		for (int j = 0; j < p.size(); j++)
		{
			if (dis[p[j]] == inf || flag[p[j]])continue;
			if (minn > dis[p[j]]) {
				minn = dis[p[j]];
				u = p[j];
			}
		}
		if (u == -1)continue;
		flag[u] = 1;
		for (int j = head[u]; j != -1; j = e[j].u)
		{
			if (dis[e[j].v] > dis[u] + e[j].w) 
			{
				dis[e[j].v] = dis[u] + e[j].w;
				ans[e[j].v].push_back(u);
			}
		}
	}
}
int main()
{
	while (cin>>n>>m) {
		cnt = 0;
		if (!n && !m)break;
		for (int i = 0; i < 30; i++)head[i] = -1;
		for (int i = 0; i < n; i++)
		{
			char x;
			cin >> x;
			int j = int(x - 'A');
			p.push_back(j); 
		}
		while (m--) {
			char x, y;
			int u, v, w;
			cin >> x >> y >> w;
			u = int(x - 'A');
			v = int(y - 'A');
			add(u, v, w);
			add(v, u, w);
		}char x, y;
		cin >> x >> y;
		int s = int(x - 'A');
		int t = int(y - 'A');/*
		for (int i = 0; i < p.size(); i++)
		{
			for (int j = head[i]; j != -1; j = e[j].u) {
				cout << char('A'+i )<< " " << char('A'+e[j].v) << " " << e[j].w<<endl;
			}
		}*/
		dijstra(s, t);
		cout << dis[t] << endl;
		for (int i = 0; i < ans[t].size(); i++)
		{
			cout << char('A' + ans[t][i]); cout << " ";
		}cout << y << endl;
		for (int i = 0; i < p.size(); i++)
		{
			ans[p[i]].clear();
		}p.clear();
	}
	return 0;
}