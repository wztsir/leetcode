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
bool canChange(string start, string target) {
    int s = 0, t = 0;
    int n = start.size();
    string st = start, ta = target;
    st.erase(remove(st.begin(), st.end(), '_'), st.end());
    ta.erase(remove(ta.begin(), ta.end(), '_'), ta.end());


}
