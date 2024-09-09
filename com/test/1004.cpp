#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> dp;
int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
   
    dp.resize(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            
            // 检查能否连接
            if (abs(a[i - 1] - b[j - 1]) <= 4) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[N][N] << endl;
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    vector<int> dp(N + 1, 0);
    vector<int> dp_i_1(N+1, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j--) {
            int temp = dp[j];//为dp[i-1][j-1]
            dp[j] = max(dp[j], dp[j - 1]);
            if (abs(a[i] - b[j - 1]) <= 4) {
                dp[j] = max(dp[j], dp_i_1[j - 1] + 1);
            }

            dp[j] = max(dp[j], dp[j]); 
            dp_i_1[]
        }
    }
    cout << dp[N] << endl;
    return 0;
}