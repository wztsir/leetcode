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
//对于极端情况，全0，没有考虑到
int orangesRotting(vector<vector<int>>& grid) {
    int total = 0;
    queue<pair<int, int>> q;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] != 0)total++;
            if(grid[i][j] == 2){
                q.emplace(i, j);
            }
        }
    }
    int decay = q.size();
    if(q.size() == 0 && total != 0)return -1;
    else if (q.size() == total)return 0;
    int time = 0;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        time++;
        int size = q.size();
        for(int i = 0; i < size; i++){
            pair<int, int> node = q.front();
            q.pop();
            for(int d = 0; d < 4; d++){
                int u = node.first + dir[d][0];
                int v = node.second + dir[d][1];
                if(u >= 0 && u < grid.size() && v >= 0 && v < grid[0].size() && grid[u][v] == 1){
                    grid[u][v] = 2;
                    q.emplace(u, v);
                    decay ++;
                }
            }
        }
        if(decay == total)return time;
    }
    return -1;
}
int main()
{
    vector<vector<int>> grid = {{2,1,1}, {1,1,1}, {0,1,2}};
    orangesRotting(grid);
   system("pause");
   return 0;
}
