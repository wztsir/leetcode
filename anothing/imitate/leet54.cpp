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
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int index = 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;
    while(index * 2 < m && index * 2 < n){
        for(int j = index; j <= n - 1 - index; j++){
            ans.push_back(matrix[index][j]);
        }
        for(int i = index+1; i <= m -2 - index; i++){
            ans.push_back(matrix[i][n-1-index]);
        }
        if(index >= m-1-index)break;
        for(int j = n-1-index; j >= index; j--){
            ans.push_back(matrix[m-1-index][j]);
        }
        if(n-1-index <= index)break;
        for(int i = m -2 - index;i >= index + 1; i--){
            ans.push_back(matrix[i][index]);
        }
        index++;
    }
    return ans;
}
int main()
{
    vector<vector<int>> m = {{7}, {9}, {6}};
    spiralOrder(m);
   system("pause");
   return 0;
}
