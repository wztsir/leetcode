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
#include<numeric> // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
using namespace std;



int maximumRows(vector<vector<int>>& matrix, int numSelect) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> map(m);
    for(int i = 0; i < m; i++){
        int temp = 0;
        for(int j = 0; j < n; j++){
            if(matrix[i][j])temp |= (1 << j);
        }
        map[i] = temp;
    }
    int res = 0;
    for(int s = 0; s < (1 << n); s++){
        if(__builtin_popcount(s) == numSelect){
            int temp = 0;
            for(int i = 0; i < m; i++){
                if((map[i] & s) == map[i])temp++;
            }
            res = max(res, temp);
        }
    }
    return res;
    
}
int main(){
    vector<vector<int>> m = {{1},{0}};
    int n = 1;
    maximumRows(m, n);
}