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
long long maximumSumOfHeightsIndex(vector<int>& maxHeights, int cur) {
    int s = maxHeights.size();
    long long res = maxHeights[cur];
    vector<int> h(s);
    h[cur] = maxHeights[cur];
    for(int i = cur-1; i>=0; --i){
        h[i] = min(maxHeights[i], h[i+1]);
        res += h[i];
    }
    for(int i = cur+1; i< s; ++i){
        h[i] = min(maxHeights[i], h[i-1]);
        res += h[i];
    }
    return res;
}
//这个target怎么求，不知道，如果要用二分，
long long maximumSumOfHeights(vector<int>& maxHeights) {
    unordered_map<int, vector<int>> map;
    int m = 0;
    for(int i=0; i<maxHeights.size(); ++i){
        m =max(m, maxHeights[i]);
        map[maxHeights[i]].push_back(i);
    }
    while(true){
        
        for(auto& it : map[m]){
            long long r = maximumSumOfHeightsIndex(maxHeights, it);
        }
    }
    
    

}