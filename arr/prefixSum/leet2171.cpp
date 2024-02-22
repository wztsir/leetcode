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
long long minimumRemoval(vector<int>& beans) {
    int size = beans.size();
    sort(beans.begin(), beans.end());
    vector<long long> preSum(size+1, 0);
    long long total = 0;
    for(int i = 1; i <= size; i++){
        preSum[i] = preSum[i-1] + beans[i-1];
    }
    total = preSum[size];
    long long res = total - (long long)beans[0] * size;
    for(int i = 1; i < size; i++){
        long long temp = 0;
        temp += (total-(long long)beans[i] * (size - i));
        res = min(res, temp);
    }
    return res;
}
int main()
{
   vector<int> a = {4,1,6,5};
   minimumRemoval(a);
   return 0;
}
