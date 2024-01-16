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

//数位DP的模板题
//数位DP的特点在于对limit变量的利用

// 细节一
//在记忆化过程中，可以画二维图理解，高位 Limit false后面低位都是false，所以必须dp[i][j]只记录false的情况，因为i,j相同，L为true影响范围更小，舍弃考虑
//然后后面要使用与修改dp[][]都需要考虑Limit值

// 细节二
// 取模，最后加法，可能会溢出，所以加上MOD，将负数变成正数
vector<vector<int>> dp;
int ma, mi;
const int MOD = 1e9 + 7;
int get(string num, int i, int j, bool limit){
    if(j > ma)return 0;
    if(i == -1)return j >= mi;
    if(!limit && dp[i][j] != -1)return dp[i][j];
    int up = limit ? num[i]-'0' : 9;
    int res = 0;
    for(int x = 0; x <= up; x++){
        res = (res +get(num, i-1, j + x, limit && x == up)) % MOD;
    }
    if(!limit)dp[i][j] = res;
    return res;
}
int count(string num1, string num2, int min_sum, int max_sum) {
    int length = num2.size();
    dp.resize(length, vector<int>(min(9 * length, max_sum)+1, -1));
    ma = max_sum, mi = min_sum;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int res = (get(num2, num2.size()-1, 0, true) - get(num1, num1.size()-1, 0, true)+MOD) % MOD;
    int temp = 0;
    for(auto c : num1)temp += c-'0';
    res += temp >= min_sum && temp <= max_sum;
    return res;
}
int main()
{
    string a1 = "1";
    string a2 = "12";
    int n1 = 1, n2 = 8;
    count(a1, a2, 1, 8);
   system("pause");
   return 0;
}
