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
// vector<int> memo;
// const int mod = 1e9 +7;
// int dfs(int length, int zero, int one){
//     if(length < 0)return 0;
//     if(length == 0)return 1;
//     if(memo[length] != 0)return memo[length];
//     return memo[length] = (dfs(length-zero, zero, one) + dfs(length-one, zero, one)) % mod;
// }
// int countGoodStrings2(int low, int high, int zero, int one) {
//     memo.resize(high+1, 0);
//     int ans = 0;
//     for(int i = low; i<=high; ++i){
//         ans += dfs(i, zero, one);
//     }
//     return ans;
// }
int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high+1);
    dp[0] = 1;
    int ans = 0;
    int mod = 1e9 + 7;
    for(int i = 1; i<=high; ++i){
        if(i >= zero)dp[i] = (dp[i] + dp[i-zero]) % mod;
        if(i >= one)dp[i] = (dp[i] + dp[i-one]) % mod;
        if(i >= low)ans = (ans + dp[i]) % mod;
    }
    return ans;
}
int main(){
    countGoodStrings(1000, 1000, 6, 9);
}