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
vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
    vector<vector<int>> graph(n, vector<int>(n));
    for(auto edge : edges){
        graph[edge[0]][edge[1]] = edge[2];
        graph[edge[1]][edge[0]] = edge[2];
    }
    


}
int main()
{
   system("pause");
   return 0;
}
