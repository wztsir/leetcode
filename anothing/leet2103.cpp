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
// #include"TreeNode.h"
using namespace std;
int countPoints(string rings) {
    vector<int> map(10);
    std::map<char, int> d = {  
        {'R', 1},  
        {'G', 2},  
        {'B', 4}  
    };
    for(int i = 0; i < rings.size(); i += 2){
        int index = rings[i+1]-'0';
        char c = rings[i];
        map[index] |= d[c];
    }
    int res = 0;
    for(auto& it : map){
        if(it == 7)res++;
    }
    return res;
}
