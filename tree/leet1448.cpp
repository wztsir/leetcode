#include"TreeNode.h"
#include<vector>
using namespace std;
//没必要维护一个数组
int dfs(TreeNode* root, vector<int> ma){
    if(root == nullptr)return 0;
    int res = 1;
    for(auto it : ma){
        if(it > root->val){
            res = 0;
            break;
        }
    }
    ma.push_back(root->val);
    res += dfs(root->left, ma)+dfs(root->right, ma);
    ma.pop_back();
    return res;
}
int goodNodes(TreeNode* root) {
    vector<int> ma;
    return dfs(root, ma);
}