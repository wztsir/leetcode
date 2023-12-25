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

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int s = nums.size();
    vector<int> sum;
    int temp = 0;
    for(int i = 0; i < k; i++){
        temp += nums[i];
    }
    sum.push_back(temp);
    for(int i = k; i < s; i++){
        temp += nums[i] - nums[i-k];
        sum.push_back(temp);
    }
    int n = sum.size();
    vector<int> l(n, 0), r(n, n-1);
    int mx = 0;
    for(int i = 0; i < n; i++){
        if(sum[i] > sum[mx]){
            mx = i;
        }
        l[i] = mx;
    }
    mx = n-1;
    for(int i = n-1; i >= 0; i--){
        if(sum[i] >= sum[mx]){
            mx = i;
        }
        r[i] = mx;
    }
    vector<int> ans;
    mx = 0;
    for(int i = k; i + k <  n; i++){
        if(sum[i] + sum[l[i-k]] + sum[r[i+k]] > mx){
            ans = {l[i-k], i, r[i+k]};
            mx = sum[i] + sum[l[i-k]] + sum[r[i+k]];
        }
    }
    return ans;
}
int main(){
    vector<int> sum = {1,2,1,2,6,7,5,1};
    maxSumOfThreeSubarrays(sum, 2);

}