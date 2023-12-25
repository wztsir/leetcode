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
#include"TreeNode.h"
using namespace std;
long long findTheArrayConcVal(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    long long res = 0;
    while(l < r){
        int a = nums[l++];
        int b = nums[r--];
        res += b;
        int k = 0;
        while(b){
            b /= 10;
            k++;
        }
        res += a * pow(10, k);
    }
    if(l == r)res += nums[l];
    return res;
}