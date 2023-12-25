#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
//需求一：统计两个数组的交集
//需求二：两个数组的最小值进行组合
int minNumber(vector<int>& nums1, vector<int>& nums2) {
    int res = 0;
    vector<int> arr1(10);
    vector<int> arr2(10);
    for(auto& it : nums1){
        arr1[it] = 1;
    }
    for(auto& it : nums2){
        arr2[it] = 1;
    }
    int l = 0, r = 0;
    for(int i = 1; i <= 9; ++i){
        if(arr1[i] && l == 0)l = i;
        if(arr2[i] && r == 0)r = i;
        if(arr1[i] && arr2[i])return i;
    }
    res += min(l, r);
    res *= 10;
    res += max(l, r);
    return res;
}

//更加优美的代码
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        auto same = [&](){
            unordered_set<int> s(nums1.begin(), nums1.end());
            int x = 10;
            for (int num: nums2) {
                if (s.count(num)) {
                    x = min(x, num);
                }
            }
            return x == 10 ? -1 : x;
        };

        if (int x = same(); x != -1) {
            return x;
        }
        
        int x = *min_element(nums1.begin(), nums1.end());
        int y = *min_element(nums2.begin(), nums2.end());
        return min(x * 10 + y, y * 10 + x);
    }
};
