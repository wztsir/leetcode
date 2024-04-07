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
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
using namespace std;

class ThroneInheritance {
private:
    unordered_map<string, vector<string>> edges;
    unordered_set<string> dead;
    string king;
public:
    ThroneInheritance(string kingName):king(kingName) {
        
    }
    
    void birth(string parentName, string childName) {
        edges[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        // lamda
        function<void(string)> dfs = [&](string node){
            if(dead.find(node) == dead.end()){
                res.push_back(node);
            }
            for(auto& child : edges[node]){
                dfs(child);
            }
        };
        dfs(king);
        return res;
    }
};