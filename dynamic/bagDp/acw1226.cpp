#include<bits/stdc++.h>
using namespace std;
const int N= 105;
bool dp[N][10000];
int gcd(int a,int b){
    return b == 0 ? a : gcd(b, a % b);
}
int main(){
    int n;
    int a[N];
    cin >> n;
    int d = 0;//细节的，一开始的d不是0
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        d = gcd(d, a[i]);
    }
    if(d != 1){
        cout<<"INF";
        return 0;
    }
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 10000; j++){
            dp[i][j] = dp[i-1][j] || (j < a[i] ? false : dp[i][j-a[i]]);
        }
    }
    int res = 0;
    for(int i = 0; i < 10000; i++){
        if(!dp[n][i])res++;
    }
    cout<< res;
}