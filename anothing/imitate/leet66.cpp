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
// digits 全9，ans数组长度为n+1，且内容为 1 与n个0
// 否则， ans数组长度为n, 且内容自然考虑 "每个数位" 的加1
vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    int n = digits.size();
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(digits[i] != 9){
            flag = true;
            break;
        }
    }
    if(!flag){
        ans.resize(n+1, 0);
        ans[0] = 1;
    }else{
        ans.resize(n);
        int cy = 0;
        digits[n-1]++;
        for(int i = n-1; i >= 0; i--){
            ans[i] = (digits[i] + cy) % 10;
            cy =  (digits[i] + cy) / 10;   
        }
    } 
    return ans;   
}
int main()
{
   system("pause");
   return 0;
}
