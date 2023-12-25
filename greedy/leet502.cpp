#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//从小于等于w的cap里选择最大的pro

bool static cmp(pair<int, int>& a, pair<int, int>& b){
    return a.second < b.second;
}
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    vector<pair<int, int>> cp;
    for(int i = 0; i < profits.size(); ++i){
        cp.emplace_back(profits[i], capital[i]);
    }
    sort(cp.begin(), cp.end(), cmp);
    priority_queue<int> h;//最大堆
    int i = 0;
    while(k--){
        while(i < capital.size() && w >= cp[i].second){
            h.push(cp[i].first);
            i++;
        }
        if(h.empty())break;
        w += h.top();
        h.pop(); 
    }
    return w;
}