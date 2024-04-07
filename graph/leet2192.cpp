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
vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<int> degree(n);
    vector<vector<int>> mp(n);
    vector<vector<int>> res(n);
    vector<unordered_set<int>> anc(n);
    for(auto & edge : edges){
        int from = edge[0], to = edge[1];
        mp[from].push_back(to);
        degree[to]++;
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(!degree[i])q.push(i);
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto& son : mp[u]){
            anc[son].insert(u);
            for(auto& temp : anc[u]){
                anc[son].insert(temp);
            }
            --degree[son];
            if(!degree[son])q.push(son);
        }
    }
    for(int i = 0; i < n; i++){
        for(auto& temp : anc[i]){
            res[i].push_back(temp);
        }
        sort(res[i].begin(),res.end());
    }
    return res;
}
int main()
{
   system("pause");
   return 0;
}
