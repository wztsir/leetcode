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
//如果要用index然后不断转圈，针对最后可能存在的单行或者单列，上必须左闭右闭， 右必须上闭下闭，
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    vector<int> res;
    int index = 0;
    //将区间改为左闭右闭，同时反添加多行
    while(index < (row+1)/2 && index < (col+1)/2){
        for(int i = index; i <= col - index - 1; i++){
            res.push_back(matrix[index][i]);
        }
        for(int j = index+1; j <= row - index -1; j++){
            res.push_back(matrix[j][col - index - 1]);
        }
        if(index < row - index - 1){
            for(int i = col - index - 2; i >= index; --i){
                res.push_back(matrix[row-index-1][i]);
            }
        }
        if(index < col - index -1){
        for(int j = row - index -2; j > index; j--){
            res.push_back(matrix[j][index]);
        }
        }
        index++;
    }
    return res;
}