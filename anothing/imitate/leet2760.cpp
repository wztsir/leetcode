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



int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int size = nums.size();
    int ans = 0;
    for(int i = 0; i < size; ++i){
        if(nums[i] % 2 == 0 && nums[i] <= threshold){
            int k = i;
            while(k+1 < size && nums[k]%2 != nums[k+1]%2 && nums[k] <= threshold)k++;
            if(nums[k] > threshold)k--;
            ans = max(ans, k-i+1);
            i = k;
        }
    }
    return ans;
}
int main(){
    vector<int> a = {3,2,5,4};
    longestAlternatingSubarray(a, 5);
}