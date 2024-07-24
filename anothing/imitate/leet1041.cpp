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
// 1、统计LR次数，对4取余

// 2、方向不改变，一次循环， 到达（0，0）


// 不为于原点， 同时方向朝北 -> 逃离 -> false 否则 true
// int y, x // 点的坐标
// int dirction = [0, 1, 2, 3]//北 西 南 东

// int index = 0;
//  L : index = (index+1) % 4;
//  R : index = (index  + 3) % 4;
// G
// if('G'){
//    x+=direc[index][0];
//  y+=direc[index][1];
//}

// x , y
//  vector<vector<int>> direc {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
bool isRobotBounded(string instructions) {
    int x, y;
    int index;
    // 不在原点， 同时 方向朝北
    // 不在原点 -> x, y 有一个不为0
    // if(index == 0 && (x ！= 0 || y != 0))
    // if(index == 0 && !(x == 0 && y == 0))
    // 0、x = x + 0, y = y + 1
    // 1、x = x - 1, y = y + 0
    // 2、x = x + 0, y = y - 1
    // 3、x = x + 1, y = y + 0
    vector<vector<int>> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    x = x + dir[index][0];
    y = y + dir[index][1];
}
int main()
{
   system("pause");
   return 0;
}
