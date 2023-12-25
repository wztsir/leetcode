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

int minDeletion(vector<int>& nums) {
    int ans = 0, size = nums.size();
    for(int i = 0; i+1 < size; i++){
        if((i-ans) % 2 == 0){
            if(nums[i] == nums[i + 1])ans++;
        }
    }
    if((size - ans) % 2 == 1)ans++;
    return ans;
}
int main(){
    vector<int> a = {1,1,2,2,3,3};
    minDeletion(a);
}