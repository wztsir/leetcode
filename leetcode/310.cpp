#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
//int main() {
//	float f1 = 8765.4, f2 = 8765.4;
//	double d1 = 8765.4, d2 = 8765.4;
//	printf("%f\n%f", f1 * f2, d1 * d2);
//	string s;
//	getline(cin, s);
//	printf("不能直接打印C++风格的字符串，但是可以用c_str()%s", s.c_str());
//	//char*类型的可以直接用构造函数或者赋值
//	int a;
//	float b;
//	double c;
//	char d;
//	char* e = new char[10];
//	scanf_s("%d%f%lf", &a, &b, &c);
//}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	if (n == 1)return { 0 };
	vector<vector<int>> map(n);//除了指针需要用赋值分配空间，普通的就直接构造函数就可以分配了
	for (int i = 0; i < edges.size(); i++) {
		int a = edges[i][0], b = edges[i][1];
		map[a].push_back(b);
		map[b].push_back(a);
	}
	vector<int> leafs;
	for (int i = 0; i < n; i++) {
		if (map[i].size() == 1) {
			leafs.push_back(i);
		}
	}
	int total = n;
	while (total > 2) {
		total -= leafs.size();
		vector<int> newleafs;
		for (auto leaf : leafs) {
			int nibor = map[leaf][0];
			map[nibor].erase(find(map[nibor].begin(), map[nibor].end(), leaf));//很巧妙，最后删除的过程中存在叶子的情况
			if (map[nibor].size() == 1)newleafs.push_back(nibor);
		}
		leafs = newleafs;
	}
	return leafs;

}

//int main() {
//	int n = 6;
//	vector<vector<int>> node = { {3, 0},{3, 1},{3, 2},{3, 4},{5, 4} };
//	findMinHeightTrees(n, node);
//}