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

bool splitArraySameAverage(vector<int>& nums) {
    int sum = 0;
    for(auto& it : nums){
        sum += it;
    }
    int n = nums.size();
    function<bool(int, int, int)>  dfs= [&](int index, int firstSize, int firstTotal){
        for(int i = index; i < n-1; i++){
            firstSize++;
            firstTotal += nums[i];
            double first = firstTotal * 1.0 / firstSize;
            double second = (sum * 1.0 - firstTotal) / (n - firstSize);
            if(first == second || dfs(i+1, firstSize, firstTotal))return true;
            firstSize--;
            firstTotal -= nums[i];
        }
        return false;
    };
    if(dfs(0, 0, 0)) return true;
    return false;
}
int  main(){
    vector<int> a ={6,8,18,3,1};
    splitArraySameAverage(a);
}