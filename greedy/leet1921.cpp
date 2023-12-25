#include<vector>
#include<algorithm>
using namespace std;
//细节： 在开始时，如果存在0，就直接结束
//贪心，每次都弄最快抵达城市的怪兽

//关键需求，两个数组，如何根据两个数组的除法值对另一个数组进行排序
bool static cmp(const pair<int, int>& x, const pair<int, int>& y){
    return x.first * y.second < x.second * y.first;
}
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    vector<pair<int, int>> ratios;
    for (int i = 0; i < dist.size(); ++i) {
        ratios.push_back({dist[i], speed[i]});
    }
    sort(ratios.begin(), ratios.end(), cmp);
    int res = 0;
    for(res; res < dist.size(); res++){
        ratios[res].first -= ratios[res].second * res;
        if(ratios[res].first <= 0)return res;
    }
    return res;
}
int main(){
    vector<int> dist = {1,3,4};
    vector<int> speed = {1,1,1};
    eliminateMaximum(dist, speed);
}