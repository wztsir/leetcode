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
// #include"TreeNode.h"
using namespace std;
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    int l = puzzles.size();
    vector<int> res(l);
    vector<vector<int>> tree(26);
    vector<vector<int>> map(l, vector<int>(26));
    for(int i = 0; i < l; i++){
        tree[puzzles[i][0] - 'a'].push_back(i);
        for(auto& c : puzzles[i]){
            map[i][c-'a']++;
        }
    }
    unordered_map<char, int> char_num;
    // for(auto & word : words){
    //     char_num.clear();
    //     for(auto& c : word){
    //         char_num[c]++;
    //     }
    //     for(auto& c_num : char_num){
    //         char temp = c_num.first;
    //         for(auto& puzzle : tree[temp-'a'])
    //     }
    // }
}