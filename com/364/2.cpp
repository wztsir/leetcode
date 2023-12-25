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
long long maximumSumOfHeights(vector<int>& maxHeights) {
    int n = maxHeights.size();
    vector<long long> leftMax(n), rightMax(n);

    // 计算每个位置左边的最大高度
    leftMax[0] = maxHeights[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = min(leftMax[i - 1], (long long)maxHeights[i]);
    }

    // 计算每个位置右边的最大高度
    rightMax[n - 1] = maxHeights[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = min(rightMax[i + 1], (long long)maxHeights[i]);
    }

    long long maxSum = 0;
    for (int i = 0; i < n; ++i) {
        long long maxHeight = max(leftMax[i], rightMax[i]);
        maxSum += maxHeight;
    }

    return maxSum;
}
long long maximumSumOfHeights(vector<int>& maxHeights) {
    int s = maxHeights.size();
    long long r = 0;
    for(int cur = 0; cur < s;++cur){
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
        r = max(res,r);
    }

    return r;
}
int main(){
    vector<int> h = {3,6,3,5,5,1,2,5,5,6};
    maximumSumOfHeights(h);
}