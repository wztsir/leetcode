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

//站在节点的角度去考虑：普通节点与终止节点
void preorder(TreeNode* root, vector<int>& seriay){
    if(root->left == nullptr && root->right == nullptr){
        seriay.push_back(root->val);
        return;
    }//终止条件
    // pre.push_back(root->val);// 往下之前要做的
    
    preorder(root->left);// 往下走之后要做的
    preorder(root->right);//往下走之后要做的
    return;
}
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> pre;
    vector<int> post;
    preorder(root1, pre);
    preorder(root2, post);
    int n = pre.size(), m = post.size();
    if(n != m)return false;
    for(int i = 0; i < n; i++){
        if(pre[i] != post[i])return false;
    }
    return true;
}
int main()
{
   system("pause");
   return 0;
}
