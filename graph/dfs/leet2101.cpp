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
int maximumDetonation(vector<vector<int>>& moves) {(1~9, 2)
    vector<vector<char>> arr(3, vector<char>(3));
    for(int i = 0; i < moves.size(); i++){
        int r = moves[i][0], l = moves[i][1];
        if(i % 2 == 0){
            arr[r][l] = 'X';
        }else{
            arr[r][l] = 'O';
        }
        
    }
    
    vector<int> arr2(3, 0);

    // arr[0]
}
int main()
{
   system("pause");
   return 0;
}
