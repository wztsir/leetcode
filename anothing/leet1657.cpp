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
using namespace std;
bool closeStrings(string word1, string word2) {
    if(word1.size() != word2.size())return false;
    unordered_map<char, int> map1, map2, arr;
    // unordered_set<char> s;
    for(auto& w : word1){
        map1[w]++;
        // s.insert(w);
    }
    // for(int i = 0; i < word2.size(); i++){
    //     char w = word2[i];
    // }
    // for(auto&w : word2)//迭代的取,自动匹配类型
    for(auto& w :  word2){
        if(map2.find(w) == map2.end())return false;
        map2[w]++;
    }
    for(auto& node : map1){
        arr[node.second]++;
    }
    for(auto& node : map2){
        if(arr.find(node.second) == arr.end() || arr[node.second] <= 0)return false;
        arr[node.second]--;
    }
    return true;
}
int main()
{
    closeStrings("au", "a");
   system("pause");
   return 0;
}

