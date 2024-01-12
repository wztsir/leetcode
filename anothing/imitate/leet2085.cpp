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
int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int>  m1, m2;
    for(auto& w : words1){
        m1[w]++;
    }
    for(auto& w : words2){
        m2[w]++;
    }
    int ans = 0;
    for(auto& m : m1){
        if(m.second == 1 && m2[m.first] == 1)ans++;
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
