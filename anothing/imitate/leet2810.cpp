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
// string finalString(string s) {
//     string res;
//     for(auto c : s){
//         if(c == 'i')reverse(res.begin(), res.end());
//         else res += c;
//     }
//     return res;
// }
string finalString(string s) {
    deque<char> q;
    bool tail = true;
    for(auto& c : s){
        if(c == 'i'){
            tail = !tail; 
            continue;
        }
        if(tail)q.push_back(c);
        else q.push_front(c);
    }
    string res = tail ? string(q.begin(), q.end()) : string(q.rbegin(), q.rend());
    return res;
}
int main()
{
   system("pause");
   return 0;
}
