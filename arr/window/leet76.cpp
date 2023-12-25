#include<string>
#include<unordered_map>
using namespace std;
//同30题，滑动窗口
string minWindow(string s, string t) {
    int sl = s.size(), tl = t.size();
    if(sl == 0 || tl == 0)return "";
    int left = 0, right = 0;
    unordered_map<char, int> need, window;
    for(auto it : t){
        need[it]++;
    }
    int valid = 0, start = 0, len = INT_MAX;
    while(right < sl){
        char c = s[right];
        right++;
        if(need.count(c)){
            window[c]++;
            if(window[c] == need[c])valid++;
        }
        while(valid == need.size()){
            if(right - left < len){
                start = left;
                len = right - left;
            }
            c = s[left];
            left++;        
            if(need.count(c)){
                // window[c]--;
                // if(window[c] == need[c])valid--;细节，增加判断是否同，与减少是否判断同，是两种顺序
                if(window[c] == need[c])valid--;
                window[c]--;
            }
            
        }
        
    }
    return len == INT_MAX ? "" : s.substr(start, len);

}