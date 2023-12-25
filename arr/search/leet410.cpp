#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
// #include"TreeNode.h"
using namespace std;
int splitArray(vector<int>& nums, int k) {
    if(nums.size() == 0)return 0;
    auto f = [&](int x){
        int need = 1, sum =0, s = nums.size();//一定存在数据，先开了一个包
        for(int i = 0; i < s; ++i){
            if(sum + nums[i] > x){
                need++;
                sum = nums[i];
            }else sum += nums[i];
        }
        return need;
    };
    int l = * max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 1);
    while(l < r){
        int mid = l + (r-l)/2;
        if(f(mid) <= k){
            r = mid;
        }else if(f(mid) > k){
            l = mid + 1;
        }
    }
    return l;
}
int main(){
    vector<int> v= {1,4,4};
    int k = 3;
    splitArray(v, k);
}