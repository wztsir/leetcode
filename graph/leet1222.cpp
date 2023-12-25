#include<vector>
using namespace std;
vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<vector<int>> res;
    vector<vector<int>> map(8, vector<int>(8));
    for(auto& it : queens){
        map[it[0]][it[1]] = 1;
    }
    int row = king[0], col = king[1];
    for(int i = 0; i < dir.size(); ++i){
        int a = row + dir[i][0], b = col + dir[i][1];
        while(a < 8 && a >= 0 && b < 8 && b >= 0){
            if(map[a][b]){
                res.push_back({a, b});
                break;
            }
            a += dir[i][0];
            b += dir[i][1];
        }
    }
    return res;
}