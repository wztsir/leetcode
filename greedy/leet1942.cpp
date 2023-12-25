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

int smallestChair(vector<vector<int>>& times, int targetFriend) {
    int target_arrive = times[targetFriend][0];
    sort(times.begin(), times.end(), [&](vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    });
    int chair = 0;
    priority_queue<int, vector<int>, greater<int>> q;//存放椅子的编号,小顶堆
    multimap<int, int> left_id;//记录离开的时间与编号，离开时间可能存在重复
    for(auto& time : times){
        //分配椅子，先查看之前的椅子有多少把是空的
        int arrive = time[0], left = time[1];
        while(!left_id.empty() && left_id.begin()->first <= arrive){
            q.push(left_id.begin()->second);
            left_id.erase(left_id.begin());
        }
        int res = 0;
        if(q.empty()){//空闲椅子队列为空，分配椅子
            res = chair;
            chair++;
        }else{//空闲椅子队列非空，分配椅子
            res = q.top();
            q.pop();
        }
        if(target_arrive == arrive)return res;
        left_id.insert({left, res});
    }
    // priority_queue<pair<int, int>, vector<pair<int, int>>,> pq;//存储<离开时间，座位号
    return 0;
}