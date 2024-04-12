#include<bits/stdc++.h>
using namespace std;
int dp[12][12];
int main(){
    int t;
    cin >> t;
    for(int i = 0; i <= 10; i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i<= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(i < j)dp[i][j] = dp[i][j-1];
            else dp[i][j] = dp[i][j-1] + dp[i-j][j];
        }
    }
    int m, n;

    while(t--){
        scanf("%d%d", &m, &n);
        printf("%d\n", dp[m][n]);
    }
    return 0;
}