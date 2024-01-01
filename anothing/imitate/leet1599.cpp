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
int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
    if(boardingCost*4 <= runningCost)return -1;
    int max_money = 0,remain = 0,money = 0;
    int res = 0,round = 0;
    int i = 0,size = customers.size();
    while(remain > 0 || i < size){
        round ++;
        if(i < size){
            remain += customers[i];
            i++;
        }
        if(remain >= 4){
            money += boardingCost*4 - runningCost;
            remain -= 4;
        }else{
            money += boardingCost*remain - runningCost;
            remain = 0;
        }
        if(money > max_money){
            max_money = money;
            res = round;
        }
    }
    return max_money > 0 ? res : -1;
}
int main()
{
   system("pause");
   return 0;
}
