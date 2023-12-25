#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.begin(), tasks.end(),[](int a, int b){
        return a>b;
    });
    int res = 0;
    for(int i = 0; i<processorTime.size();i++){
        res = max(res, processorTime[i] + tasks[i*4]);
    }
    return res;
}