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
int countBits(int num){
    int count = 0;
    while(num){
        count += num & 1;
        num >>= 1;
    }
    return count;
}
bool canSortArray(vector<int>& nums) {
    vector<int> arr(nums);
    sort(arr.begin(), arr.end());
    for(int i = 0; i < nums.size(); i++){
        if(countBits(nums[i]) != countBits(arr[i])) return false;
    }
    return true;    

}
int main()
{
    vector<int> nums = {75,34,30};
    canSortArray(nums);
   system("pause");
   return 0;
}
