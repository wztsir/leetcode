#include<vector>
#include<queue>
#include<set>
#include<unordered_set>
#include<string>
#include<iostream>
using namespace std;
//超时
//要防止走回头路
//细节的就是在判断 cur的邻接节点时候，要往s/v里放。可以减少同一次的节点数量，减枝
int openLock(vector<string>& deadends, string target) {
    unordered_set<string> s(deadends.begin(), deadends.end());
    // unordered_set<string> v;
    queue<string> q;
    q.push("0000");
    if(s.count("0000"))return -1;
    s.insert("0000");
    int d = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
            string cur = q.front();
            q.pop();
            if(target == cur)return d;
            for(int j = 0; j < 4; ++j){
                string nxt(cur), ad(cur);
                if(nxt[j] == '0')nxt[j] = '9';
                else nxt[j] -= 1;
                if(s.count(nxt)==0){
                    q.push(nxt);
                    s.insert(nxt);
                }

                if(ad[j] == '9')ad[j] = '0';
                else ad[j] += 1;                
                if(s.count(ad)==0){
                    q.push(ad);
                    s.insert(ad);
                }
                if(nxt == target || ad == target)return d+1;
            }
        }
        d++;
    }
    return -1;
}
int main(){
    vector<string> q = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    cout << openLock(q,"0009");
}