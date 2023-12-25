#include<vector>
#include<unordered_set>
using namespace std;
int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int res = 0, s = nums.size();
    unordered_set<int> v;
    for(int i = 0; i < s; i++){
        int c = 0, n = i;
        while (n > 0) {
            c += n & 1;
            n >> 1;
        }
        if(c == k)res += nums[i];

    }
    return res;
}
        // if(c == k){
        //     res += nums[i];
        //     v.insert(i);
        //     int t = i * 2;
        //     while(t < s){
        //         res += nums[t];
        //         v.insert(t);
        //         t *= 2;
        //     }
        // }