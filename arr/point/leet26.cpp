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
int removeDuplicates(vector<int>& nums) {
    int slow = 0;
    for(int i = 0; i < nums.size(); ++i){
        if(nums[i] != nums[slow]){
            nums[++slow] = nums[i];
        }
    }
}