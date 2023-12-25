#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <numeric> // 为了使用std::accumulate()函数
#include "TreeNode.h"
using namespace std;
//树的直径，即求所有节点的左右子树的深度之和，且是最大值

//1、多走几步，发现就是一个子树的深度和
//2、这个子树直接求最值就能发现
int res = 0;
int dfs(TreeNode* root) {
    if(root == nullptr)return 0;
    int l = dfs(root->left);//最大深度
    int r = dfs(root->right);
    res = max(l + r + 1, res);
    return max(l, r) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    dfs(root);
    return res;
}
