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

int maximumMinutes(vector<vector<int>>& grid) {

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m = grid.size(), n = grid[0].size();
    auto bfs = [&](vector<vector<int>>& nodes)-> tuple<int, int, int>{
        vector<vector<int>> time(m, vector<int> (n, -1));    
        queue<vector<int>> q;
        for(auto& node : nodes){
            q.push(node);
            time[node[0]][node[1]] = 0;
        }
        int t = 0;
        while(!q.empty()){
            int size = q.size();
            t++;
            for(int  i = 0; i < size; ++i){
                vector<int> cur = q.front();
                q.pop();
                for(auto& d : dir){
                    int a = cur[0] + d[0], b = cur[1] + d[1];
                    if(a >=0 && a <m && b >=0 && b <n && grid[a][b] == 0 && time[a][b] < 0){
                        q.push({a, b});
                        time[a][b] = t;
                    }
                }
            }
        }
        return {time[m - 1][n - 1], time[m - 1][n - 2], time[m - 2][n - 1]};
    };
    vector<vector<int>> nodes = {{0, 0}};
    auto [human_to_home, m1, m2] = bfs(nodes);
    nodes.clear();
    if(human_to_home == -1)return -1;// 人过不去
    for(int i= 0; i < m; ++i){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                if(i == m-1 && j == n-1)return 0;
                nodes.push_back({i,j});
            }
        }
    }
    auto [fire_to_home, f1, f2] = bfs(nodes);
    if(fire_to_home == -1)return 1000000000;//火不会过去
    if(fire_to_home < human_to_home)return -1;
    int d =  fire_to_home - human_to_home;
            if (m1 != -1 && m1 + d < f1 || // 安全屋左边相邻格子，人比火先到
            m2 != -1 && m2 + d < f2) { // 安全屋上边相邻格子，人比火先到
            return d; // 图中第一种情况
        }
        return d - 1; // 图中第二种情况else return total - arrive-1;
}
int main()
{
    vector<vector<int>> grids = {{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    
    // {{0,2,0,0,1},{0,2,0,2,2},{0,2,0,0,0},{0,0,2,2,0},{0,0,0,0,0}};
    // 
    maximumMinutes(grids);

}

