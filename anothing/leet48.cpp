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

using namespace std;
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n; j++){
            int temp = matrix[j][i];
            matrix[j][i] = matrix[j][n-i-1];
            matrix[j][n-i-1] = temp;
        }
    }
}  