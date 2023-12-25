#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
// #include"TreeNode.h"
using namespace std;
vector<vector<int>> tree;
vector<int> v;
long long dfs(int node, int p){
    if(tree[node].size() == 1 && node != 0)return v[node];
    long long res = 0;
    for(auto& son : tree[node]){
        if(son != p)res += dfs(son, node);
    }
    if(v[node] > res)return res;
    else return v[node];
}
long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
    int n = values.size();
    tree.resize(n);
    v=values;
    for(auto& edge : edges){
        int p = edge[0], s=edge[1];
        tree[p].push_back(s);
        tree[s].push_back(p);
    }
    long long total =accumulate(values.begin(), values.end(), 0LL);
    long long a = dfs(0, -1);
    return total - a;
}
int main(){
    vector<vector<int>> d={{2,0}, {4,1}, {5,3}, {4,6}, {2,4}, {5,2}, {5,7}};
    vector<int> v = {12,12,7,9,2,11,12,25};
    // {5,2,5,2,1,1};
    maximumScoreAfterOperations(d, v);
}

// [[2,0],[4,1],[5,3],[4,6],[2,4],[5,2],[5,7]]
// [12,12,7,9,2,11,12,25]