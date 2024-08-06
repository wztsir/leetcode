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
unsigned long long ans = 0;
int mod = 1e9 +7;
unsigned long long factorial(int n, int k) {
    unsigned long long result = 1;
    for (int i = ; i <= n; ++i) {
        result =(result * i)%mod;
    }
    return result;
}
void dfs(int zero, int  one, int endzero, int endone, int numzero, int numone,int limit){
    if(numzero == zero && numone == one)ans++;
    if(numzero < zero && endzero < limit){//可以补0
        dfs(zero, one, endzero+1, 0, numzero+1, numone, limit);
    }
    if(numone < one && endone < limit){//可以补1
        dfs(zero, one, 0, endone+1, numzero, numone+1, limit);
    }
}
int numberOfStableArrays(int zero, int one, int limit) {
    if(limit >= zero && limit >= one){
        int temp = (factorial(one) * factorial(zero)) % mod;
        unsigned long long temp1 = factorial(zero + one);
        ans =  (factorial(zero + one) + mod / temp) % mod;
        return ans;
    }
    dfs(zero, one, 0, 0, 0, 0, limit);
    return ans % mod;
}
int main()
{
   numberOfStableArrays(13, 20, 93);
   return 0;
}
