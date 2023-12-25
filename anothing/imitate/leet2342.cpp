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
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
using namespace std;


int sum_of_bit(int num){
    int sum = 0;
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int maximumSum(vector<int>& nums) {
    unordered_map<int, priority_queue<int>> qs;
    for(auto& num : nums){
        int key = sum_of_bit(num);
        qs[key].push(num);
    }
    int ans = 0;
    for(auto& q : qs){
        if(q.second.size() >= 2){
            int t1 = q.second.top();
            q.second.pop();
            int t2 = q.second.top();
            ans = max(ans, t1 + t2);
        }
    }
    return ans;
}