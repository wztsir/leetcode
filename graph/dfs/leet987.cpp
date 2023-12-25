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
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
#include"TreeNode.h"
using namespace std;
map<int, priority_queue<int>> ans;
void dfs(TreeNode* root, int index){
    if(root == nullptr)return;
    ans[index].push(root->val);
    root(root->left, index-1);
    root(root->right, index+1);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> res;
    for(auto& it : ans){
        vector<int> temp(it);
        res.push_back(temp);
    }
    return res;
}