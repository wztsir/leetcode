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
#include< functional>
using namespace std;
int lengthOfLastWord(string s) {
    // "Hello a" 
    //"  fly me   to   the moon    a"// n -1 - (n-2) -1
    int ans = 0;
    int begin = -1;
    s += " ";
    int n = s.size();
    for(int i = 0; i+1 < n; i++){
        if(s[i] == ' '){
            // i -> " "
            // begin -> " "
           // ->(begin, i)  (0,2) -> 1
            int temp = i - begin - 1;
            if(temp)ans = temp;

            begin = i;
        }
    }
    //if(s[n-1] != ' ')ans = n - begin -1;
    return ans;   
}
int main()
{
   system("pause");
   return 0;
}
