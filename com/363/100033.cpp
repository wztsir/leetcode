
//二分法，有上界，有可以移动的范围
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;
int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
    int res = 0;
    for(auto& com : composition){
        auto check = [&](int m){
            long long money = 0;
            for(int i = 0; i < n; ++i){
                long long diff = (long long)m * com[i] - stock[i];
                if(diff > 0){//判断低级错误
                    money += (long long)diff * cost[i];
                    if(money > budget)return false;
                }
            }
            return true;
        };

        int l = 0, r = stock[0] + budget + 1;
        while(l < r){
            int m = l + (r - l)/2;
            if(m == 2)int q;
            if(check(m)){
                
                l = m+1;
            }else{
                r = m;
            }
        }
        res = max(l - 1, res);
    }
    return res;
}
int main(){
    int n = 4, k = 9, b = 55;
   vector<vector<int>> composition = 
    {{8,3,4,2},{3,9,5,5},{1,7,9,8},{7,6,5,1},{4,6,9,4},{6,8,7,1},{5,10,3,4},{10,1,2,4},{10,3,7,2}};
    vector<int> stock = {9,1,10,0};
    vector<int> cost = {3,4,9,9};
    maxNumberOfAlloys(n,k, b, composition, stock, cost);
}