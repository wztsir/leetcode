#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
// 2603
//在灵爷的基础上，继续思考，为什么是二次删树，不能是一次删除距离为2的节点
//树是不存在环的，如果全删除距离叶子为2的节点，可能该节点的度大于1，会导致里面的树无法联通，无法遍历
int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    int n = coins.size();
    int re = 0;
    vector<vector<int>> map(n);
    vector<int> du(n);
    for(auto& it : edges){
        int a = it[0], b = it[1];
        du[a]++, du[b]++;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    queue<int> q;
    for(int i = 0;i < n; ++i){
        if(coins[i] == 0 && du[i] == 1)q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        re++;
        for(auto& it : map[cur]){
            du[it]--;
            if(coins[it] == 0 && du[it] == 1)q.push(it);
        }
    }

    for(int i = 0;i < n; ++i){
        if(coins[i] == 1 && du[i] == 1)q.push(i);
    }
    for(int c = 0; c<2;c++){
        int s = q.size();
        for(int i = 0; i < s; ++i){
            int cur = q.front();
            q.pop();
            re++;
            for(auto& it : map[cur]){
                du[it]--;
                if(du[it] == 1)q.push(it);
            }
        }
    }
    return n== re ? 0 : (n - re - 1)*2;
}