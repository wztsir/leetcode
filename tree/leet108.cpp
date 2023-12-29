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
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
#include"TreeNode.h"
using namespace std;

// [left, right]  即int index = (left+right)/2; 是中间偏左边
TreeNode* build(vector<int>& nums, int left, int right){
    if(left > right)return nullptr;
    int index = (left+right)/2;
    TreeNode* node = new TreeNode(nums[index]);
    node->left = build(nums, left, index-1);
    node->right = build(nums, index+1, right);
    return node;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return build(nums, 0, nums.size()-1);
}
int main()
{
   system("pause");
   return 0;
}
