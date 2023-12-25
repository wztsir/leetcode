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
#include<sstream>
#include"TreeNode.h"
using namespace std;
int sumOfMultiples(int n) {
    int res = 0;
    for(int i = 1; i<= n; i++){
        if(i % 3 == 0 || i%5 == 0 || i % 7 == 0)res += i;
    }
    return res;
}