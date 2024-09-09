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
vector<vector<int>> mp;
vector<vector<int>> memo;
int r, c;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dfs(int i, int j){
    if(memo[i][j] != 0)return memo[i][j];

    int temp = 0;
    for(int k = 0; k < 4; k++){
        int a = i + dir[k][0], b = j + dir[k][1];
        if(a >= 0 && a < r && b >= 0 && b < c && mp[a][b] < mp[i][j]){
            temp = max(temp, dfs(a, b));
        }
    }
    temp++;
    memo[i][j] = temp;
    return temp;
    
}
int main(){
    
    cin >> r >> c;
    mp.resize(r, vector<int>(c));
    memo.resize(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mp[i][j];
        }
    }
    int res = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            res = max(res, dfs(i, j));
        }
    }
    cout << res;
    return 0;
}


