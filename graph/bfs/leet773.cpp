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
//首先bfs， 
//难点一：不同的状态如何比较，存数组？那样效率太低了，只能用字符串，再使用哈希去重状态
//难点二：不同状态如何丝滑转向下一个状态，2X3标号0，1，2，3，4，5然后看邻接
vector<vector<int>> nei = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
int slidingPuzzle(vector<vector<int>>& board) {
    string start, target = "123450";
    for(auto& it : board){
        for(auto& i : it){
            start.push_back(i + '0');
        }
    }
    queue<pair<string, int>> q;
    unordered_set<string> s;
    q.push(pair{start, 0});
    s.insert(start);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        if(cur.first == target)return cur.second;
        int index = cur.first.find('0');
        for(auto& it : nei[index]){
            string next = cur.first;
            int num = cur.second+1;
            swap(next[index], next[it]);
            if(s.count(next))continue;
            q.push(pair{next, num});
            s.insert(next);
            if(next == target)return num;
        }
    }
    return -1;
}
int main(){
    vector<vector<int>> s = {{1,2,3},{4,0,5}};
    slidingPuzzle(s);
}