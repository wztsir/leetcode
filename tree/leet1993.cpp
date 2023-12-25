#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
// #include"TreeNode.h"
using namespace std;
struct TreeNode{
    int value;
    TreeNode* left, *right;
    TreeNode():value(0),left(nullptr), right(nullptr){}
    TreeNode(int v):value(v), left(nullptr), right(nullptr){}
    TreeNode(int v, TreeNode* _left, TreeNode* _right):value(v), left(_left), right(_right){}
};
class LockingTree {
private:
    vector<pair<bool, int>> memo;
    vector<int> parent;
    vector<vector<int>> children;
public:

    LockingTree(vector<int>& parent) {
        this->parent = parent;
        int s = parent.size();
        memo.resize(s, {false, -1});
        children.resize(s);
        for(int i = 1; i < parent.size(); ++i){
            children[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(memo[num].first == false){
            memo[num].first = true;
            memo[num].second = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(memo[num].first == true && memo[num].second == user){
            memo[num].first = false;
            return true;
        }
        return false;
    }
    bool getFatherLock(int num){
        int father = num;
        while(father != -1){
            if(memo[father].first == true)return false;
            father = parent[father];
        }
        return true;
    }
    bool upgrade(int num, int user) {
        if(memo[num].first == true)return false;
        if(!getFatherLock(num))return false;
        queue<int> q;
        q.push(num);
        int s = parent.size();
        int k = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto& it : children[cur]){
                q.push(it);
                if(memo[it].first == true){
                    memo[it].first = false;
                    k = 1;
                }
            }
        }
        if(k == 0)return false;
        memo[num].first = true;
        memo[num].second = user;
        return true;
    }
};