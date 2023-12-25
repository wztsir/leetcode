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
#include<sstream>
using namespace std;

//犯下思维错误，要找的天晴天数是要大于上次下雨的天数的， 天数即index
vector<int> avoidFlood(vector<int>& rains) {
    vector<int> res(rains.size(),1);
    set<int> sun;//天数
    unordered_map<int, int> rain;// 池-天数
    for(int i = 0; i < rains.size(); ++i){
        int pool = rains[i];
        if(pool == 0){
            sun.insert(i);//记录没下雨的时候，防备
        }
        else{
            res[i] = -1;
            if(rain.count(pool)){
                auto it = sun.lower_bound(rain[pool]);
                if(it == sun.end())return {};
                res[*it] = pool;
                sun.erase(it);
            }
            rain[pool] = i;
        }
    }
    return res;
}
int main(){
    vector<int> a = {1,2,0,1,2};
    avoidFlood(a);

}