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

using namespace std;
//dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]);
int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    vector<vector<int>> dp(row, vector<int>(row));
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < row; ++i){
        dp[i][0] = dp[i-1][0] + triangle[i][0];
    }
    for(int i = 1; i < row; ++i){
        for(int j = 1; j < triangle[i].size(); j++){
            if(j != triangle[i].size()-1){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
            else dp[i][j] =dp[i-1][j-1] + triangle[i][j];
        }
    }
    int res = INT_MAX;
    for(int j = 0; j<triangle[row-1].size(); ++j){
        res = min(dp[row-1][j], res);
    }
    return res;
}
int main(){
    vector<vector<int>> a = {{2},{3,4},{6,5,7},{4,1,8,3}};
    minimumTotal(a);
}