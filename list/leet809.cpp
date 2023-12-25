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
#include<sstream>
// #include"TreeNode.h"
using namespace std;
int expressiveWords(string s, vector<string>& words) {
    int sl = s.size();
    int res = 0;
    for(auto & word : words){
        int wi = 0, wl = word.size();
        int si = 0;
        while(wi < wl && si < sl){
            if(s[si] != word[wi])break;
            int st = 1, wt = 1;
            while(si + 1 < sl && s[si] == s[si + 1]){
                si++;
                st++;
            }
            while(wi + 1 < wl && word[wi] == word[wi + 1]){
                wi++;
                wt++;
            }
            if(wt > st || (wt < st && st < 3))break;
            si++,wi++;
        }
        if(si == sl && wi == wl)res++;
    }
    return res;
}