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
int sumOfTheDigitsOfHarshadNumber(int x) {
    int res = 0, temp = x;
    while(temp > 0){
        res = res + temp % 10;
        temp /= 10;
    }
    if(x % res == 0)return res;
    else return -1;
}
int main()
{
    sumOfTheDigitsOfHarshadNumber(23);
}
