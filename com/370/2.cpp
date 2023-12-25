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
    int findChampion(int n, vector<vector<int>>& edges) {
           
    vector<int> du(n, 0);
    for(auto& edge : edges){
        int b = edge[1];
        du[b]++;
    }
    int k = 0;
    int res = 0;
    for(int i = 0; i < n;i++){
        if(du[i] == 0){
            k++;
            res = i;
        }
    }
    return k==1 ? res : -1;
    }