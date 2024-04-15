// 解决无序号
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s;
//     cin >> s;
//     unordered_map<char, int> m;
//     int size = s.size();
//     int res = 0;
//     for(int i = size-1; i >= 0; --i){
//         if(s[i] == ')')m[')']++;
//         else if(s[i] == ']')m[']']++;
//         else if(s[i] == '('){
//             if(m.count(')') > 0)m[')']--;
//             else res++;
//         }        
//         else{
//             if(m.count(']') > 0)m[']']--;
//             else res++;
//         }
//     }
//     for(auto& it : m){
//         res += it.second;
//     }
//     cout<< res;
// }
#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main(){
    string s;
    cin >> s;
    stack<char> stk;
    int size = s.size();
    int res = 0;
    
    for(int l = size - 1; l >= 0; l--){
        for(int r = l + 1; r < size; r++){
            if((s[l] == '('&& s[r] == ')')|| (s[l] == '['&& s[r] == ']'))dp[l][r] = dp[l+1][r-1] + 2;
            dp[l][r] = max(dp[l][r], max(dp[l+1][r], dp[l][r-1]));
        }
    }
    cout << size - dp[0][size-1];
}