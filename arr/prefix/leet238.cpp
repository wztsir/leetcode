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
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> l (n);
    vector<int> r (n);
    l[0] = 1, r[n-1] = 1;
    for(int i = 1; i < n; i++){
        l[i] = l[i-1] * nums[i-1];
    }
    for(int i = n-2; i >= 0; --i){
        r[i] = r[i+1] * nums[i+1];
    }
    for(int i = 0; i < n; i++){
        l[i] = l[i] * r[i];
    }
    return l;
}