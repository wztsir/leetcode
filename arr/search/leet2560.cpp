#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
// 由于相邻的房屋装有相互连通的防盗系统，所以小偷 不会窃取相邻的房屋 。

// 小偷的 窃取能力 定义为他在窃取过程中能从单间房屋中窃取的 最大金额 。

// 给你一个整数数组 nums 表示每间房屋存放的现金金额。形式上，从左起第 i 间房屋中放有 nums[i] 美元。

// 另给你一个整数 k ，表示窃贼将会窃取的 最少 房屋数。小偷总能窃取至少 k 间房屋。(即窃取的房屋数目不超过k)

int minCapability(vector<int>& nums, int k) {
    if(nums.size() == 0)return 0;
    auto f = [&](int x){
        int cnt = 0, visit = 0;
        for(auto &it : nums){
            if(it <= x && !visit){
                cnt++;
                visit = 1;
            }else visit = 0;
        }
        return cnt;
    };
    int l = *min_element(nums.begin(), nums.end());
    int r = *max_element(nums.begin(), nums.end())+1;
    while(l < r){
        int mid = (l+r)>>1;//犯错，
        if(f(mid) >= k)r = mid;
        else l = mid+1;
    }
    return l;
}