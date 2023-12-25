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
#include"TreeNode.h"
using namespace std;
vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
    int size = nums.size();
    vector<int> ans(size, 1);
    auto it = find(nums.begin(), nums.end(), 1);
    if (it == nums.end()) { // 不存在基因值为 1 的点
        return ans;
    }
    //建图
    vector<vector<int>> g(size);
    for(int i = 1; i < size; i++){
        g[parents[i]].push_back(i);
    }
    unordered_set<int> vised;//放入的是基因
    function<void(int)> dfs = [&](int node){
        vised.insert(nums[node]);
        for(auto& son : g[node]){
            if(vised.find(nums[son]) == vised.end())dfs(son);
        }
    };
    int res = 2;
    int cur = it - nums.begin();
    while(cur != -1){
        
        dfs(cur);
        while(vised.count(res)){
            res++;
        }
        ans[cur] = res;
        cur = parents[cur];
    }
    return ans;
}