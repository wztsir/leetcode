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
//最基本的思路，要将两个人的，目标统一
//A为alice得到数总和，B为Bob得到数总和
//即alice要最大化 A-B， Bob 最小化A-B
// 即alice与Bob 每次都拿  A+B最大的数


//换一种思考方式：
// 问：有没有其它的思考方式？

// 答：也可以这样思考：对比两颗石子
//  (a[i],b[i])(a[i],b[i])(a[i],b[i]) 和 (a[j],b[j])(a[j],b[j])(a[j],b[j])。
//  如果 Alice 选 iii，Bob 选 jjj，那么 A−B=a[i]−b[j]A-B=a[i]-b[j]A−B=a[i]−b[j]；
//  如果 Alice 选 jjj，Bob 选 iii，那么 A−B=a[j]−b[i]A-B=a[j]-b[i]A−B=a[j]−b[i]。
//  如果 Alice 选 iii 更优，则有 a[i]−b[j]>a[j]−b[i];a[i]-b[j] > a[j]-b[i]a[i]−b[j]>a[j]−b[i]，
//  即 a[i]+b[i]>a[j]+b[j]a[i]+b[i] > a[j]+b[j]a[i]+b[i]>a[j]+b[j]，
//  说明 Alice 应当优先选 a[i]+b[i]a[i]+b[i]a[i]+b[i] 更大的石子。


int stoneGameVI(vector<int>& a, vector<int>& b) {
    int n = a.size();
    vector<int> temp(n);
    iota(temp.begin(), temp.end(), 0);     
    sort(temp.begin(), temp.end(), [&](int i, int j){
        return a[i] + b[i] > a[j] + b[j];
    });
    int diff = 0;
    for(int i = 0; i < n; i++){
        diff += i % 2 == 0 ? a[temp[i]] : -b[temp[i]];
    }
    return (diff > 0) - (diff < 0);
}
int main()
{
   system("pause");
   return 0;
}
