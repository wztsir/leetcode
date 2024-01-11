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
int addMinimum(string word) {
    int size = word.size();
    int ans = 1;
    for(int i = 1; i < size; i++){
        if(word[i] <= word[i-1])ans++;
    }
    return ans*3 - size;

}
int main()
{
   system("pause");
   return 0;
}
