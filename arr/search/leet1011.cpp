
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<cmath>
#include"TreeNode.h"
#include <numeric>  // 为了使用std::accumulate()函数 
using namespace std;
//二分搜索不好debug，必须要足够熟练代码， l,r， f(x), 以及mid的左右
int shipWithinDays(vector<int>& weights, int days) {
    if(weights.size() == 0)return 0;
    auto f = [&](int x){
        int d = 0, temp = 0;
        for(int i = 0; i < weights.size(); ++i){
            temp += weights[i];
            if(temp >= x){
                if(temp >x){
                    i--;
                }
                temp = 0;
                d++;
            }else if(i == weights.size()-1)d++;
        }
        return d;
    };
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 1);//需指定初始值
    while(l < r){
        int mid = l + (r-l)/2;
        if(f(mid) == days){
            r = mid;
        }else if(f(mid) > days){
            l = mid + 1;
        }else{
            r = mid;
        }
    }

    return l;
}