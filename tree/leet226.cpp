#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <numeric> // 为了使用std::accumulate()函数
#include "TreeNode.h"
using namespace std;
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr)return nullptr;
    TreeNode* l = invertTree(root->left);
    TreeNode* r = invertTree(root->right);
    root->right = l;
    root->left = r;
    return root;
}