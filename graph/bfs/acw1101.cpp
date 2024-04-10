#include<bits/stdc++.h>
using namespace std;
char g[200][200];
int vis[200][200];
int dir[4][2] ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int  bfs(int i, int j, int r, int c){
    int res = 0;
    queue<pair<int, int>> q;
    q.emplace(i, j);
    memset(vis, 0, sizeof(vis));
    while(!q.empty()){
        int s = q.size();
        res++;
        for(int k = 0; k < s; k++){
            auto node = q.front();
            q.pop();
            for(int u = 0; u < 4; u++){
                int ne_x = node.first + dir[u][0], ne_y = node.second + dir[u][1];
                if(ne_x >= 0 && ne_x < r && ne_y >= 0 && ne_y < c){
                    if(g[ne_x][ne_y] == '.' && vis[ne_x][ne_y] == 0){
                        q.emplace(ne_x, ne_y);
                        vis[ne_x][ne_y] = 1;
                    }else if(g[ne_x][ne_y] == 'E')return res;
                }
            }
        }
    }
    return 0;
}
int main(){
    int T, R, C;
    cin >> T;
    while(T--){
        scanf("%d%d", &R, &C);
        for(int i = 0; i < R; i++){
            scanf("%s", g[i]);
        }
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(g[i][j] == 'S'){
                    int res = bfs(i, j, R, C);
                    if(res)printf("%d\n", res);
                    else printf("oop!\n");
                }
            }
        }
    }
}