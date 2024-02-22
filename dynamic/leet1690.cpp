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
vector<int> preSum, s;
vector<vector<int>> memo;
int dfs(int i, int j){
    if(i > j) return 0;
    if(memo[i][j] != 0) return memo[i][j];
    int c1 = preSum[j] - preSum[i] - dfs(i, j-1);
    int c2 = preSum[j+1] - preSum[i+1] - dfs(i+1, j);
    return memo[i][j] = max(c1, c2);
}
int stoneGameVII(vector<int>& stones) {
    int n = stones.size();
    preSum.resize(n+1, 0);
    memo.resize(n, vector<int>(n, 0));
    s = stones;
    for(int i = 1; i <= n; i++){
        preSum[i] = preSum[i-1] + stones[i-1];
    }

    return dfs(0, n-1);
    
}
int main()
{
   system("pause");
   return 0;
}
