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
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
// #include"TreeNode.h"
using namespace std;
long long beautifulSubarrays(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n+1);
    unordered_map<int, int> pre_num;
    int res = 0;
    pre_num[0] = 1;
    for(int i = 1; i <=n; i++){
        prefix[i] = prefix[i-1] ^ nums[i-1];
        res += pre_num[prefix[i]];
        pre_num[prefix[i]]++;
    }
    return res;
}