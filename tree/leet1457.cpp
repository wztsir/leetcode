#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
#include"TreeNode.h"
using namespace std;
int ans = 0;
void dfs(TreeNode* node, int cnt){
    if(node == nullptr){
        if(cnt == (cnt & -cnt)){
            ans++;
        }
        return;
    }
    dfs(node->left, cnt ^= (1 << node->val));
    dfs(node->right, cnt ^= (1 << node->val));
}
int pseudoPalindromicPaths (TreeNode* root) {
    dfs(root, 0);
    return ans/2;
}

int main(){
    TreeNode* node = new TreeNode(9);
    pseudoPalindromicPaths(node);
}