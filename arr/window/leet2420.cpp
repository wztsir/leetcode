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
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
// #include"TreeNode.h"
using namespace std;
// void clear(queue<int> & q){
//     queue<int> empty;
//     swap(empty)
// }
vector<int> goodIndices(vector<int>& nums, int k) {
    deque<int> prefix;
    deque<int> postfix;
    int n = nums.size();
    vector<int> ans;
    if(2 *k == n)return {};
    int i = 0;
    for(; i<k; i++){
        if(!prefix.empty() && prefix.back() < nums[i]){
            prefix.clear();
        }
        prefix.push_back(nums[i]);
    }
    i++;
    for(i; i<=2*k; i++){
        if(!postfix.empty() && postfix.back() > nums[i]){
            postfix.clear();
        }
        postfix.push_back(nums[i]);
    }
    if(prefix.size() == k && postfix.size() == k)ans.push_back(k);
    for(int i = k+1; i<n-k; i++){
        if(prefix.back() < nums[i-1]){
            prefix.clear();
        }else if(prefix.size() == k)prefix.pop_front();
        prefix.push_back(nums[i-1]);

        if(postfix.back() > nums[i+k]){
            postfix.clear();
        }else if(postfix.size() == k)postfix.pop_front();
        postfix.push_back(nums[i+k]);
        if(prefix.size() == k && postfix.size() == k)ans.push_back(i);
    }

    return ans;
}
int main(){
    vector<int> v ={1253747,459932,263592,354832,60715,408350,959296};
    int k = 2;
    goodIndices(v, k);
}