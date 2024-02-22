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
int alternatingSubarray(vector<int>& nums) {
    int left = 0, res = -1, right = 1;
    int size = nums.size();
    while(left < size-1){
        if(nums[left+1] - nums[left] != 1){
            left++;
            continue;
        }
        int right = left;
        int l = left;
        while(right + 2< size && num[right] == nums[right+2])right++;
        int temp = right - left + 2;
        res = max(res, temp);
        left = right + 1;
    }
    return res;
}
int main()
{
   system("pause");
   return 0;
}
