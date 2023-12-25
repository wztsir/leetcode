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
#include<sstream>
#include"TreeNode.h"
using namespace std;
//重点是 0 ^ 任何数等于其自身
int singleNumber(vector<int>& nums) {
    int res = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        res = res ^ nums[i];
    }
    return res;
}