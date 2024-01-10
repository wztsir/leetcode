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
// f[-1] = 0;
// f[i] = f[i-1]
// f[i] = min(f[j-1]) 前提是【j,i】在dict中

// 改成递推，全部右移
// f[0] = 0;
// f[i+1] = f[i]
// f[i+1] = min(f[j]) 前提是【j,i】在dict中

//递推右移，每个循环对应一个参数，同时不改变每个循环时参数的含义，只改变对应的
int minExtraChar(string s, vector<string>& dictionary) {
    unordered_set<string> set(dictionary.begin(), dictionary.end());
    int size = s.size();
    vector<int> f(size+1, 0);
    for(int  i = 0; i < size; i++){
        f[i+1] = f[i]+1;
        for(int j = 0; j <= i; j++){
            string sub = s.substr(j, i-j+1);
            if(set.count(sub)){
                f[i+1] = min(f[i+1], f[j]);
            }
        }
    }
    return f[size];
}
int main()
{
   system("pause");
   return 0;
}
