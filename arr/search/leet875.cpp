#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include"TreeNode.h"
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    if(piles.size() == 0)return 0;
    auto f = [&](int x){//犯错，f的类型不是返回类型，是function类型
        int t = 0;
        for(auto& it : piles){
            t += it / x;
            if(it % x)t++;
        }
        return t;
    };
    int left = 1, right = *max_element(piles.begin(),piles.end());
    while(left < right){
        int mid = left + (right - left)/2;
        if(f(mid) == h){
            right = mid;
        }else if(f(mid) < h){//犯错，f(x)是单调递减函数
            right = mid;
        }else if(f(mid) > h){
            left = mid + 1;
        }
    }
    return left;
}