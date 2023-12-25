#include<vector>
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
class StockSpanner {
private:
    stack<pair<int, int>> map;
    int index;
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        pair<int, int> cur(price, ++index);
        while(!map.empty() && map.top().first <= price){
            map.pop();
        }
        int before =  map.empty() ? 0 : map.top().second;
        map.push(cur);
        return index - before;
    }
};