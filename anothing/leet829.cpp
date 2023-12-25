#include<vector>
#include<set>
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
// #include"TreeNode.h"
using namespace std;
int consecutiveNumbersSum(int n) {
    int i = 1, k = 1;
    int res = 0;
    while(i <= n){
        if((n - i) % k == 0)res++;
        k++;
        i += k;
    }
    return res;
}
int main(){
    int n = 15;
    consecutiveNumbersSum(9);
}