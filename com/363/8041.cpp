#include<vector>
#include<unordered_set>
#include<cmath>
#include<algorithm>
using namespace std;
bool isPerfectSquare(int n) {
    int root = static_cast<int>(sqrt(n));
    return root * root == n;
}
long long maximumSum(vector<int>& nums) {
    long long res = -1;
    int l = nums.size();
    vector<long long> ma(l+1, 0);
    for(int i = 1; i <= l; ++i){
        ma[i] = nums[i-1];
    }
    ma[1] = nums[0];
    for(int i = 1; i <= l; ++i){//其实就快做出来了
        for(int j = i-1; j >=1; --j){
            if(isPerfectSquare(i * j)){
                ma[i] = ma[j] + nums[i-1];
                break;
            }
        }
    }
    auto it = max_element(ma.begin(),ma.end());
    res = *it;
    return res;
}
//O(n)的写法
long long maximumSum(vector<int>& nums) {
    long long res = 0;
    int l = nums.size();
    for(int i = 1; i <= l; ++i){
        long long temp = 0;
        for(int j = 1; i * j * j <= l; j++){
            temp += nums[i * j * j - 1];
        }
        res = max(res, temp);
    }
    return res;
}