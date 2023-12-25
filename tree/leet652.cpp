#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
unordered_map<string, int> memo;
vector<TreeNode*> res;
string dfs(TreeNode* root){
    if(root == nullptr)return "#";
    string l = dfs(root->left);
    string r = dfs(root->right);
    string m = l + "," + r + "," + to_string(root->val);
    if(memo.count(m) && memo[m] == 1){
        res.push_back(root);

    }
    memo[m]++;
    return m;
    
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    dfs(root);
    return res;
}