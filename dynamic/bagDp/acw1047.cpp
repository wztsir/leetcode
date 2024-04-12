#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int main(){
    int n, k;
    cin >> n >> k;
   for(int i = 0; i < n; i++){
        int candy;
        scanf("%d", &candy);
        if(i == 0){
            for(int j = 0; j < k; j++){
                if(j == candy % k)dp[0][j] = candy;
                else dp[0][j] = 0;
            }
        }else{
            for(int j = 0; j < k; j++){
                if( dp[i-1][(j + k - candy%k)%k] == 0)dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][(j + k - candy%k)%k] + candy);
            }
        }
    }
    printf("%d", dp[n-1][0]);
}