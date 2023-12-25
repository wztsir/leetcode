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
int findChampion(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> du(n, 0);
    for(int i = 0; i< n;++i){
        for(int j = 0; j<n; j++){
            if(grid[i][j] == 1)du[j]++;
        }
    }
    for(int i = 0; i < n;i++){
        if(du[i] == 0)return i;
    }
    return -1;
}