#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include"TreeNode.h"
using namespace std;
unordered_map<TreeNode*, int>memo;
int rob(TreeNode* root) {
    if(root == nullptr)return 0;
    if(memo.count(root))return memo[root];
    int a = 0,b =0,c=0,d=0;
    if(root->left != nullptr){
        a = rob(root->left->left);
        b = rob(root->left->right);
    }
    if(root->right != nullptr){
        c = rob(root->right->left);
        d = rob(root->right->right);
    }
    return memo[root] =  max(rob(root->left)+rob(root->right), a+b+c+d + root->val);
}