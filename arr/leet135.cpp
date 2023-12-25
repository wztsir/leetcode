#include<vector>
using namespace std;
//分为上山与下山两种情况
//极高点需要同时考虑两种情况
//不断上山与下山,即左右遍历
//很棒，左右遍历即下山也可以看作上山
int candy(vector<int>& ratings) {
    vector<int> can(ratings.size(), 1);
    for(int i = 1; i < ratings.size(); ++i){
        if(ratings[i] > ratings[i-1])can[i] = can[i-1] + 1;
    }
    for(int i = ratings.size()-2; i >= 0; --i){
        if(ratings[i] > ratings[i+1] && can[i+1] + 1 > can[i])can[i] = can[i+1] + 1;
    }
    int res = 0;
    for(int i = 0; i < ratings.size(); ++i){
        res += can[i];
    }
    return res;
}