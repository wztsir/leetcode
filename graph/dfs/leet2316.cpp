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
#include<functional>
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
// #include"TreeNode.h"
using namespace std;
long long countPairs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> map(n);
    for(auto& edge : edges){
        
        int a = edge[0], b = edge[1];
        map[a].push_back(b);
        map[b].push_back(a);
    }
    vector<int> visited(n);
    function<int(int)> dfs = [&](int node) -> int{
        visited[node] = 1;
        int size = 1;
        for(auto& n : map[node]){
            if(visited[n] == 0)size += dfs(n);//必须显示声明返回值类型
        }
        return size;
    };
    int num_node = 0;
    long long res = 0;
    for(int i = 0; i < n; ++i){
        if(visited[i] == 0){
            int s = dfs(i);
            res +=(long long) s * num_node;
            num_node += s;
        }
    }
    return res;
}