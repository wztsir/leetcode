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


long long numberOfRightTriangles(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> row(m, 0);
    vector<int> col(n, 0);
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++){
            row[i] += grid[i][j];
            col[j] += grid[i][j];
        }
    }
    long long ans = 0;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++){
            if(grid[i][j])ans += (row[i]-1) * (col[j]-1);
        }
    }
    return ans;
}