#include<vector>
#include<queue>
// #include"ListNode.h"
#include<unordered_set>
using namespace std;
//坐标与位置的映射

int snakesAndLadders(vector<vector<int>>& board) {
    queue<int> q;
    unordered_set<int> vis; 
    vis.insert(1);
    q.push(1);
    int d = 0, n = board.size();
    while(!q.empty()){
        int sq = q.size();//细节犯错，q.size()随时在变化
        for(int t = 0; t < sq; ++t){
            int cur = q.front();
            q.pop();
            if(cur == n*n)return d;
            for(int i = 1; i <= 6; ++i){
                int nxt  = cur + i;
                if(nxt > n*n)break;
                int w,v;
                if(((nxt-1)/n)%2 == 0){
                v = (nxt-1) % n;
                }else{
                v = n - 1 - (nxt - 1) % n;
                }
                w = n - 1 - (nxt-1)/n;
                if(board[w][v] != -1)nxt = board[w][v];//必须要这个，可以减去很多枝
                if(nxt == n*n)return d+1;//减枝
                if(vis.count(nxt)==0){
                    q.push(nxt);
                    vis.insert(nxt);
                }
            }
        }
        d++;

    }
    return -1;
}
int main(){
    vector<vector<int>> b = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    snakesAndLadders(b);
}