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
int buyChoco(vector<int>& prices, int money) {
    int fi = INT_MAX, se = INT_MAX;
    for(auto& p : prices){
        if(p <= fi){
            se = fi;
            fi = p;
        }else if(p < se){
            se = p;
        }
    }
    return money - (fi + se) < 0 ? money : money - (fi + se);
}
int main()
{
    vector<int> p = {1,2,2};
    buyChoco(p, 3);
   system("pause");
   return 0;
}
