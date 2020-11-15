#include<iostream>
using namespace std;
//图
bool map[1000][1000];//横纵坐标用ascii码存储
bool book[1000];//标记这个点是否被遍历过 

bool DFS(int a, int b) { //深度优先搜索判断两个点之间是否存在路径
	book[a] = true;
	if (map[a][b]) {
		return true;//如果相同直接返回
	}
	bool HasRoad = false;
	for (int i = 0; i < 1000; i++) {
		//深度优先搜索 
		if (map[a][i] && !book[i]) {
			HasRoad = (HasRoad || DFS(i, b));
		}
	}
	return HasRoad;
}

int main() {
	int n, m;//顶点，边
	while (cin >> n >> m && (n || m)) {
		//初始化
		for (int i = 0; i < 1000; i++) {
			book[i] = false;
			for (int j = 0; j < 1000; j++) {
				map[i][j] = false;
			}
		}
		//读入
		char t;
		for (int i = 0; i < n; i++) {
			cin >> t;
		}
		for (int i = 0; i < m; i++) {
			char a, b;
			cin >> a >> b;
			map[(int)a][(int)b] = map[(int)b][(int)a] = true;
		}
		char searcha, searchb;
		cin >> searcha >> searchb;
		if (DFS((int)searcha, (int)searchb)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}


	return 0;
}