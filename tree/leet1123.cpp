#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include"TreeNode.h"
using namespace std;
//其实这道题目设计即最深节点的最小子树，涉及子树可以直接返回节点


TreeNode * res; int m = -1;
int dps(TreeNode* root, int h){//传入的是当前的深度，返回当前以当前节点的深度
    if(root == nullptr)return h-1;
    int l = dps(root->left, h+1);
    int r = dps(root->right, h+1);
    if(l >= m && l == r){//考虑两种情况，容易出错，不便于理解
        res = root;
        m = l;
    }
    return max(l , r);
}
TreeNode* lcaDeepestLeaves2(TreeNode* root) {
    dps(root, 0);
    return res;
}
pair<TreeNode*, int> dfs(TreeNode* node){
    if(node == nullptr)return {node, -1};
    pair<TreeNode*, int> l = dfs(node->left);
    pair<TreeNode*, int> r = dfs(node->right);
    //谁深返回谁的子节点
    if(l.second > r.second)return {l.first, l.second+1};
    else if(l.second < r.second)return {r.first, r.second+1};
    //一样深，返回当前子节点
    return {node, l.second+1};
}
TreeNode* lcaDeepestLeaves(TreeNode* root) {
    return dfs(root).first;
}
//树就是三种dfs遍历方式，
int main(){
    TreeNode* a = new TreeNode(0);
    TreeNode* b = new TreeNode(1);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(2);
    a->left = b;
    b->right = d;
    a->right = c;
    lcaDeepestLeaves2(a);
}


