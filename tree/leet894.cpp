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
#include"TreeNode.h"
using namespace std;
vector<TreeNode*> dp[20];

auto init = [](){
    dp[1] = {new TreeNode(0)};
    for(int i = 3; i < 20; i += 2){
        for(int j = 1; j < i; j += 2){
            for(auto& left : dp[j]){
                for(auto& right : dp[i-1-j]){
                    dp[i].push_back(new TreeNode(0, left, right));
                }
            }
        }
    }
    return 0;
}();
vector<TreeNode*> allPossibleFBT(int n) {
    return n%2 == 1 ? dp[n] : dp[0];
}
int main()
{
   system("pause");
   return 0;
}
