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
// 思考简单了，将代码元音字符全都放在一起，其实不可以
int maxVowels_wrong(string s, int k) {
    unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
    int n = s.size(), m = 0;
    vector<int> arr(n, 0);
    if(set.find(s[0]) != set.end()){
        arr[0] = 1;
        m = 1;
    }
    for(int i = 1; i < n; i++){
        if(set.find(s[i]) != set.end()){
            arr[i] = arr[i-1] + 1;
            m = max(m, arr[i]);
        }
    }
    return min(m, k);
}
//滑动窗口
int maxVowels(string s, int k) {
    queue<char> windows;
    unordered_set<char> set = {'a', 'e', 'i', 'o', 'u'};
    int m = 0, ans = 0;
    char temp;
    for(int i = 0; i < s.size(); i++){
        windows.push(s[i]);
        if(set.find(s[i]) != set.end()){
            m++;
        }
        while(windows.size() > k){
            temp = windows.front();
            windows.pop();
            if(set.find(temp) != set.end()){
                m--;
            }
        }
        ans = max(ans, m);
    }
    return min(ans, k);
}
int main()
{
   system("pause");
   return 0;
}
