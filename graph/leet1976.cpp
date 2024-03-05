#include<vector>
#include<limits.h>
#include<queue>
using namespace std;
/*稠密图写法*/
// 建图犯错，初始化为很大值，方便之后更新
// 同时为什么要/2 , 防止 graph[x][y] + dis[x] 溢出
// 时间复杂度为 n^2
int countPaths(int n, vector<vector<int>>& roads) {
    // vector<vector<long long> graph(n, vector<long>(n));
    const int MOD = 1E9 + 7; 
    vector<vector<long long>> graph(n, vector<long long>(n, LLONG_MAX / 2)); // 细节一
    for(auto road : roads){
        graph[road[0]][road[1]] = road[2];
        graph[road[1]][road[0]] = road[2];
    }
    vector<long long> dis(n, LLONG_MAX / 2); // 2
    vector<int> done(n),f(n);
    f[0] = 1, dis[0] = 0;
    while(true){
        int x = -1;
        for(int i = 0; i < n; i++){// 3
            if(!done[i] && (x < 0 || dis[i] < dis[x])){
                x = i;
            }
        }
        done[x] = 1;
        if(x == n-1)return f[x];
        for(int y = 0; y < graph[x].size(); y++){
            if(graph[x][y] + dis[x] < dis[y]){
                dis[y]  = graph[x][y] + dis[x];
                f[y] = f[x];
            }else if(graph[x][y] + dis[x] == dis[y]){
                f[y] = (f[y] + f[x]) % MOD;
            }
        }
    }
}

/*稀疏图写法*/
// 对于优先队列使用，知识点：
// 当使用priority_queue<pair<int, int>> pq;创建一个存储pair<int, int>类型元素的优先队列时，默认情况下会按照以下规则进行排序：

// 按照pair的第一个元素进行比较，如果第一个元素不同，则较小的元素具有更高的优先级。
// 如果第一个元素相同，则会比较第二个元素，较小的第二个元素具有更高的优先级。如果第二个元素也相同，则继续比较后续的元素。
int countPaths2(int n, vector<vector<int>>& roads) {
    const int MOD = 1E9 + 7; 
    vector<vector<pair<int, int>>> graph(n); // 细节一
    for(auto road : roads){
        int a = road[0], b = road[1], d = road[2];
        graph[a].emplace_back(b, d);
        graph[b].emplace_back(a, d);
    }
    vector<long long> dis(n, LLONG_MAX/2);
    vector<int> f(n), done(n);
    f[0] = 1, dis[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // 1
    pq.emplace(0, 0);
    while(true){
        auto [dx, x] = pq.top();
        pq.pop();
        if(x == n-1)return f[n-1];
        if(dx > dis[x])continue;//2 这个是没被更新的数据，直接跳过
        for(auto [y, ry] : graph[x]){
            long long temp = dis[x] + ry;
            if(temp < dis[y]){
                dis[y]  = temp;
                f[y] = f[x];
                pq.emplace(temp, y);
            }else if(temp == dis[y]){
                f[y] = (f[y] + f[x])%MOD;
            }
        }
    }
}