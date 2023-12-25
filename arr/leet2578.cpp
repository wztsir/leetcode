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
int splitNum(int num) {
    vector<int> arr;
    while(num!=0){
        int t  = num % 10;
        num /= 10;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    int a = 0, b = 0;
    for(int i = 0; i < arr.size(); i+=2){
        a = a*10 + arr[i];
        if(i+1 < arr.size())b = b*10 + arr[i+1];
    }
    return a+b;
}