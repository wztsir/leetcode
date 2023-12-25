#include<vector>
#include<queue>
using namespace std;
vector<bool> checkIfPrerequisite_false(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<int> ma(numCourses);
    vector<bool> res;
    int t = 0;
    vector<int> du(numCourses);
    vector<vector<int>> map(numCourses);
    queue<int> q;
    for(auto& it : prerequisites){
        int from = it[0], to = it[1];
        du[to]++;
        map[from].push_back(to);
    }
    for(int i = 0; i < numCourses; ++i){
        if(du[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; ++i){
            int cur = q.front();
            q.pop();
            ma[cur] = t;
            for(auto& it : map[cur]){
                du[it]--;
                if(du[it] == 0)q.push(it);
            }
        }
        t++;
    }
    for(auto& it : queries){
        int from = it[0], to = it[1];
        if(ma[from] < ma[to])res.push_back(true);
        else res.push_back(false);
    }
    return res;
}
//写出了广度优先与拓扑排序，但是没有想到合适的数据结构，能够实现: 入队的顺序根本不靠谱，有时候先后入队，但是并没有直接的联系
//先决条件也可以是 间接 的。如果课程 a 是课程 b 的先决条件，课程 b 是课程 c 的先决条件
//设计数据结构，记录当前节点所有的先节点，出队的时候，取出队列队首元素，同时，将这个节点及其所有前置条件节点设置为所有后续节点的前置条件节点，然后对每一个后续节点入度进行 −1-1−1 操作，若操作后的节点入度为 000，则继续将该节点加入队列。

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<bool> res;
    vector<int> du(numCourses);
    vector<vector<int>> map(numCourses);
    vector<vector<bool>> ispre(numCourses, vector<bool>(numCourses, false));
    queue<int> q;
    for(auto& it : prerequisites){
        int from = it[0], to = it[1];
        du[to]++;
        map[from].push_back(to);
    }
    for(int i = 0; i < numCourses; ++i){
        if(du[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto& it : map[cur]){
            ispre[cur][it] = true;
            for(int i = 0; i < numCourses; ++i){
                ispre[i][it] = ispre[i][cur] | ispre[i][it];
            }
            du[it]--;
            if(du[it] == 0)q.push(it);
        }
    }
    for(auto& it : queries){
        int from = it[0], to = it[1];
        if(ispre[from][to])res.push_back(true);
        else res.push_back(false);
    }
   return res;
}