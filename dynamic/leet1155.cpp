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
int numRollsToTarget(int n, int k, int target) {

    const int mod = 1e9 + 7;
    vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
    for(int i = 1; i <= min(k, target); i++){
        dp[1][i] = 1;
    }
    for(int i = 1; i <= n; i++){
        dp[i][i] = 1;
    }
    for(int i = 2; i <=n; i++){
        for(int j = i+1; j <= min(target, i*k); j++){
            for(int x = 1; x <=k && x < j;x++){
                dp[i][j] += dp[i-1][j-x] % mod;
            }
        }
    }
    return dp[n][target];
}
int main(){
    int n = 2, k = 6, t = 7;
    numRollsToTarget(2, 6, 7);
}