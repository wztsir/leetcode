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
vector<int> spiralOrder(vector<vector<int>>&  matrix) {
    // [[1,2,3],[3,2,1]]==2X3  vector<vector<int>> arr(2, vector<int> (3));
    // [[[2,4],[1,2],[4,3],[3,2]], [[2,4],[1,2],[4,3],[3,2]]] = 2X4X2
    int index = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans;
    while(index <= min(m, n)/2){
        //上
        for(int i = index; i < n-1 - index; i++){
            ans.push_back(matrix[index][i]);
        }
        //右
        for(int j = index; j < m-1 - index; j++){
            ans.push_back(matrix[j][n -1 - index]);
        }
        //下
        for(int i = n - 1 -index;  i > index; i--){
            ans.push_back(matrix[m - 1 -index][i]);
        }
        
        
        //左
        for(int j = m - 1 - index; j > index; j--){
            ans.push_back(matrix[j][index]);
        }
        index ++;
    }
    if( m == n && m % 2 == 1)ans.push_back(matrix[m/2][n/2]);
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{6, 9, 7}};
    spiralOrder(arr);
   system("pause");
   return 0;
}
