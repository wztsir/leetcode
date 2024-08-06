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
vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
    // vector<vector<int>> graph(n, vector<int>(n, INT_MAX));  使用邻接矩阵会爆内存
    vector<vector<pair<int, int>>> graph(n);
    vector<int> dist(n, INT_MAX); // 初始化距离为最大值
    for(auto edge : edges){
        int x = edge[0], y = edge[1], d = edge[2];
        graph[x].push_back({y, d});
        graph[y].push_back({x, d});
        // graph[edge[0]][edge[1]] = min(edge[2], graph[edge[0]][edge[1]]);
        // graph[edge[1]][edge[0]] = min(edge[2], graph[edge[1]][edge[0]]);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dist[0] = 0;
    q.push({0, 0});
    while (!q.empty()){
        auto node = q.top();
        q.pop();
        int from = node.second, src = node.first;
        if (src > dist[from]) { // 消去重边，即dis[from]已经被更新过了，src已经过时的信息了，需要跳过这个点
            continue;
        }

        for(auto e : graph[from]){
            int to = e.first, d = e.second;
            if(dist[to] > dist[from] + d && disappear[to] > dist[from] + d){
                    dist[to] = dist[from] + d;
                    q.push({dist[to], to});
                
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(dist[i] == INT_MAX)dist[i] = -1;
    }
    return dist;
}
int main(){
    vector<vector<int>> edges = {{0,1,2},{1,2,1},{0,2,4}};
    vector<int> dis = {1,1,5};
    minimumTime(3, edges, dis);
   system("pause");
   return 0;
}
