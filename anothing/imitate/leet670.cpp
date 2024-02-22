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
int maximumSwap(int num) {
    string temp = to_string(num);
    int size = temp.size();
    int res = num;
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            swap(temp[i], temp[j]);
            res = max(res, stoi(temp));
            swap(temp[i], temp[j]);
        }
    }
    return res;
}
int main()
{
   system("pause");
   return 0;
}
