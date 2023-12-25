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
int sumDistance(vector<int>& nums, string s, int d) {
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        nums[i] += s[i] == 'R' ? d : -d;
    }
    sort(nums.begin(), nums.end());
    long long res = 0, sum = nums[0];
    int mod = 1e9 + 7;
    for(int i = 1; i < n; ++i){
        res = (res + ((long long)nums[i] * i - sum)) % mod;
        sum += nums[i];
    }
    return res;
}
