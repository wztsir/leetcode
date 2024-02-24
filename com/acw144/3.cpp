#include<iostream>
#include<vector>
#include<cstdio>
#include<unordered_set>
#include<queue>
using namespace std;
vector<int> sk;
vector<vector<int>> graph;
void bfs(int i, int s){
    unordered_set<int> visited;
    unordered_set<int> need;
    int ans = 0;
    queue<int> q;
    q.push(i);
    need.insert(sk[i]);
    int des = 0;
    while(need.size() < s){
        int size = q.size();
        des ++;
        for(int i = 0; i < size; i++){
            int node = q.front();
            q.pop();
            visited.insert(node);
            for(auto & it : graph[node]){
                if (visited.find(it) == visited.end() && need.find(sk[it]) == need.end()) {
                    ans += des;
                    need.insert(sk[it]);
                    q.push(it);
                    if(need.size() ==  s){
                        printf("%d ",ans);
                        return;
                    }
                }
            }
        }

    }
    printf("%d ",ans);
    return;
}
int main(){

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    graph.resize(n+1);
    sk.resize(n+1);
    int a,  b;
    for(int i = 1; i <= n; i++){
        cin >> sk[i];
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        bfs(i, s);
    }
}