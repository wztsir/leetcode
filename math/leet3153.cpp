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
long long sumDigitDifferences(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size(), index = 0;
    unordered_map<int, int> mp;
    int temp = nums[0];
    while(temp){
        mp.clear();
        for(int i = 0; i < n; i++){
            int a = nums[i] / pow(10, index);
            a %= 10;
            mp[a]++;
        }
        for(auto& m : mp){
            ans += m.second * (n-m.second);
        }
        index++;
        temp /= 10;
    }
    ans /= 2;
    return ans;
}
int main()
{
    vector<int> arr = {13,23,12};
   system("pause");
   return 0;
}
