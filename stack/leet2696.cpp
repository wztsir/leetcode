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
//消消乐的都可以用栈来模拟
int minLength(string s) {
    stack<char> t;
    
    for(int i = 0; i < s.size(); i++){
        int k = 0;
        if(!t.empty()){
            if(s[i] == 'B'&& t.top() == 'A'){
                k=1;
                t.pop();
            }else if(s[i] == 'D'&& t.top() == 'C'){
                k=1;
                t.pop();
            }
        }
        if(!k)t.push(s[i]);
    }
    return t.size();
}
//更简洁的代码：
class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char c: s) {
            if (!st.empty() && (c == 'B' && st.top() == 'A' || c == 'D' && st.top() == 'C'))
                st.pop();
            else
                st.push(c);
        }
        return st.size();
    }
};


