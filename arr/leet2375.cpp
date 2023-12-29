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
long long minCost(vector<int>& nums, int x) {
    int n = nums.size();
    vector<long long> s(n);
    for(int i = 0; i < n; i++){
        s[i] = (long long)i*x;
    }
    for(int i = 0; i < n; i ++){
        int mn = nums[i];//考虑的重心是第i个元素在操作j次时的最小值
        for(int j = 0; j < n; j++){//分别计算出第i个元素在操作j次的最小值
            mn = min(mn, nums[(i+j) % n]);
            s[j] += mn;
        }
    }
    return *min_element(s.begin(), s.end());
}
int main()
{
   system("pause");
   return 0;
}
