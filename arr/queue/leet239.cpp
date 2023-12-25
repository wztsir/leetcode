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
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {//队列中放下标，而不是数据，因为如果放数据，不知道要不要出队列
    deque<int> q;
    for(int i = 0; i < k; ++i){
        while(!q.empty() && nums[q.back()] <= nums[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    vector<int> res;
    res.push_back(nums[q.front()]);
    for(int i = k; i < nums.size(); ++i){
        while(!q.empty() && nums[q.back()] <= nums[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(q.front() < i-k){
            q.pop_front();
        }
        res.push_back(nums[q.front()]);
    }
    return res;
}
int main(){
    vector<int> test = {-7,-8,7,5,7,1,6,0};
    maxSlidingWindow(test, 4);
}
