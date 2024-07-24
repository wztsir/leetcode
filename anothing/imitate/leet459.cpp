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
bool repeatedSubstringPattern(string s) {
    int n = s.size();
    // n / 2 -> 整型
    // n / 2 * 1.0 -> double
    bool flag = true;

    for(int i = 1; i <= n/2; i++){// 子串长度
        if(n % i != 0)continue;
        flag = true;
        for(int j = 0; j < i; j++){// 初始子串的小标
            // j=0  0+0*i  0+i  0+2i ... 0+v_0*i < n  => j+v*i
            // j=1  1+0*i  1+i  1+2i ... 1+v_1*i < n
            //                    {i, 2i, 3i,..., M} j+M<n
           //=> s[j] s[j+v*i] v={0, 1, 2, ...M}  j + M*i < n
            for(int v = 0; j + v < n; v+= i){
                if(s[j] != s[j+v]){
                    flag = false;
                    break;
                }
            }
            if(!flag)break;
        }
        
        if(flag)return true;
    }
    return false;
}
int main(){
    repeatedSubstringPattern("abab");
   system("pause");
   return 0;
}
