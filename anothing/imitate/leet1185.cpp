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
string dayOfTheWeek(int day, int month, int year) {
    int ans = 4;
    vector<string> res = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<int> dayofMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for(int y = 1971; y < year; y++){
        if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)ans += 366;
        else ans += 365;
    }
    for(int i = 1; i < month; i++){
        ans += dayofMonth[i - 1];
        if (i == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) ans++;
    }
    ans += day;
    return res[ans % 7];
}
int main()
{
   system("pause");
   return 0;
}
