#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;
//难点在于同时处理头尾，头尾不能同时被抢，实际上就只有3钟情况，首被抢，尾不被，首不被抢，尾被抢;两者都不被抢（肯定最小，不考虑）-》不被抢就直接放弃，不纳入dp的考虑
int rob(vector<int>& nums, int s, int e){
    vector<int> dp(nums.size() + 2, 0);
    for(int i = s+2; i < e+2; ++i){
        dp[i] = max(dp[i-1], nums[i-2] + dp[i-2]);
    }
    return dp[e+1];
}
int rob(vector<int>& nums) {
    int l = nums.size();
    if(l == 1)return nums[0];
    max(rob(nums, 0, l-1), rob(nums, 1, l));
}