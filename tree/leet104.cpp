#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <numeric> // 为了使用std::accumulate()函数
#include "TreeNode.h"
using namespace std;
int maxDepth(TreeNode *root){
    if(root == nullptr)return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l,r)+1;
}