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
bool backtrack(vector<int>& nums, vector<int>& used, int target, int sum, int begin){
    if(sum == target)return true;
    bool ans = false;
    for(int i = begin; i < nums.size(); i++){
        if(used[i] == 0){
            used[i] = 1;
            if(backtrack(nums, used, target, sum + nums[i], i+1)) return true;
            used[i] = 0;
        }
    }
    return false;
}
bool canPartitionKSubsets(vector<int>& nums, int k) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if(total % k)return false;
    int target = total / k;
    vector<int> used(nums.size(), 0);
    for(int i = 0; i < k; i++){
        if(!backtrack(nums, used, target, 0, 0)) return false;
    }
    return true;
}
int main()
{
    vector<int> t = {1,1,1,1,2,2,2,2};
    canPartitionKSubsets(t, 4);
   system("pause");
   return 0;
}
