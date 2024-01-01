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

int largestRectangleArea(vector<int>& heights) {
    int size = heights.size();
    stack<int> s;
    vector<int> right_min(size, size);
    vector<int> left_min(size, -1);
    for(int i = size - 1; i >= 0; i--){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }
        if(!s.empty()) right_min[i] = s.top();
        s.push(i);
    }
    stack<int> s2;
    for(int i = 0; i < size; i++){
        while(!s2.empty() && heights[s2.top()] >= heights[i]){
            s2.pop();
        }
        if(!s2.empty())left_min[i] = s2.top();
        s2.push(i);
    }
    int res = 0;
    for(int i = 0; i < size; i++){
        res = max(res, (right_min[i] - left_min[i] -1) * heights[i]);
    }
    return res;
}
int main(){
    vector<int> s= {9,0};
    largestRectangleArea(s);
}