#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric> // 为了使用std::accumulate()函数
#include <sstream>
#include <functional>
using namespace std;
// 我首先看了灵神的答案，知道要使用动态规划，和位运算，但是其中有几个点，我自己思考了后，补充了

// 动态规划方程： dfs(m, u) = max(dfs(m-1, v) + S(u))
// 解释一下，u，v两个都是座位的分布状态，这道题里用位运算，所以都是int表示， u->v具体看灵神公式

// 位运算的前置知识，灵神总结的很详细：https://leetcode.cn/circle/discuss/CaOJ45/

// 补充一：聚焦于每一排的状态，如何计算
// m排的状态是直接穷举出来，u是m排的子集，m排位置个数是n,就是每一个位置都可以坐或者不坐，就有2^n情况,同时要求每个位置左右不能坐，所以删除2个位置挨着的情况，这就是所有的U的状态
// 然后S（u）,直接计算每个U里面有多少个位置坐了，即有多少位是1

// 补充二：为什么

int maxStudents(vector<vector<char>> &seats)
{
    int m = seats.size(), n = seats[0].size();
    vector<int> mp(m);
    for (int i = 0; i < m; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (seats[i][j] == '.')
            {
                temp |= 1 << j;
            }
        }
        mp[i] = temp;
    }
    vector<vector<int>> memo(m, vector<int>(1 << n , -1));
    function<int(int, int)> dfs = [&](int m, int s) -> int{
        if(memo[m][s] != -1)return memo[m][s];
        if (m == 0){
            if (s == 0)
            {
                return 0;
            }
            int lb = s & -s;
            return dfs(m, s & ~(lb * 3)) + 1;
        }
        // 枚举m排的所有状态

        int res = dfs(m - 1, mp[m - 1]); // 第 m 排空着
        for (int t = s; t; t = (t - 1) & s){
            if ((t & (t >> 1)) == 0){
                int next = mp[m - 1] & ~(t << 1 | t >> 1);
                res = max(res, dfs(m - 1, next) + __builtin_popcount(t));
            }
        }
        return  memo[m][s] = res;
    };
    return dfs(m - 1, mp[m - 1]);
}

int main() {

            vector<vector<char>> seats = {{'#', '.', '#', '#', '.', '#'},
                                     {'.', '#', '#', '#', '#', '.'},
                                     {'#', '.', '#', '#', '.', '#'}};
    maxStudents(seats);
    cout<<0;
    return 0;
}