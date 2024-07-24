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
// 细节：1 <= nums.length <= 105， 所以需要判断nums的长度是不是1
// 当给定的数组 nums 是《《单调数组》》时返回 true，否则返回 false。
bool isMonotonic(vector<int>& nums) {
    int n = nums.size();
    // if(n < 3)return true; // 可以
    //首先 声明一个信号量，判断其是递增还是递减
    bool flag = true;// 默认为递增
    if(nums[0] > nums[n-1])flag = false;// 改为递减
    for(int i = 0; i+1 < n; i++){
        if(flag){
            if(nums[i] > nums[i+1])return false;
        }else{
            if(nums[i] < nums[i+1])return false;
        }
    }
    return true;
}// 对的 全部相等，依旧是单调数组
// 有问题吗

int main()
{
   system("pause");
   return 0;
}
