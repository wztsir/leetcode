#include<vector>
#include<set>
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
// #include"TreeNode.h"
using namespace std;

int numFriendRequests(vector<int>& ages) {
    sort(ages.begin(), ages.end());
    auto f = [&](double t){
        int l = 0, r = ages.size();
        while(l < r){
            int mid = l +  (r-l)/2;
            if(ages[mid] == t)l = mid + 1;
            else if(ages[mid] > t)r = mid;
            else  l = mid +1;
        }
        return l;
    };
    int res = 0;
    //等于的情况
    int k = ages.size()-1;
    for(int i = ages.size() - 1; i>=0; --i){
        double tar = 0.5 * ages[i] + 7;//找大于这个值的最小值
        res += (i - f(tar)) > 0 ? i - f(tar) : 0;
        if(ages[i] == ages[k]){
            if(ages[i] > 14)res+= k - i;
        }else k = i;
    }
    return res;
}
int main(){
    vector<int> n ={108,115,5,24,82};
    numFriendRequests(n);
}
