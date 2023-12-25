#include<vector>
#include<queue>
using namespace std;
//设计数据结构统计入度与出度
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> du(numCourses);
    vector<vector<int>> map(numCourses);
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
        for(auto& it : map[cur]){
            du[it]--;
            if(du[it] == 0)q.push(it);
        }
    }
    int i;
    for(i = 0; i < numCourses; ++i){
        if(du[i] != 0)break;
    }
    return i == numCourses ? true : false;
}