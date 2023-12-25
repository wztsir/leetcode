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
int findTheLongestBalancedSubstring(string s) {
    int n = s.size();
    int zero = 0, one = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1')continue;
        int temp = i;
        if(s[i] == '0'){
            while(i+1 < n && s[i+1] == '0')i++;
            zero = i - temp + 1;
            temp = i;
        }
        if(i == n-1)break;  //后面不可能有1了
        while(i+1 < n && s[i+1] == '1')i++;
        one = i - temp;// (], 所以不用加一
        ans = max(ans, 2 * min(zero, one));
        zero = 0, one = 0;
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
