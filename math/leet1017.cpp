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
string baseNeg2(int n) {
    string ans;
    if(n == 0)return "0";
    while(n){
        int r = 0;
        if(n%2)r = 1;
        if(r) ans.push_back('1');
        else ans.push_back('0');
        n -= r;
        n /= -2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}