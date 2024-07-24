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
int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> row(n, 0);
    vector<int> col(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            row[i] = max(row[i], grid[i][j]);
            col[j] = max(col[j], grid[i][j]);
        }
    }
    int total = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           total += min(row[i], col[j]) - grid[i][j];
        }
    }
    return total;
}
int main()
{
   system("pause");
   return 0;
}
