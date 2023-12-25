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
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    vector<int> res(n);
    for(int i = 0; i < k; i++){
        res[i] = nums[n - k + i];
    }
    for(int i = k; i < n; ++i){
        res[i] = nums[i-k];
    }
    nums = res;
}