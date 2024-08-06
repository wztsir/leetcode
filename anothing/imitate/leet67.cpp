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
string addBinary(string a, string b) {
    int add = 18;
    
    pow()
    string ans;
    stack<int> s;
    while(add){
        int mod = add % 2;
        s.push(mod);
        add /= 2;
    }
    while(!s.empty()){
        int temp = s.top();// 拿到栈顶
        s.pop();// 删除栈顶
        ans += to_string(temp);
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
