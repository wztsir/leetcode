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
//	printf("����ֱ�Ӵ�ӡC++�����ַ��������ǿ�����c_str()%s", s.c_str());
//	//char*���͵Ŀ���ֱ���ù��캯�����߸�ֵ
//	int a;
//	float b;
//	double c;
//	char d;
//	char* e = new char[10];
//	scanf_s("%d%f%lf", &a, &b, &c);
//}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	if (n == 1)return { 0 };
	vector<vector<int>> map(n);//����ָ����Ҫ�ø�ֵ����ռ䣬��ͨ�ľ�ֱ�ӹ��캯���Ϳ��Է�����
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
			map[nibor].erase(find(map[nibor].begin(), map[nibor].end(), leaf));//��������ɾ���Ĺ����д���Ҷ�ӵ����
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