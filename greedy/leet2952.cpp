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
int minimumAddedCoins(vector<int>& coins, int target) {
    sort(coins.begin(), coins.end());
    int left = 0,res = 0, i = 0;
    while(i < coins.size()){
        if(coins[i] > left){
            if(coins[i] == left+1){
                left += coins[i];
                i++;
            }else{
                left = left*2+1;
                res++;
            }
            
        }else if(coins[i] <= left){
            left += coins[i];
            i++;
        }
        if(left >= target)return res;
    }
    while(left < target){
        left = left*2+1;
        res++;
    }
    return res;
}
int main()
{
   system("pause");
   return 0;
}
