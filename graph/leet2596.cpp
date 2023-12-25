#include<vector>
#include<algorithm>
using namespace std;
bool checkValidGrid(vector<vector<int>>& grid) {
    if(grid[0][0] != 0)return false;
    int n = grid.size();
    vector<pair<int, int>> q(n * n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            q[grid[i][j]] = {i, j};
        }
    }
    int row = 0, col = 0;
    for(int i = 1; i < n * n; ++i){
        int row_t = q[i].first;
        int col_t = q[i].second;
        if((abs(row_t - row) == 2 && abs(col_t - col) == 1) || (abs(row_t - row) == 1 && abs(col_t - col) == 2)) {
            row = row_t;
            col = col_t;
        }else return false;
    }
    return true;
}