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
long long maxKelements(vector<int>& nums, int k) {
    long long res = 0;
    multiset<int, greater<int>> s;
    for(auto& n : nums){
        s.insert(n);
    }
    for(int i = 0; i < k; ++i){
        int temp = *s.begin();
        res += temp;
        temp  = ceil(temp /3.0);
        s.erase(s.begin());
        s.insert(temp);
    }
    return res;
}
int main(){
    vector<int> n = {1,10,3,3,3};
    int k = 5;
    maxKelements(n, k);
}