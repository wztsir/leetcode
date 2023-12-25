#include<vector>
#include<unordered_set>
using namespace std;
int firstMissingPositive(vector<int>& nums) {
    unordered_set<int> q;
    for(auto& it : nums){
        q.insert(it);
    }
    int res = 1;
    while(true){
        if(q.count(res))res++;
        else return res;
    }
}