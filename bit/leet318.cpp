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

int maxProduct2(vector<string>& words) {
    vector<int> hash;
    int n = words.size();
    for(auto& word : words){
        int h = 0;
        for(auto& c : word){
            h = h | 1 << (c-'a');
        }
        hash.push_back(h);
    }
    int ans = 0;
    for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            if((hash[i] & hash[j]) == 0){
                ans = max(ans, int(words[i].size() * words[j].size()));
            }
        }
    }
    return ans;
}
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> masks(length);
        for (int i = 0; i < length; i++) {
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        int maxProd = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }


int main(){
    vector<string> a ={"abcw","baz","foo","bar","xtfn","abcdef"};
    maxProduct(a);
}