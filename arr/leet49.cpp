#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric> // 为了使用std::accumulate()函数
#include <sstream>
#include <functional>
using namespace std;
string encode(string& input)
{
    vector<char> output(26,'0');
    for (size_t i = 0; i < input.size(); i++)
    {
        output[input[i]-'a']++;
    }
    return string(output.begin(), output.end());
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    map<string, vector<string>> mp;
    for (auto &str : strs){
        string temp = encode(str);
        mp[temp].push_back(str);
    }
    vector<vector<string>> res;
    for(auto& m : mp){
        res.push_back(m.second);
    }
    return res;
}
int main()
{
    vector<string> s ={"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(s);
    system("pause");
    return 0;
}
