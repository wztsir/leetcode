#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
int countWays(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = 0, l =nums.size();
    int res = 0;
    if(nums[0] > n)res++;
    for(int i = 0; i < l; ++i){
        n++;
        if(nums[i] < n ){
            if((i+1 <l && nums[i+1] > n) || i+1 == l){
                res++;
            }
        } 
    }
    return res;
}