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
int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    vector<int> input_num(n);
    vector<int> son_num(n, 0);
    vector<int> vised(n, 0);
    for(int i = 0; i < n; ++i){
        input_num[favorite[i]]++;
    }
    queue<int> q;
    for(int i = 0; i < n; ++i){
        if(input_num[i] == 0)q.push(i);
    }
    int num_branch = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        vised[node] = 1;
        if(--input_num[favorite[node]] == 0){
            q.push(favorite[node]);
        }
        son_num[favorite[node]] = max(son_num[favorite[node]], son_num[node] + 1);
    }
    //可能存在不止一个环
    function<int(int)> dfs = [&](int node){
        if(vised[node])return 0;
        vised[node] = 1;
        return dfs(favorite[node]) + 1;
    };
    int sum_chain = 0, max_circle = 0;
    for(int i = 0; i < n; ++i){
        int temp = 0;
        if(vised[i] == 0){
            temp = dfs(i);
            if(temp == 2)sum_chain += temp + son_num[i] + son_num[favorite[i]];//如果是2，就当作一个可以组成环的组件
            else max_circle = max(temp, max_circle);
        }
    }
    return max(max_circle, sum_chain);
}
int main(){
    vector<int> favorite = {1,2,3,4,5,6,3,8,9,10,11,8};
    maximumInvitations(favorite);
    
}