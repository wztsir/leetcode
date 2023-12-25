#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
//有多少状态，天数，交易K次，持有或者销售出
int maxProfit(int k, vector<int>& prices) {
    int s = prices.size();
    vector<vector<vector<int>>> dp(s, vector<vector<int>>(k+1, vector<int>(2)));
    // 0 未持有
    // 1 持有
    //分析base case
    //i 的临界值为0，所以base 为-1
    //k 的临界值为1，所以base 为0
    //什么情况下要设置成最小值，INT_MIN, 或者INT_MAX不希望被取到的时候
    for(int i = 0; i < s; ++i){
        dp[i][0][0] = 0;
        dp[i][0][1] = INT_MIN;
    }
    for(int i = 0; i < s; ++i){
        for(int j = 1; j <= k; ++j){
            if(i == 0){
                dp[i][j][0] = 0;
                dp[i][j][1] = -prices[0];
                continue;
            }
            dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
            dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] -  prices[i]);
        }
    }
    return dp[s-1][k][0];
}