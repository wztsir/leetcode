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
vector<int> canSeePersonsCount(vector<int>& heights) {
    int size = heights.size();
    stack<int> s;
    vector<int> ans(size);
    for(int i = size-1; i >= 0; i--){
        int res = 0;
        while(!s.empty() && s.top() < heights[i]){
            s.pop();
            res++;
        }
        if(!s.empty())res++;
        ans[i] = res;
        s.push(heights[i]);
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
