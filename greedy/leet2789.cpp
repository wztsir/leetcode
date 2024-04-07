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
long long maxArrayValue(vector<int>& nums) {
    int i = nums.size()-1;
    vector<long long> temp(nums.begin(), nums.end());
    long long res = nums[i];
    for(i; i > 0; i--){
        if(temp[i-1] <= temp[i]){
            temp[i-1] += temp[i];
        }
        res = max(res, temp[i-1]);
    }
    return res;
}
int main()
{
   system("pause");
   return 0;
}
