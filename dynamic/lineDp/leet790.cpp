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
const int mod = 1e9+7;
int numTilings(int n) {
    if(n == 1)return 1;
    if(n == 2)return 2;
    int dp_n_1 = 1, dp_n_2 = 2, dp_n;
    int ans = 1;
    for(int i = 3; i <= n; i++){
        dp_n =(dp_n_1 + dp_n_2 + ans * 2) % mod;
        ans += dp_n_2;
        dp_n_2 = dp_n_1;
        dp_n_1 = dp_n;
    }
    return dp_n;
}
int main()
{
   system("pause");
   return 0;
}
