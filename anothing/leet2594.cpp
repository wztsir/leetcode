#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

// long long repairCars(vector<int>& ranks, int cars) {
//     if(ranks.size() == 0 || cars == 0)return 0;
//     sort(ranks.begin(), ranks.end());
//     long long res = INT_MAX;
//     int i = 1;
//     while(true){
//         int t = cars;
//         long long time;
//         time = (long long)ranks[ranks.size()-1] * i * i;
//         if(time >= res)break;
//         t -= i;
//         for(int j = ranks.size()-2; j >= 1; --j){
//             t -= (int) sqrt(time/ranks[j]);
//             if(t <= 0) break;
//         }
//         if(t > 0)time = max(time, (long long)ranks[0] * t * t);
//         if(time >= res)break;
//         res = time;
//         ++i;
//     }
//     return res;
    
// }

//二分法，因为对于时间t而言，如果t符合，>=t的都符合
// 如果 t不符合，小于t的都不符合
using ll = long long;
bool check(ll t, vector<int>& ranks, int cars){
    ll r = 0;
    for(auto it : ranks){
        r += sqrt(t / it);
    }
    return r >= cars;
}
long long repairCars(vector<int>& ranks, int cars) {
    if(ranks.size() == 0 || cars == 0)return 0;
    ll l = 1, r = (ll)ranks[0] * cars * cars;
    while(l < r){
        ll m = (l + r) >> 1;
        if(check(m, ranks, cars)){
            r = m;//因为是[)所以r直接取m
        }else{
            l = m+1;
        }
    }
    return l;
}
int main(){
    vector<int> ranks = {1,1,3,3};
    int cars = 74;
    repairCars(ranks, cars);
}