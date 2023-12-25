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
// #include"TreeNode.h"
using namespace std;
//田忌赛马
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    sort(nums1.begin(), nums1.end());
    vector<int> idx(nums1.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){
        return nums2[i] < nums2[j];
    });
    int left = 0, right = n-1;
    vector<int> res(n);
    for(auto& x : nums1){
        res[x > nums2[idx[left]] ? idx[left++] : idx[right--]] = x;
    }
    return res;
}
int main(){
    vector<int> a = {2, 3, 4, 5};
    vector<int> b ={1, 10, 4, 11};
    advantageCount(a, b);
} 