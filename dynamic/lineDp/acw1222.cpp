#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main(){//核心解法，寻找最长回文子序列
    string str;
    cin >> str;
    // scanf("%s", str);
    int size = str.size();
    for(int l = size-1; l >= 0; l--){
        dp[l][l] = 1;
        for(int r = l + 1; r < size; r++){
            if(str[l] == str[r])dp[l][r] = dp[l+1][r-1] + 2;
            dp[l][r] = max(dp[l][r], max(dp[l+1][r], dp[l][r-1]));
        }
    }
    printf("%d", size - dp[0][size-1]);
    return 0;

}