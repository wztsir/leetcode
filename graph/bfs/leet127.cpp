#include<string>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> ba(wordList.begin(), wordList.end());
    unordered_set<string> vis;
    queue<string> q;
    q.push(beginWord);
    vis.insert(beginWord);
    string t = "abcdefghijklmnopqrstuvwxyz";
    int d = 1;
    while(!q.empty()){
        int sq = q.size();
        for(int i = 0; i < sq; ++i){
            string cur = q.front();
            q.pop();
            if(cur == endWord)return d;
            for(int j = 0; j < cur.size(); ++j){
                string temp(cur);
                for(int u = 0; u < 26; ++u){
                    if(temp[j] == t[u])continue;
                    temp[j] = t[u];
                    if(ba.count(temp) && vis.count(temp) == 0){
                        vis.insert(temp);
                        q.push(temp);
                        if(temp == endWord)return d+1;
                    }
                }
            }
        }
        d++;
    }
    return 0;
}
int main(){
    string s = "ymain", e = "oecij";
    vector<string> v = {"ymann","yycrj","oecij","ymcnj","yzcrj","yycij","xecij","yecij","ymanj","yzcnj","ymain"};
    ladderLength(s, e, v);
}