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
int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size()-1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(nums[mid] > nums[mid+1])r = mid;
        else l = mid+1;
    }
    return l;
}
int main()
{
   system("pause");
   return 0;
}
