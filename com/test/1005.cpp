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
const int mod = 1e9+7;
int n, q;
vector<int> arr;
vector<vector<int>> memo;
int dfs(int i, int k){
    if(k == 0){
        return 1;
    }else if(i >= n || k < 0)return 0;
    if(memo[i][k] != 0)return memo[i][k];
    int ans = 0;
    for(int v = i+1; v < n; v++){
        if(arr[v] % arr[i] == 0){
            ans = (ans + dfs(v, k-1)) % mod;
        }
    }
    memo[i][k] = ans;
    return ans;
}
int main(){
    cin >> n;
    arr.resize(n);
    memo.resize(n, vector<int>(n-q, 0));
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> q;
    sort(arr.begin(), arr.end());
    int res = 0;
    for(int i = 0; i < n; i++){
        res = (res + dfs(i, n-q-1)) % mod;
    }
    cout << res;
    return 0;
}
