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
int maxOperations(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> map;// key nums[i] , value 元素出现的次数
    int ans = 0;
    for(int i = 0;i < n; i++){
        if(map.find(k-nums[i]) != map.end() && map[k-nums[i]] >  0){
            map[k-nums[i]]--;
            ans++;
        }else
        map[nums[i]]++;
    }
    // int ans = 0;
    // for(auto& node : map){
    //     if(k-node.first == node.first){
    //         ans += node.second/2;
    //     }else{
    //         if(map.find(k-node.first) == map.end())continue;
    //         ans += min(node.second, map[k-node.first]);
    //         node.second = 0;
    //         map[k-node.first] = 0;
    //     }
        
    // }
    return ans;
}
int main()
{
    vector<int> a ={29,26,81,70,75,4,48,38,22,10,51,62,17,50,7,7,24,61,54,44,30,29,66,83,6,45,24,49,42,31,10,6,88,48,34,10,54,56,80,41,19};
   maxOperations(a, 12);
   system("paus e");
   return 0;
}
