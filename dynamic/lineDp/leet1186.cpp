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
int maximumSum(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(2));
    dp[0][0] = arr[0];// 不删除
    dp[0][1] = 0;//必须删除
    int ans = arr[0], temp;
    for(int i = 1; i < n; i++){
        if(dp[i-1][0] > 0)dp[i][0] =  dp[i-1][0] + arr[i];
        else  dp[i][0] = arr[i];
        dp[i][1] = max(dp[i-1][1] + arr[i], dp[i-1][0]);
        temp = max(dp[i][0], dp[i][1]);
        ans = max(ans, temp);
    }
    return ans;
}
int main()
{
   vector<int> arr = {1,-2,0,3};
   maximumSum(arr);
   return 0;
}
