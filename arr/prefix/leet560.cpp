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
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + nums[i-1];
    }
    multiset<int> memo;
    memo.insert(0);
    int res = 0;
    for(int i = 1; i <= n; ++i){
        res += memo.count(prefix[i] - k);
        memo.insert(prefix[i]);
    }
    return res;
}