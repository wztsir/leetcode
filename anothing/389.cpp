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
char findTheDifference(string s, string t) {
    vector<int> arr(26, 0);
    for(auto a : arr){
        
    }
    for(int i = 0; i < s.size(); i++){
        arr[s[i] - 'a'] ++;
    }
    for(int i = 0; i < t.size(); i++){
        arr[t[i] - 'a'] --;
        if(arr[t[i] - 'a'] < 0)return t[i];
    }
    return 0;
}
int main()
{
   system("pause");
   return 0;
}
