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
int maxProfit(vector<int>& prices) {
    int s = prices.size();
    if(s == 1)return 0;
    int l = 0, r = 1;
    int res = 0;
    while(r < s){
        int temp = prices[r] -  prices[l];
        if(temp > 0)res += temp;
        r++;
        l++;
    }
    return res;
}