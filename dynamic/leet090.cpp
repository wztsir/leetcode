#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;
//打家劫舍问题，前面的选择会影响后面能不能抢，反过来，后面的金额的大小又反过来影响前面抢不抢，为什么这样的代码就能直接解决这个需求  抢的时候，状态往前跳两个

//首先最关键的是状态转移方程，而要写出方程，必须指导状态与选择，
//边移动，就能边知道选择，先定移动的方向，比如从左到右
//一开始的想法是以i为终点，[),不抢i，就是dp[i-1],抢i就是dp[i-2]+nums[i],犯错误，写成了dp[i-1)。 （细节的动态规划两种情况变化的步骤一定不同）
vector<int> memo;
int dp(vector<int>& nums, int n){
    if(n == -1 || n == -2){
        return 0;
    }
    if(memo[n] != -1)return memo[n];
    memo[n] = max(dp(nums, n-1), dp(nums, n - 2) + nums[n]);
    return memo[n];
}

int rob1(vector<int>& nums) {
    int l = nums.size();
    memo.resize(l, -1);
    return dp(nums, l-1);
}
//改写自底向上，非常容易
int rob(vector<int>& nums) {
    int l = nums.size();
    vector<int> dp(l, 0);
    dp[0] = nums[0];
    if(l == 1)return dp[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < l; i++){
        dp[i] = max(dp[i-1], dp[i -2] + nums[i]);
    }
    return dp[l-1];
}