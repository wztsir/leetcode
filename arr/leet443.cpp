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
int compress(vector<char>& chars) {
    int n = chars.size();
    if(n == 1)return 1;
    char c = chars[0];
    int num = 1;  // 统计当前字符出现的次数
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(i == n || chars[i] != c){
            chars[ans] = c;
            if(num != 1){
                // stack<int> s;
                // while(num){
                //     s.push(num % 10);
                //     num /= 10;
                // }
                // while(!s.empty()){
                //     int temp = s.top();
                //     s.pop();
                //     ans++;
                //     chars[ans] = temp + '0';
                // }
                string temp = to_string(num);
                for(char& t : temp){
                    chars[ans++] = t;
                }
            }
            ans++;
            if(i != n)c = chars[i];
            num = 1;
        }
        else{
            num++;
        }
    }
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
