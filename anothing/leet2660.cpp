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

//这道题关键在于审题，不能被示例有意误导


//这里分析的视角是第i轮
// 假设玩家在第 i 轮中击中 xi 个瓶子。玩家第 i 轮的价值为：

// 如果玩家在该轮的前两轮的任何一轮中击中了 10 个瓶子，则为 2xi 。
// 否则，为 xi 。
// 玩家的得分是其 n 轮价值的总和。
int isWinner(vector<int>& player1, vector<int>& player2) {
    int p1 = 0, p2 = 0;
    int c1 = 0, c2 = 0;
    int n = player1.size();
    for(int i = 0; i < n; i++){
        if(!c1)p1 += player1[i];
        else{
            p1 += player1[i] * 2;
            c1 --;
        }
        if(!c2)p2 += player2[i];
        else{
            p2 += player2[i] * 2;
            c2 --;
        }
        if(player1[i] == 10)c1 = 2;
        if(player2[i] == 10)c2 = 2;
    }
    if(p1 > p2)return 1;
    else if(p1 < p2)return 2;
    return 0;
}