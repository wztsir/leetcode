//规则或算法：
//1.存数字时考看栈中前一个字符，+ - 则出
//2.+ - ( 直接存放
//3.对于 - 一元运算的考虑 
// #include<string>
// #include<stack>
// using namespace std;
// int calculate(string s) {
//     stack<char> t;
//     stack<int> out;
//     int res = 0;
//     for(int i = 0; i < s.size(); ++i){
//         char c = s[i];
//         if(c == ' ')continue;
//         else if(c == '(' || c == '+'|| c == '-')t.push(c);
//         else if(c <= '9' && c >= '0'){
//             if(t.top() == '-' || t.top() == '+'){
//                 char ca = t.top();
//                 t.pop();
//                 if(ca == '+' && t.pop)
//             }
//         }

//     }
    
    
// }

// 注意：cpp 代码由 chatGPT🤖 根据我的 python 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 python 代码对比查看。

#include <string>
#include <deque>
#include <algorithm>
#include<vector>
#include <numeric>

using namespace std;
static int helper(deque<char> &s){
        vector<int> stack;
        char sign = '+';
        int num = 0;

        while (!s.empty()) {
            char c = s.front();
            s.pop_front();
            if (isdigit(c)) {
                num = 10 * num + (c - '0');
            }
            // 遇到左括号开始递归计算 num
            if (c == '(') {
                num = helper(s);
            }

            if ((!isdigit(c) && c != ' ') || s.empty()) {
                if (sign == '+') {
                    stack.push_back(num);
                } else if (sign == '-') {
                    stack.push_back(-num);
                }
                num = 0;
                sign = c;
            }
            // 遇到右括号返回递归结果
            if (c == ')') {
                break;
            }
        }
        return accumulate(stack.begin(), stack.end(), 0);
    };
int calculate(string s) {

    // Define helper function


    deque<char> deque_s(s.begin(), s.end());
    return helper(deque_s);
}
