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
int knightDialer(int n) {
    if(n == 1)return 10;
    vector<int> dp1(10, 1);
    vector<int> dp2(10, 0);
    int M = 1e9 +7;
    for(int i = 1; i <= n-1; i++){
        dp2[0] = (dp1[6] + dp1[4]) % M;
        dp2[2] = (dp1[7] + dp1[9]) % M;
        dp2[5] = 0;
        dp2[8] = (dp1[1] + dp1[3]) % M;
        dp2[1] = (dp1[6] + dp1[8]) % M;
        dp2[4] = (0LL + dp1[0] + dp1[3] + dp1[9]) % M;
        dp2[7] = (dp1[2] + dp1[6]) % M;
        dp2[3] = dp2[1];
        dp2[6] = dp2[4];
        dp2[9] = dp2[7];
        dp1 = dp2;
    }
    int ans = 0;
    for(int j = 0; j<10; j++){
        ans = (ans + dp2[j]) % M;
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
