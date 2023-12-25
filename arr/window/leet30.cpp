#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//滑动窗口：什么情况下要想到这个方法，设计到字符串的比对，甚至不局限于字符串的比对，在长的那个上面移动
// unordered_set<string> temp;
// void dfs(vector<string>& words, vector<int>& used, string& s){
//     int n = words[0].size();
//     if(s.size() == words.size() * n){
//         temp.insert(s);
//     }
    
//     for(int i = 0; i <words.size(); ++i){
//         if(used[i])continue;
//         used[i] = 1;
//         s.append(words[i]);
//         dfs(words, used, s);
//         used[i] = 0;
//         s.erase(s.length() - n, n);
//     }
// }
// vector<int> findSubstring(string s, vector<string>& words) {
//     string t = "";
//     vector<int> used(words.size());
//     vector<int> res;
//     dfs(words, used, t);
//     for(auto it : temp){
//         size_t pos = 0;
//         while((pos = s.find(it, pos)) != string :: npos){
//             res.push_back(pos);
//             pos += it.size();
//         }
//     }
//     return res;
// }

// vector<int> findSubstring(string s, vector<string>& words) {
//     vector<int> res;
//     int n = s.size();
//     int numWords = words.size();
//     if (n == 0 || numWords == 0) {
//         return res;
//     }
//     unordered_map<string, int> mat;
//     for(auto& it : words){
//         mat[it]++;
//     }
//     int length = words[0].size();
//     int l = 0;
//     while(l + numWords * length <= n){
//         unordered_map<string, int> ma(mat);
//         for(int i = l; i <= l + (numWords-1) * length; i += length){
//             string temp = s.substr(i, length);
//             if(ma.find(temp) == ma.end() || ma[temp] == 0)break;
//             ma[temp]--;
//             if(i == l + (numWords-1) * length)res.push_back(l);
//         }
//         l++;
//     }
//     return res;
// }

//滑动窗口就是只允许滑动一次
//这道题目特殊：设置初始节点【0. wordLen）,再滑动即可

vector<int> findSubstring(string s, vector<string>& words) {
    int sl = s.size(), num = words.size(), wl = words[0].size();
    vector<int> res;
    unordered_map<string, int> dif;
    for(auto it : words){
        dif[it]--;
    }
    for(int i = 0; i < wl; ++i){
        if(i + num * wl > sl)break;
        unordered_map<string, int> diff(dif);
        int l = i, r = i;
        while(r < sl){
            //右进入
            string t = s.substr(r, wl);
            r += wl;
            diff[t]++;
            if(diff[t] == 0)diff.erase(t);
            if(diff.empty())res.push_back(l);
            //左出
            if(r - l >= num * wl){
                string t = s.substr(l, wl);
                l += wl;
                diff[t]--;
                if(diff[t] == 0)diff.erase(t);
            }

        }
    }
    return res;
}
int main(){
    
}