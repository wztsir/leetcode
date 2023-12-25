#include<string>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;
int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> ba(bank.begin(), bank.end());
    unordered_set<string> vis;
    queue<string> q;
    q.push(startGene);
    vis.insert(startGene);
    string t = "ACGT";
    int d = 0;
    while(!q.empty()){
        int sq = q.size();
        for(int i = 0; i < sq; ++i){
            string cur = q.front();
            q.pop();
            if(cur == endGene)return d;
            for(int j = 0; j < 8; ++j){
                string temp(cur);
                for(int u = 0; u < 4; ++u){
                    if(temp[j] == t[u])continue;
                    temp[j] = t[u];
                    if(ba.count(temp) && vis.count(temp) == 0){
                        vis.insert(temp);
                        q.push(temp);
                        if(temp == endGene)return d+1;
                    }
                }
            }
        }
        d++;
    }
    return -1;
}
int main(){
   string start = "AACCGGTT", end = "AACCGGTA";
   vector<string> bank = {"AACCGGTA"};
   minMutation(start, end, bank);
}