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
#include<sstream>
using namespace std;
string capitalizeTitle(string title) {
    istringstream iss(title);
    string s, ans;
    while(iss >> s){
        
        if(s.length() > 2){
            ans += toupper(s[0]);
            s = s.substr(1);
        }
        for(auto &c : s){
            ans += tolower(c);
        }
        if(!ans.empty())ans+= " ";
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
