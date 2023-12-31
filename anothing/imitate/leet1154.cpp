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
int dayOfYear(string date) {
    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));
    int ans = 0;
    vector<int> dayofMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int i = 1; i < month; i++){
        ans += dayofMonth[i-1];
        if((i == 2) && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))ans++;
    }
    ans += day;
    return ans;
}
int main()
{
   system("pause");
   return 0;
}
