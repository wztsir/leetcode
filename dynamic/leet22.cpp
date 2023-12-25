#include<string>
#include<vector>
using namespace std;
vector<string> res;
int length = 0;
void dps(string& str, int l1, int l2){
    if(str.size() == 2 * length){res.push_back(str);return ;}
        if (l1 != length) {
        str.push_back('(');
        dps(str, l1 + 1, l2);
        str.pop_back(); // 回溯，移除添加的字符
    }

    if (l1 - l2 > 0) {
        str.push_back(')');
        dps(str, l1, l2 + 1);
        str.pop_back(); // 回溯，移除添加的字符
    }
}
vector<string> generateParenthesis(int n) {
    string str = "";
    length = n;
    dps(str, 0, 0);
    return res;
}
// int main(){ 
//     string s = "wzt";
//     vector<string> res;
//     res.push_back(s);
//     s += "sk";
//     // generateParenthesis(3);

// }
