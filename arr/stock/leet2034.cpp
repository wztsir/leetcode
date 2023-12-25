#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
class StockPrice {
public:
    StockPrice() {
        this->curTimestamp = 0;
    }
    
    void update(int timestamp, int price) {
        if(timePriceMap.count(timestamp)){//更改
            int pre = timePriceMap[timestamp];
            auto it = prices.find(pre);
            prices.erase(it);
        }
        curTimestamp = max(curTimestamp, timestamp);
        timePriceMap[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return timePriceMap[curTimestamp];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
private:
    int curTimestamp;
    unordered_map<int, int> timePriceMap;
    multiset<int> prices;
};

