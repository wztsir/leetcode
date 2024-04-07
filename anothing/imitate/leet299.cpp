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
string getHint(string secret, string guess) {
   unordered_map<char, int> m1, m2;
   int same = 0, ans = 0;
   for(int i = 0; i < secret.size(); i++){
      m1[secret[i]]++;
      m2[guess[i]]++;
      if(secret[i] == guess[i]) same++;
   }
   for(auto& it : m1){
      ans += min(it.second,  m2[it.first]);
   }
    return to_string(same) + 'A' + to_string(ans - same) + "B";
}
int main()
{
   system("pause");
   return 0;
}
