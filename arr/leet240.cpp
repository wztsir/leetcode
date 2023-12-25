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
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int x = m-1, y = 0;
    while(x >= 0 && y < n){
        if(matrix[x][y] == target)return true;
        else if(matrix[x][y] > target)x--;
        else y++;
    }
    return false;
}