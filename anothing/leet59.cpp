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
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n));
    int k = 1;
    int index = 0;
    int loop = n/2;
    while(loop--){
        for(int i = index; i < n - 1 - index; i++){
            res[index][i] = k++;
        }
        for(int j = index; j < n - 1 - index; j++){
            res[j][n- 1 - index] = k++;
        }
        for(int i = n-1-index; i > index; i--){
            res[n-1-index][i] = k++;
        }
        for(int j = n-1-index; j > index; j--){
            res[j][index] = k++;
        }
        index++;
    }
    if(n%2)res[index][index] = k;
    return res;
}
int main(){
    int n = 3;
    generateMatrix(n);
}