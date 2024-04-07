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
int maxBottlesDrunk(int numBottles, int numExchange) {
    int full = numBottles, empty = 0;
    int res = 0;
    while(full > 0 || empty >= numExchange){
        if(empty < numExchange){
            empty += full;
            res += full;
            full = 0;
        }else{
            empty -= numExchange;
            full++;
            numExchange++;
        }
    }
    return res;
}
int main()
{
    maxBottlesDrunk(13, 6);
}
