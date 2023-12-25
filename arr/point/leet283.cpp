#include<vector>
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

void moveZeroes(vector<int>& nums) {
    int s = nums.size();
    if(s <= 1)return;
    int j = 0;
    for(int i = 0; i < s; ++i){
        if(nums[i] != 0){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j++] = temp; 
        }
    }
}
