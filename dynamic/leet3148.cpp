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
int maxScore(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> map(grid);
    int ans = INT_MIN;
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            int temp;
            if(i == m-1 && j == n-1)continue;
            if(i == m-1)temp = map[i][j+1];
            else if(j == n-1)temp = map[i+1][j];
            else temp = max(map[i][j+1], map[i+1][j]);
            map[i][j] = max(temp, grid[i][j]);
            ans = max(temp-grid[i][j], ans);
        }
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
