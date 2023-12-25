#include"TreeNode.h"
int res = 0,temp = 0;
int sumNumbers(TreeNode* root) {
    if(root == nullptr)return 0;
    temp = temp * 10 + root->val;
    if(root->left == nullptr && root->right == nullptr)res += temp;
    sumNumbers(root->left);
    sumNumbers(root->right);
    temp = temp / 10;
    return res;
}