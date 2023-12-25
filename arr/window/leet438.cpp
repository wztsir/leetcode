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
vector<int> findAnagrams(string s, string p) {
    unordered_map<int, int> map;
    vector<int> res;
    int n = p.size(), m = s.size();
    int k = 0;
    for(int i = 0; i < n; ++i){
        map[p[i]]++;
        if(map[p[i]] == 1)k++;
    }
    int r = 0, l = 0;
    unordered_map<int, int> window;
    int temp = 0;
    //区间搞错了
    while(r < m){
        window[s[r]]++;
        if(window[s[r]] == map[s[r]]){
            temp++;
        }
        r++;
        if(temp == k){
            while(r - l > n){
                if(window[s[l]] == map[s[l]]){
                    temp--;
                }
                window[s[l]]--;
                l++;               
            }
            if(temp == k)res.push_back(l);
        }
    }
    return res;
}
int main(){
    string s1 = "cbaebabacd";
    string s2 = "abc";
    findAnagrams(s1, s2);
}