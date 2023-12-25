#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
//贪心题重点考察策略，但是一旦换一个oj就会很难
bool static cmp(vector<int>& a, vector<int>& b){
    if(a[1] == b[1])return a[0] < b[0];
    else return a[1] < b[1];
}
int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), cmp);
    int res = 0, t = 0;
    priority_queue<int>q;//存放这套方案
    for(auto& it : courses){
        int del = it[1], dul = it[0];
        if(dul + t <= del){//只考虑了要在截止期间最大，没有考虑让当前的队列市场最小
            res++;
            t += it[0];
            q.push(dul);
        }else if(!q.empty() && q.top() > dul){//之前q.top()都可以放入，之前q.top()时 del更小
            t -= q.top() - dul;
            q.pop();
            q.push(dul);
        }
    }
    return q.size();
}