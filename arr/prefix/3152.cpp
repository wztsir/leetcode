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
// 暴力解法不行 n^2
vector<bool> isArraySpecial2(vector<int>& nums, vector<vector<int>>& queries) {
    int n = queries.size();
    vector<bool> ans(n);
    for(int q = 0; q < n; q++){
        int left = queries[q][0], right = queries[q][1];
        bool flag = true;
        for(int i = left+1; i <= right; i++){
            if(((nums[i] ^ nums[i-1]) & 1) == 0){
                flag = false;
                break;
            }
        }
        ans[q] = flag;
    }
    return ans;
}
// 利用前缀和的思路， 
vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<bool> ans;
    vector<int> prefix(n, 0);
    // temp[0] = 0;
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + !((nums[i] ^ nums[i-1]) & 1);
    }
    for(auto& q : queries){
        int left = q[0], right = q[1];
        if(prefix[right] == prefix[left])ans.push_back(true);
        else ans.push_back(false);
    }
    return ans;
}
int main()
{
    vector<int> t = {3,4,1,2,6};
    vector<vector<int>> q = {{0, 4}};
    isArraySpecial(t, q);
   system("pause");
   return 0;
}
