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
long long countAlternatingSubarrays(vector<int>& nums) {
    long long res = 0, left = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[i-1])left++;
        else{
            res = res + (left+1)*left / 2;
            left = 1;
        }
    }
    res = res + (left+1)*left / 2;
    return res;
}
int main()
{
    vector<int> ans = {0, 1, 1, 1};
    countAlternatingSubarrays(ans);
   system("pause");
   return 0;
}
