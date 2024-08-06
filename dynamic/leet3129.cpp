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
const int mod = 1e9+7;
int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one+1, vector<int>(2, 0)));
    for(int i = 1; i <= min(limit,zero); i++){
        dp[i][0][0] = 1;
    }
    for(int i = 1; i <= min(limit,one); i++){
        dp[0][i][1] = 1;
    }

    for(int i = 1; i <= zero; i++){
        for(int j = 1; j <= one; j++){
            dp[i][j][0] = ((long long)dp[i-1][j][0] + dp[i-1][j][1]) % mod;
            if(i >= limit+1)dp[i][j][0] = (dp[i][j][0] - dp[i - limit - 1][j][1] + mod) % mod;
            dp[i][j][1] = ((long long)dp[i][j-1][0] + dp[i][j-1][1]) % mod;
            if(j >= limit+1)dp[i][j][1] = (dp[i][j][1] - dp[i][j - limit - 1][0] + mod) % mod;
        }
    }
    return (dp[zero][one][0]+ dp[zero][one][1])%mod;
    
}
int main()
{
    numberOfStableArrays(1, 1, 2);
   system("pause");
   return 0;
}
