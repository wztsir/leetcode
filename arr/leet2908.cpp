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
int minimumSum(vector<int>& nums) {
    int res = INT_MAX, size = nums.size();
    vector<int> leftminn(size), rightminn(size);
    int minn = nums[0];
    for(int i = 1; i < size; i++){
        if(nums[i] <= minn)minn = nums[i];
        else leftminn[i] = minn;
    }
    minn = nums[size-1];
    for(int i = size-2; i >= 0; i--){
        if(nums[i] <= minn)minn = nums[i];
        else rightminn[i] = minn;
    }
    for(int i = 1; i < size-1; i++){
        if(leftminn[i] && rightminn[i])
        res = min(res, leftminn[i] + rightminn[i] + nums[i]);
    }
    return res == INT_MAX ? -1 : res;
}
int main()
{
    vector<int> nums = {8,6,1,5,3};
    minimumSum(nums);
   system("pause");
   return 0;
}
