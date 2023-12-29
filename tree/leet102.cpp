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

//层序遍历模板题
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(root == nullptr)return res;
    queue<TreeNode*> q;
    q.push(root);
    int h = 0;
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            temp.push_back({node->val});
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        res.push_back(temp);
    }
    return res;
}
int main()
{
   system("pause");
   return 0;
}
