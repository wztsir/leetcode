    #include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cmath>
#include <numeric>  // 为了使用std::accumulate()函数 
#include"TreeNode.h"
using namespace std;
    string maximumOddBinaryNumber(string s) {
        int num = 0, size = s.size();
        for(auto& it : s){
            if(it == '1')num++;
        }
        string res;
        for(int i = 0; i<num-1; ++i){
            res.push_back('1');
        }
        for(int i = 0; i<size-num;++i){
            res.push_back('0');
        }
        res.push_back('1');
        return res;
        
    }
    int main(){
        maximumOddBinaryNumber("010");
    }