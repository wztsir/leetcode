#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == nullptr)return "#";
    string l = serialize(root->left);
    string r = serialize(root->right);
    string res = to_string(root->val);
    res += "," + l + "," + r;
    return res;
}
TreeNode* redeserialize(queue<string>& q){
    if(!q.empty() && q.front() == "#"){
        q.pop();
        return nullptr;
    }
    int val = stoi(q.front());
    q.pop();
    TreeNode* node = new TreeNode(val);
    node->left = redeserialize(q);
    node->right = redeserialize(q);
    return node;
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    queue<string> q;
    string s;
    for(auto& ch : data){  
        if(ch == ','){
            q.push(s);
            s.clear();
        }
        else s.push_back(ch);
    }
    if(!s.empty())q.push(s);
    return redeserialize(q);
}
int main(){
    
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;
    string s = serialize(a);
    TreeNode* n = deserialize(s);
    
}