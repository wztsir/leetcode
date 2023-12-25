#include<vector>
#include<queue>
using namespace std;
//设计数据结构统计入度与出度
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> du(numCourses);
    vector<vector<int>> map(numCourses);
    vector<int> res;
    queue<int> q;
    for(auto& it : prerequisites){
        du[it[0]]++;
        map[it[1]].push_back(it[0]);
    }
    for(int i = 0; i < numCourses; ++i){
        if(du[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for(auto& it : map[cur]){
            du[it]--;
            if(du[it] == 0)q.push(it);
        }
    }
    return res.size() == numCourses ? res : vector<int>();
}