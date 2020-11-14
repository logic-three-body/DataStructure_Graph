#include<vector>
#include<iostream>

using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
const int inf = 0x3f3f3f3f;
int flag[N], dis[N];
vector<int>CityNam;
vector<int>path[N], cost[N];
vector<int>ans[N];
int n, m;
vector<int> dijsktra(int s, int t) {
	for (int i = 0; i < CityNam.size(); i++) {
		dis[CityNam[i]] = inf;
	}flag[s] = 1;
	for (int i = 0; i < path[s].size(); i++) {
		dis[path[s][i]] = cost[s][i];
		ans[path[s][i]].push_back(s);
	}
	for (int h = 1; h < n; h++) {
		int minn = inf, k = 0;
		for (int i = 0; i < CityNam.size(); i++) {
			if (dis[CityNam[i]] == inf || flag[CityNam[i]])continue;
			if (minn > dis[CityNam[i]]) {
				k = CityNam[i];
				minn = dis[CityNam[i]];
			}
		}
		flag[k] = 1;//标记已找过
		ans[k].push_back(k);
		for (int i = 0; i < path[k].size(); i++) {
			if (dis[path[k][i]] > dis[k] + cost[k][i]) {
				dis[path[k][i]] = dis[k] + cost[k][i];
				ans[path[k][i]].push_back(k);
			}
		}
	}
	return ans[t];
}

int main()
{
	while (cin >> n >> m) {
		if (!n && !m)break;
		memset(flag, 0, sizeof(flag));
		for (int i = 1; i <= n; i++)
		{
			char x;
			cin >> x;
			CityNam.push_back(x - 'A');
		}
		while (m--) {//输入节点以及对应权重
			char x, y;
			int d;
			cin >> x >> y >> d;
			int i = x - 'A', j = y - 'A';
			path[j].push_back(i);//原点到另一个点（下标）
			cost[j].push_back(d);//权重
			path[i].push_back(j);
			cost[i].push_back(d);
		}
		char x, y;//输入需要得出的路径
		cin >> x >> y;
		int s = x - 'A', t = y - 'A';
		vector<int>a = dijsktra(s, t);

		cout << dis[t] << endl;
		for (int i = 0; i < a.size(); i++) {
			cout << char('A' + a[i]);
			if (i == a.size() - 1)cout << endl;
			else cout << " ";
		}
		for (int i = 0; i < CityNam.size(); i++)ans[i].clear(), path[i].clear(), cost[i].clear();
		CityNam.clear();
	}
	return 0;
}
