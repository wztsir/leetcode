#include<vector>
#include<set>
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
//简单的思路就是对于i而言，查找[0,i]的最大左边， [i, n-1]的最大右边, 记住是包括i的
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> m_l(n);
    vector<int> m_r(n);
    m_l[0] = height[0];
    m_r[n-1] = height[n-1];
    for(int i = 1; i < n; ++i){
        m_l[i] = max(m_l[i-1], height[i]);
    }
    for(int i = n-2; i >= 0; --i){
        m_r[i] = max(m_r[i+1], height[i]);
    }
    int res = 0;
    for(int i = 1; i < n-1; i++){
        res += min(m_r[i], m_l[i]) - height[i];
    }
    return res;
}