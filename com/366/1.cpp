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
int differenceOfSums(int n, int m) {
    int t = 0;
    for(int i = 0; i * m <= n; i++){
        t += (i*m);
    }
    return (n+1)*n - t*2;
}