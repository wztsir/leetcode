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
int maxProfit(vector<int>& prices) {
    int buy = 0, sell = 0, s = prices.size();
    if(s <= 1)return 0;
    vector<vector<int>> dp(s, vector<int>(2));
    //0 未持有
    //1 持有
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[1][0] = max(0, prices[1] - prices[0]);
    dp[1][1] = max(-prices[0], -prices[1]);
    for(int i = 2; i < s; ++i){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
    }
    return dp[s-1][0];
}