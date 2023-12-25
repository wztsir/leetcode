#include"TreeNode.h"
#include<algorithm>
#include<climits>
using namespace std;
// 其实这道题的难点在于root可以是任何节点，对于任何节点，都需要计算，当前节点与左右子节点的路径和；同时只有与左节点或者右节点结合的值可以被递归传递
// 这个被传递的值被叫做贡献值，左右根，先计算左右子节点的情况

//
int max_val =INT_MIN;
int Sum(TreeNode* root) {
    if(root == nullptr)return 0;
    int left = max(0, Sum(root->left));
    int right = max(0, Sum(root->right));
    max_val = max((left + right + root->val), max_val);
    return max(left, right) + root->val;
}
int maxPathSum(TreeNode* root) {
    Sum(root);
    return max_val;
}