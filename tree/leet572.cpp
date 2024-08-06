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
#include<memory>
#include "TreeNode.h"
using namespace std;
bool sameTree(TreeNode* root, TreeNode* subRoot){
    if(root == nullptr && subRoot == nullptr)return true;
    if(root == nullptr || subRoot == nullptr || root->val != subRoot->val)return false;
    return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root == nullptr)return false;
    return sameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
// int main()
// {
//    system("pause");
//    return 0;
// }





