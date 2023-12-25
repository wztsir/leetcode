#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric> // 为了使用std::accumulate()函数
#include "TreeNode.h"
using namespace std;
//我先思考了遍历方式，先序加数据结构直接薄纱

//但是要空间O(1),所以接着思考了分解子问题，走几步看看，3个节点怎么拉直，直接将右节点放在左节点右边位置-》多个节点即先拉直左边，返回最右节点，后拉直右边，放置左边
//dfs
TreeNode* f(TreeNode* root){//返回子树最右节点
    if(root == nullptr)return nullptr;
    if(root->left == nullptr && root->right == nullptr)return root;
    TreeNode* l = f(root->left);
    TreeNode* r = f(root->right);
    if(l == nullptr)return r;//左子树为空
    if(r == nullptr)r = l;//右子树为空
    l->right = root->right;
    root->right = root->left;
    root->left = nullptr;
    return r;
}
void flatten(TreeNode* root) {
    f(root);
}
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    a->left = b;
    b->left = c;
    flatten(a);
}