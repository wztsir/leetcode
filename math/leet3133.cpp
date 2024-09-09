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
long long minEnd(int n, int x) {// n是待添加的数据， x是已有的数据
    int index = 0;//num(n-1)记录当前添加的位的位置
    long long ans = x;
    n--;
    while(n){
        if((x & 1) == 0){// 说明存在空位，可以放数据
            if((n & 1) == 1){
                ans += pow(2, index);
            }
            n >>= 1;
        }
        x >>= 1;
        index++;
    }
    return ans;
}
int main()
{
    minEnd(3, 2);
   system("pause");
   return 0;
}
