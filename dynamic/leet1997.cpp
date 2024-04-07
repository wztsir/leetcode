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
int firstDayBeenInAllRooms(vector<int>& nextVisit) {
   int size = nextVisit.size();
   const int MOD = 1e9 + 7;
   vector<int> dp(size);
   for(int i = 1; i < size; i++){
      dp[i] =( 2 * dp[i-1] - dp[nextVisit[i-1]] + 2 + MOD) % MOD;
   }
   return dp[size-1];
}
int main()
{
   system("pause");
   return 0;
}

