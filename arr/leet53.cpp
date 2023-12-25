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
#include"TreeNode.h"
using namespace std;
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> memo(n);
    int res = nums[0];
    memo[0] = nums[0];
    for(int i = 1; i < n; ++i){
        if(memo[i-1] > 0) {
            memo[i] = nums[i] + memo[i-1];
        }else memo[i] = nums[i];
        res = max(res, memo[i]);
    }
    return res;
}