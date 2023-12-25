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
#include <numeric>  // 为了使用std::accumulate()函数 
#include<sstream>
#include<functional>
// #include"TreeNode.h"
using namespace std;
vector<string> getFolderNames(vector<string>& names) {
    unordered_map<string, int> folder;
    int n = names.size();
    vector<string> ans(n);
    for(int i = 0; i<n; ++i){
        string temp = names[i];
        int k = 0;
        if(folder.count(temp)) k = folder[temp];
        while(folder.count(temp)){
            temp =  names[i] +"(" + to_string(++k) + ")";
        }
        folder[names[i]] = k;
        folder[temp] = 0;
        ans[i] = temp;
    }
    return ans;
}