
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
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>

using namespace std;
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    map<int, int, greater<int>> car;
    for(int i = 0; i < position.size(); ++i){
        car[position[i]] = speed[i];
    }
    int res = 0;
    double time = 0;
    for(auto& c : car){
        if(((target - c.first) * 1.0 / c.second) > time){
            time = (target - c.first)*1.0 / c.second;
            res++;
        }
    }
    return res;
}