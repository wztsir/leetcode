#include<vector>
#include<stack>
using namespace std;

//关键是找到每个点管理的区间范围
//区间该点最小，区间点皆大于该点
//找到左右边界小于等于该点
//同时特殊情况，相等，左边小于等于，右边小于
//细节犯错，栈中放置边界下标, 所以条件上比对，要用arr[小标]
const int MOD = 1e9 + 7;
int sumSubarrayMins(vector<int>& arr) {
    vector<int> left(arr.size()), right(arr.size());
    stack<int> s, ss;
    int n = arr.size();
    for(int i = 0; i < n; i++){
      while(!s.empty() && arr[s.top()] > arr[i]) {
        s.pop();
      } 
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    
    for(int i = n-1; i >=0; --i){
      while(!ss.empty() && arr[ss.top()] >= arr[i]){
        ss.pop();
      }
        right[i] = ss.empty() ? n : ss.top();
        ss.push(i);
    }
    long res = 0;//细节由于最后要%,所以res+肯定会超时
    for(int i = 0; i < n; ++i){
      res += (long)(right[i] - i) * ( i - left[i]) * arr[i];   
    }
    return res % MOD;   
}
