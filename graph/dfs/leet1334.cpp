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
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
using namespace std;


int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int, int>>> graph(n);
    for(auto& edge : edges){
        int a = edge[0], b = edge[1], w = edge[2];
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }
    vector<int> visited(n, 0);
    function<void(int, int, set<int>&)> dfs = [&](int node, int sum, set<int>& get){
        if(sum > distanceThreshold)return;
        visited[node] = 1;
        if(get.count(node) == 0){
            get.insert(node);
        }
        for(auto & son : graph[node]){
            int b = son.first, w = son.second;
            if(!visited[b]){
                dfs(b, sum+w, get);
            }
        }
        visited[node] = 0;

    };
    int index = 0, num = INT_MAX;
    for(int i = 0; i < n; i++){
        set<int> get = {i};
 
        dfs(i, 0, get);
        int temp = get.size()-1;
        if(temp <= num){
            num = temp;
            index = i; 
        }
    }
    return index;
}
int main(){
    vector<vector<int>> edges = {{0,1, 3},{1,2,1},{1,3,4},{2,3,1}};
    findTheCity(4, edges, 4);
}