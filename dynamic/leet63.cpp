#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
#include"TreeNode.h"
using namespace std;
//dp[i][j] = dp[i-1][j] + dp[i][j-1]
//思维空白，当首行和首列，有一个1，就都是0
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0])return 0;
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 1));
    int k = 0;
    for(int i = 1; i < n; ++i){
        if(obstacleGrid[i][0] || k){
            k = 1;
            dp[i][0] = 0;
        }
    }
    k = 0;
    for(int j = 1; j < m; ++j){
        if(obstacleGrid[0][j] || k){
            k=1;
            dp[0][j] = 0;
        }
    }
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            if(obstacleGrid[i][j])dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}