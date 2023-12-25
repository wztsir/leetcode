#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
//主要就是发现可以使用前缀和， 并且可以利用单调栈复用前缀和  主要是需要手动模拟出来
long long maximumSumOfHeights(vector<int>& maxHeights) {
    long long res = 0;
    int n = maxHeights.size();
    vector<long long> pre(n+1);
    vector<long long> suf(n+1);
    stack<int> sp;
    for(int i = 0; i < n; ++i){
        while(!sp.empty() && maxHeights[sp.top()] > maxHeights[i]){
            sp.pop();
        }
        int j = sp.empty() ? -1 : sp.top();
        pre[i+1] = pre[j+1] + (i-j) * maxHeights[i];
        sp.push(i);
    }
    stack<int> sf;
    for(int i = n-1; i>=0; --i){
        while(!sf.empty() && maxHeights[sf.top()] > maxHeights[i]){
            sf.pop();
        }
        int j =  sf.empty() ? n : sf.top();
        suf[i] = suf[j] + (j-i) * maxHeights[i];
        sf.push(i);
    }
    for(int i = 0; i<n; ++i){
        res = max((long long)(pre[i+1] + suf[i] - maxHeights[i]), res);
    }
    return res;
    
}