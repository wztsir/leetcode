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
int lengthOfLongestSubstring(string s) {
    int m = s.size();
    int r = 0, l = 0;
    int res = 0;
    unordered_map<int, int> window;
    //区间搞错了
    while(r < m){//对于window而言是[left, right) r可以取到m, 但是从20后取到m没问题，19行不能取到m
        window[s[r]]++;
        r++;
        while(window[s[r-1]] == 2){
            window[s[l]]--;
            l++;
        }
        res = max(res, r-l);
    }
    return res;
}
int main(){
    string s = "bbbbb";
    lengthOfLongestSubstring(s);
}