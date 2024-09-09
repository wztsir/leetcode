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



bool increasingTriplet2(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        int j = i;
        for(; j < n; j++){
            if(nums[j] > nums[i]){
                for(int k = j; k < n; k++){
                    if(nums[k] > nums[j]){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    int first = nums[0];
    int second = INT_MAX;
    for(int i = 1; i < n; i++){
        if(nums[i] > second)return true;
        else if(nums[i] > first){
            second = nums[i];
        }else{
            first = nums[i];
        }
    }
    return false;
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    increasingTriplet(arr);
}