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

bool isValidSerialization(string preorder) {
    int diff = 1;
    int i = 0, n = preorder.size();
    while(i < n){
        if(preorder[i] == ','){
            i++;
            continue;
        }
        diff--;
        if(diff < 0)return false;
        
        if(preorder[i] != '#')diff += 2;
        while(i < n && preorder[i] != ',')i++;
        i++;
    }
    return diff == 0;
}
int main()
{
    isValidSerialization("9,#,92,#,#");
   system("pause");
   return 0;
}
