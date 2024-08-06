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
int ans = 1;
void dfs(int cur, int n){
    if(cur > n)return;
    ans++;
    if(cur & 1){
        dfs(cur<<1, n);
    }else{
        dfs(cur<<1, n);
        dfs((cur<<1) +1, n);
    }
}
int findIntegers(int n) {
    dfs(1, n);
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
