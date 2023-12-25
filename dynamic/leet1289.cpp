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
// #include"TreeNode.h"
using namespace std;
// dp[i][j] = min(dp[i-1][j-1]) + grid[i][j]
int minFallingPathSum(vector<vector<int>>& grid) {
    int row = grid.size(), col = row;
    if(row == 1)return grid[0][0];
    vector<vector<int>> dp(row, vector<int>(col));
    
    int min_first = 0, min_second = 1;
    for(int j = 0; j<grid[0].size(); ++j){
        dp[0][j] = grid[0][j];
        if(grid[0][j] < grid[0][min_first]){
            min_first = j;
        }else if(j != min_first && grid[0][j] < grid[0][min_second]){
            min_second = j;
        }
    }
    for(int i = 1; i < row; i++){
        int min_first_temp = 0, min_second_temp = 1;
        for(int j = 0; j < col; j++){
            if(j != min_first){
                dp[i][j] = dp[i-1][min_first] + grid[i][j];
            }else{
                dp[i][j] = dp[i-1][min_second] + grid[i][j];
            }
            if(dp[i][j] < dp[i][min_first_temp]){
                min_first_temp = j;
            }else if(j != min_first_temp && dp[i][j] < dp[i][min_second_temp]){
                min_second_temp = j;
            }
        }
        min_first = min_first_temp;
        min_second = min_second_temp;
    }
    return dp[row-1][min_first];
}
int main(){
    vector<vector<int>> a = 
    {{-73,61,43,-48,-36},{3,30,27,57,10},{96,-76,84,59,-15},{5,-49,76,31,-7},{97,91,61,-46,67}};
    // {{1,2,3}, {4,5,6}, {7,8,9}};
    // {{2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2}};
    
    minFallingPathSum(a);
}