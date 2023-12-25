#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
// #include"TreeNode.h"
using namespace std;
vector<int> memo;
bool dp(string s, vector<string>& wordD){
    int l2 = s.size();
    if(l2 == 0)return true;
    if(memo[l2] != -666)return memo[l2];
    for(auto& str : wordD){
        bool k = true;
        int l1 = str.size();
        if(l1 > l2)continue;
        for(int i = 1; i <= str.size(); i++){
            if(str[l1 - i] != s[l2-i]){
                k = false;
                break;
            }
        }
        if(k){
            bool subp = dp(s.substr(0,l2- l1), wordD);
            if(subp)return memo[l2] = 1;
        }
    }
    return memo[l2] = 0;
}
bool wordBreak(string s, vector<string>& wordDict) {
    memo.resize(s.size()+1, -666);
    return dp(s, wordDict);
}
int main(){
    string s = "a";
    vector<string> wordDict= {"b"};
    wordBreak(s, wordDict);
}