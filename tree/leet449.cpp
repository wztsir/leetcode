#include"TreeNode.h"
#include<string>
#include<vector>
#include<algorithm>
// #include <iostream>
#include <sstream>
using namespace std;
//根左右比较好做，不用找根的位置
//二叉搜索树
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == nullptr)return "";//不能返回nullptr
    string s = "";
    s += to_string(root ->val);
    s += ",";
    if(root->left) s += serialize(root->left);
    if(root->right) s += serialize(root->right);
    return s;
}
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    istringstream tokenStream(s);
    string token;
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
TreeNode* construct(int l, int r, vector<int>& arr) {
    if(l>r)return nullptr;
    TreeNode* node = new TreeNode(arr[l]);
    int index = l + 1;
    while(index < arr.size() && arr[index] < arr[l]){index++;}
    node->left = construct(l+1, index - 1, arr);
    node->right = construct(index, r, arr);
    return node;
}
//根左右排序的字符串怎么转回树
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data.size() == 0) {
        return nullptr;
    }
    vector<string> arr = split(data, ',');
    vector<int> ma;//错误，设置了大小就不能在push_back
    for(auto it : arr){
        int temp = 0;
        for(int i = 0; i < it.size(); ++i){
            temp = temp * 10 + it[i] - '0';
        }
        ma.push_back(temp);
    }
    return construct(0, ma.size()-1, ma);
}
int main(){
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    node1 -> left = node2;
    node1 -> right = node3;
    string t = serialize(nullptr);
    TreeNode* node = deserialize(t);
}