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
vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    if(tomatoSlices > cheeseSlices * 4 || tomatoSlices < cheeseSlices * 2 || tomatoSlices % 2 ==1)return {};
    int a = (tomatoSlices - cheeseSlices*2)/2;
    int b = cheeseSlices - a;
    return {a,b};
}
int main()
{
   system("pause");
   return 0;
}
