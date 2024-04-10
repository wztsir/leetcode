#include<bits/stdc++.h>
using namespace std;
char g[20][20];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vis[20][20];
int dfs(int i, int j, int w, int h){
    if(i < 0 || i >= h || j <0 || j >= w || vis[i][j] || g[i][j] == '#')return 0;
    int res = 1;
    vis[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int x = i+ dir[k][0], y = j + dir[k][1];
        res += dfs(x, y, w, h);
    }
    return res;
}
int main(){
    //输入是多组数据，比较新颖
    int w,h;
    while(cin >> w >> h){
        if(!w && !h)break;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < h; i++)scanf("%s", g[i]);
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(g[i][j] == '@'){
                    cout << dfs(i, j, w, h)<< endl;
                    break;
                }
            }
        }
    }
}