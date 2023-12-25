// #include"TreeNode.h"
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    int dpth = 1;
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; ++i){
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left == nullptr && cur->right == nullptr)return dpth;
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
        }
        dpth++;
    }
    return dpth;
}