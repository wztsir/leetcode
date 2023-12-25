#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include <algorithm>
#include<unordered_map>
using namespace std;
//int main() {
//    int C, Wr, Hr, Wb, Hb;
//    cin >> C >>  Hr >>  Hb>>Wr >>Wb;
//    vector<int> dp(C + 1, 0);
//    for (int i = 1; i <= C; i++) {
//        if (i >= Wr) {
//            dp[i] = max(dp[i], dp[i - Wr] + Hr);
//        }
//        if (i >= Wb) {
//            dp[i] = max(dp[i], dp[i - Wb] + Hb);
//        }
//    }
//    cout << dp[C] << endl;
//    return 0;
//}
//
//int main() {
//    int C, Wr, Hr, Wb, Hb;
//    cin >> C >> Hr >> Hb >> Wr >> Wb;
//    int dp1 = 0, dp2 = 0, dp3 = 0, dp4 = 0;
//    for (int i = 1; i <= C; i++) {
//        dp1 = dp2;
//        dp2 = dp3;
//        dp3 = dp4;
//        dp4 = 0;
//        if (i >= Wr) {
//            dp4 = max(dp4, dp1 + Hr);
//        }
//        if (i >= Wb) {
//            dp4 = max(dp4, dp2 + Hb);
//        }
//    }
//    cout << dp4 << endl;
//    return 0;
//}