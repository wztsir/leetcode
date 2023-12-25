#include<vector>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;
//+a -b
//难点：会一直循环下去，正数没有限制，
//广度优先，但是空间无限，没有终止条件
//简单的：直接选中一个极大的值，直接糊弄，AC过所有的检测点
//a == b
//a > b

//同时更加细节的，由于不能同时两次后退，所以方向是特殊状态，需要s共同考虑到, （简单的直接相乘即可）
int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    unordered_set<int> s(forbidden.begin(),forbidden.end());
    s.insert(0);
    queue<tuple<int,int, int>> q;
    q.emplace(0,0,0);
    // int d = 0;
    int lower = 0, upper = max(*max_element(forbidden.begin(), forbidden.end()) + a, x) + b;
    while(!q.empty()){
        int sq = q.size();
        for(int i = 0; i < sq; ++i){
            auto [c, dir, d] = q.front();
            q.pop();
            if(c == x)return d;
            int t1 = c + a, t2 = c - b;
            // if(t1 == x || t2 == x)return d+1; 错误，没有进行s，判断，可以状态是被禁止的
            if(t1 <= upper && s.count(t1) == 0){
                s.insert(t1);
                q.push(tuple(t1, 1, d+1));
            }
            if(dir == 1 && t2 > 0 && s.count(t2) == 0){
                s.insert(t2 * -1);
                q.push(tuple(t2, 0, d+1));
            }
        }
        

    }
    return -1;
}