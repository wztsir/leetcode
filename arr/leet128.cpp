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
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;
    for(auto& num : nums){
        set.insert(num);
    }
    int res = 0;
    for(auto& s : set){
        if(set.count(s-1))continue;
        int temp = 0;
        int begin = s;
        while(set.count(begin++)){
            temp++;
        }
        res = max(res, temp);
    }
    return res;
}
int main()
{
   system("pause");
   return 0;
}
