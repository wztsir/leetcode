#include<bits/stdc++.h>
#include"TreeNode.h"
using namespace std;
TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    if(original == nullptr || original == target){
        return cloned;
    }
    TreeNode* left = getTargetCopy(original->left, cloned->left, target);
    if(left)return left;
    return getTargetCopy(original->right, cloned->right, target);
}