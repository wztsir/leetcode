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
// #include"TreeNode.h"
using namespace std;
//变化的值就是状态, 就是所谓的n
vector<int> memo;
int dp(int n){
    if(n == 0)return 0;
    if(n < 0)return -1;
    if(memo[n] != -666)return memo[n];
    int res = INT_MAX;
    for(int i = 1; i*i <=n; ++i){
        int subP = dp(n - i*i);
        res = min(subP + 1, res);
    }
    return memo[n] = res;
}
int numSquares(int n) {
    memo.resize(n+1, -666);
    return dp(n);
}
