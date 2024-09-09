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
int power2(int n){
    int ans = 1;
    for(int i = 0; i < n; i++){
        ans *= 2;
    }
    return ans;
}
int power(int n){
    if(n == 1)return 2;
    int ans = 2;
    ans *= power(n-1);
    return ans;
}
double getMoney(double begin, double up, int inter){
    for(int i = 0; i < inter; i++){
        begin *= (1+up);
    }
    return begin;
}
int main()
{
    getMoney(3000, 0.07, 20);
   system("pause");
   return 0;
}
