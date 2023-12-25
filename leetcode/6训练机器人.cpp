#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
int res;
int b_u, b_v;
vector<int> up = { -1,1,0,0 };
vector<int> l = { 0,0,-1,1 };

bool fencha(int u, int v, vector<string>& map) {
	int k =0;
	for (int i = 0; i<up.size(); i++) {
		int w = u + up[i];
		int z = v + l[i];
		if (w < 0 || w >= map.size() || z < 0 || z >= map[0].size())continue;
		if (map[w][z] != 'X')k++;
	}
	if (u == b_u && v == b_v)k++;
	k--;
	return k >= 2;
}
bool dfs(int u, int v, vector<string>& map, vector<vector<bool>>& used) {
	if (u < 0 || u >= map.size() || v < 0 || v >= map[0].size())return false;
	if (used[u][v])return false;
	if (map[u][v] == 'T')return true;
	if (map[u][v] == 'X')return false;
	bool t = fencha(u, v, map);
	if (t)res++;
	used[u][v] = true;
	for (int i = 0; i < 4; i++) {
		if(dfs(u + up[i], v + l[i], map,used))return true;
	}
	used[u][v] = false;
	if (t)res--;
	return false;
}
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		res = 0;
//		int n, m;
//		cin >> n >> m;
//		vector<string> map(n);
//		vector<vector<bool>> used(n, vector <bool>(m, false));
//		for (int i = 0; i < n; i++) {
//			cin >> map[i];
//		}
//		for (int i = 0; i < n; i++) {
//			int f = 0;
//			for (int j = 0; j < m; j++) {
//				if (map[i][j] == 'R') {
//					f = 1;
//					b_u = i, b_v = j;
//					break;
//				}
//			}
//			if (f)break;
//		}
//		dfs(b_u, b_v,map, used);
//		cout << res << endl;
//	}
//}
//2
//2 3
//T.R
//.X.
//3 3
//...
//XRX
//..T