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
string toLowerCase(string s) {
    //"Hello"
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] >= 'A' && s[i] <= 'Z')s[i] += 32;
    }
    return s;
}
int main()
{
   system("pause");
   return 0;
}
